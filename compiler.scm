(load "pattern-matcher.scm")
(load "compiler-utils.scm")
(print-gensym #f)

(define annotate-tc
	(lambda (pe)
		(letrec ((atp
					(lambda (pe is-tp)
						(cond	((tagged-with `const pe) pe)
								((tagged-with `var pe) pe)
								((tagged-with `define pe)
									`(define ,(cadr pe) ,(atp (caddr pe) #f) ))
								((tagged-with `or pe)
									(let* (	(reversed-pe (reverse (cadr pe)))
											(last (car reversed-pe))
											(rest (reverse (cdr reversed-pe))))
										`(or 
										,(append	(map (lambda (exp) (atp exp #f) ) rest )
													(list (atp last is-tp))))))
								((tagged-with `lambda-simple pe)
									(with pe (lambda (name param body) `(,name ,param ,(atp body #t)))))
								((tagged-with `lambda-opt pe)
									(with pe (lambda (name param rest body) `(,name ,param ,rest ,(atp body #t)))))
								((tagged-with `lambda-variadic pe)
									(with pe (lambda (name param body) `(,name ,param ,(atp body #t)))))
								((tagged-with `applic pe)
									(if	is-tp
										(with pe (lambda (name operator params)
												`(tc-applic ,(atp operator #f) ,(map (lambda (exp)
																					(atp exp #f)) params))))
										(with pe (lambda (name operator params)
												`(applic ,(atp operator #f) ,(map (lambda (exp)
																					(atp exp #f)) params))))))
								((tagged-with `seq pe)
									(let* (	(reversed-pe (reverse (cadr pe)))
											(last (car reversed-pe))
											(rest (reverse (cdr reversed-pe))))
										`(seq 
										,(append	(map (lambda (exp) (atp exp #f) ) rest )
													(list (atp last is-tp))))))
								((tagged-with `if3 pe)
									(let* (	(first (cadr pe))
											(rest (cddr pe)))
										`(if3 
										,@(append	(list (atp first #f))
													(map (lambda (exp) (atp exp is-tp) ) rest )))))
								(else pe)))))
		(atp pe #f))))


(define get-var-annotation
	(lambda (var-name envs)
		(let ((minor (find-minor var-name (car envs))))
			(if	minor
				`(pvar ,var-name ,minor)
				(let ((major-minor (find-major-minor var-name (cdr envs))))
					(if	major-minor
						major-minor
						`(fvar ,var-name)))))))


(define find-major-minor
	(lambda (var-name envs)
		(letrec ((f (lambda (var-name envs counter)
						(if (null? envs)
							#f
							(let ((minor (find-minor var-name (car envs))))
								(if	minor
									`(bvar ,var-name ,counter ,minor)
									(f var-name (cdr envs) (+ 1 counter) )))))))
		(f var-name envs 0))))

(define find-minor
	(lambda (var-name env)
		(letrec ((f (lambda (var-name env counter)
					(cond	((null? env) #f)
							((eq? var-name (car env)) counter)
							(else (f var-name (cdr env) (+ 1 counter)))))))
		(f var-name env 0))))

(define (^const? x)
	(or 	(boolean? x)
			(char? x)
			(number? x)
			(string? x)
			))

(define (var? x)
(and (symbol? x)(let ((p (member x *reserved-words*)))
	(if p #f #t))))

(define *reserved-words*
  '(and begin cond define do else if lambda
    let let* letrec or quasiquote unquote 
    unquote-splicing quote set!))

(define *void-object* (void))


(define (reg-lambda-args-list? list)
	(if (not (list? list))
	    #f
	    (andmap var? list)))


;splits the improper list to a pair of proper list and single argument: (opt-lambda-args-list '(a b c . d)) returns '((a b c) . d)
(define (opt-lambda-args-list args-list succ)
	(if (not (pair? args-list))
	    (succ (cons '() args-list))
	    (opt-lambda-args-list (cdr args-list) (lambda (partial-args-list) 
	    (succ (cons (cons (car args-list) (car partial-args-list)) (cdr partial-args-list)))))))


(define (let-vars-expressions-list? list)
	(andmap (lambda (x)vector for each sheme
				(and (list? x) (var? (car x))))
			list))

(define (get-lambda-variables vars)
	(if (=(length vars)0)
		'()
		(cons (caar vars) (get-lambda-variables (cdr vars)))))


(define (get-lambda-arguments exp)
	(if (=(length exp)0)
		'()
		(cons (cadar exp) (get-lambda-arguments (cdr exp)))))

(define expand-qq
  (lambda (e)
    (cond ((unquote? e) (cadr e))
	  ((unquote-splicing? e)
	   (error 'expand-qq "unquote-splicing here makes no sense!"))
	  ((pair? e)
	   (let ((a (car e))
		 (b (cdr e)))
	     (cond ((unquote-splicing? a) `(append ,(cadr a) ,(expand-qq b)))
		   ((unquote-splicing? b) `(cons ,(expand-qq a) ,(cadr b)))
		   (else `(cons ,(expand-qq a) ,(expand-qq b))))))
	  ((vector? e) `(list->vector ,(expand-qq (vector->list e))))
	  ((or (null? e) (symbol? e)) `',e)
	  (else e))))


(define s 'unquote)
(define parse
	(let ((run
		(compose-patterns
		(pattern-rule
			(? 'c ^const?)
			(lambda (c) `(const ,c)))
		(pattern-rule
			`(quote ,(? 'c))
			(lambda (c) `(const ,c)))
		(pattern-rule
			`,(? 'v var?)
			(lambda (v) `(var ,v)))
		(pattern-rule 	;if3
			`(if ,(? 'test) ,(? 'dit))
			(lambda (test dit)
				`(if3 ,(parse test) ,(parse dit) (const ,*void-object*))))
		(pattern-rule 	;if2
			`(if ,(? 'test) ,(? 'dit) ,(? 'dif))
			(lambda (test dit dif)
				`(if3 ,(parse test) ,(parse dit) ,(parse dif))))
		(pattern-rule 	;lambda-variadic
			`(lambda ,(? `var var?) . ,(? `body))	;TODO need to check if the body is legal (also in opt and regular lambdas)
			(lambda (args body)
				`(lambda-variadic ,args ,(parse `(begin ,@body)) )))
		(pattern-rule 	;opt-lambda
			`(lambda ,(? 'opt-arg-list improper-list?) . ,(? 'body))
			(lambda (opt-arg-list body)
				(let* ( 	(args-list (opt-lambda-args-list opt-arg-list (lambda (x) x)))
							(mandatory-args (get-opt-lambda-mandatory-args args-list))
							(optional-arg (get-opt-lambda-optional-args args-list)))
					`(lambda-opt ,mandatory-args ,optional-arg ,(parse `(begin ,@body))))))
		(pattern-rule 	;letrec
			`(letrec ,(? let-vars-expressions-list?) . ,(? 'body))
			(lambda (exp-list body)
				(parse (expand-letrec `(letrec ,exp-list ,@body) ))))
		(pattern-rule 	;reg-lambda
			`(lambda ,(? 'arg-list reg-lambda-args-list?) . ,(? 'body))
			(lambda (arg-list body) `(lambda-simple ,arg-list ,(parse `(begin ,@body)))))
	   (pattern-rule
			`(define ,(? 'var var?) ,(? 'ex) )
			(lambda (vari ex)
				`(define (var ,vari) ,(parse ex))))
	  	(pattern-rule
			`(define (,(? 'name) . ,(? 'varb)) ,(? 'exp))
			(lambda (first rest exp)
				`(define (var ,first) ,(parse `(lambda ,rest ,exp)))))
		(pattern-rule
			`(define (,(? 'name) . ,(? 'varb)) ,(? 'exp))
			(lambda (first rest exp)
				`(define (var ,first) ,(parse `(lambda ,rest ,exp)))))
		(pattern-rule
			`(begin)
			(lambda()
				`(const ,*void-object*)))
		(pattern-rule
			`(begin ,(? `rest))
			(lambda(rest)
				(parse rest)))
		(pattern-rule
			`(begin . ,(? `rest))
			(lambda(rest)
				`(seq ,(map (lambda(exp)(parse exp))  rest))))
		(pattern-rule
			`(,(? 'a quasiquote?) . ,(? `rest))
			(lambda(first rest)
				(parse (expand-qq (car rest)))))
		(pattern-rule
			`(let ,(? 'va ) . ,(? 'body))
			(lambda(vars body)
				(parse `((lambda ,(get-lambda-variables vars) ,@body) ,@(get-lambda-arguments vars)))))
		(pattern-rule 	;let*
			`(let* ,(? let-vars-expressions-list?) ,(? 'body1) . ,(? 'body-rest))
			(lambda (exp-list body1 body-rest)
				(parse (expand-letstar exp-list body1 body-rest ))))
		(pattern-rule 	;and
			`(and)
			(lambda ()
			`(const #t)))
		(pattern-rule
			`(and ,(? 'first))
			(lambda (first)
				(parse first)))
		(pattern-rule 	;and
			`(and ,(? 'first) ,(? 'second))
			(lambda (first second)
				(parse `(if ,first ,second #f))))
		(pattern-rule 	;and
			`(and ,(? 'first) . ,(? 'rest))
			(lambda (first rest)
				(parse `(if ,first (and ,@rest) #f))))
		(pattern-rule 
			`(or)
			(lambda () (parse #f)))
		(pattern-rule 
			`(or ,(? 'e1))
			(lambda (e1) (parse e1) ))
		(pattern-rule 
			`(or . ,(? 'exps))
			(lambda (exps)
				(let ((parsed-exps (map parse exps)))
					`(or ,parsed-exps))))
		(pattern-rule
			`(,(? 'va  var?) . ,(? 'varb list?))
			(lambda (vari variables)
				`(applic (var ,vari) ,(map (lambda (s)(parse s)) variables ))))
		(pattern-rule
			`(,(? 'va list?) . ,(? 'va2 list?))
			(lambda (first rest)
				`(applic ,(parse first) ,(map (lambda (exp)(parse exp)) rest))))
		(pattern-rule
			`(let ,(? 'va ) ,(? 'body))
			(lambda (vars body)
				(parse  `((lambda ,(get-lambda-variables vars) ,body) ,@(get-lambda-arguments vars)))))
		(pattern-rule
			`(cond . ,(? 'cond-list)) ; TODO add identifier for cond list
			(lambda (cond-list) (parse (expand-cond cond-list))))
	)))
	(lambda (e)
		(run e
			(lambda ()
				(error 'parse
				(format "I can't recognize this: ~s" e)))))))

(define expand-letstar (lambda (exp-list body1 body-rest)
	(if (= (length exp-list) 0)
	    (apply beginify `(,body1 ,@body-rest))
	    (let*( 	(seperated-exp-list (seperate-last-element exp-list))
				(last (cdr seperated-exp-list))
				(rest (car seperated-exp-list)))
		(expand-letstar rest `((lambda (,(car last)) ,(apply beginify `(,body1 ,@body-rest)) ) ,(cadr last)) `())
	))))





(define (expand-cond cond-list)
	(letrec ((f (lambda (cond-list succ)
					(cond 	((null? cond-list) (succ cond-list))
							((and (eqv? `else (caar cond-list)) (null? (cdr cond-list)) ) (succ `(begin ,@(cdar cond-list)))) ; TODO handle else
							((and (eqv? `else (caar cond-list)) (not (null? (cdr cond-list))) ) (error `expand-cond (format "else clause must be the last in a cond expression."))) ; TODO ERROR
							(else 	(f 	(cdr cond-list)
										(lambda (rest)
											(if 	(null? rest)
													(succ `(if ,(caar cond-list) (begin ,@(cdar cond-list)) ))
													(succ `(if ,(caar cond-list) (begin ,@(cdar cond-list)) ,rest))))))))))
		(f cond-list (lambda (x) x))))

(define Ym
  (lambda fs
    (let ((ms (map
		(lambda (fi)
		  (lambda ms
		    (apply fi (map (lambda (mi)
				     (lambda args
				       (apply (apply mi ms) args))) ms))))
		fs)))
      (apply (car ms) ms))))

(define expand-letrec
  (lambda (letrec-expr)
    (with letrec-expr
      (lambda (_letrec ribs . exprs)
	(let* ((fs (map car ribs))
	       (lambda-exprs (map cdr ribs))
	       (nu (gensym))
	       (nu+fs `(,nu ,@fs))
	       (body-f `(lambda ,nu+fs ,@exprs))
	       (hofs
		(map (lambda (lambda-expr) `(lambda ,nu+fs ,@lambda-expr))
		  lambda-exprs)))
	  `(Ym ,body-f ,@hofs))))))

(define with (lambda (s f)
					(apply f s)))


	(define (pe->lex-pe pe)
		(treverse pe '(())))

	(define (treverse pe bound-list)
		(cond 
			((null? pe) pe)
			((or (^const? pe)(symbol? pe))pe)
			((and (pair? pe)(eq? (car pe) 'lambda-simple))
				(cons 
					(treverse (car pe) (add-list (cadr pe) bound-list))
					(treverse (cdr pe) (add-list (cadr pe) bound-list))
					))
			((and (pair? pe)(eq? (car pe) 'lambda-opt))(cons 
				(treverse (car pe) (add-list (append (cadr pe) (cddr pe)) bound-list))
				(treverse (cdr pe) (add-list (append (cadr pe) (cddr pe)) bound-list))
				))
			((and (pair? pe)(eq? (car pe) 'lambda-variadic))(cons 
				(treverse (car pe) (add-list (cdr pe) bound-list))
				(treverse (cdr pe) (add-list (cdr pe) bound-list))
				))
			
			((and (pair? pe)(eq? (car pe) 'var)) (get-var-annotation (cadr pe) bound-list))
			(else (cons (treverse (car pe) bound-list)(treverse (cdr pe) bound-list)))))
(define test
  (lambda (e)
    (annotate-tc
      (pe->lex-pe
	(parse e)))))


;**********************************;;;;;;;;;;;;;;;;;;;;;;;;

(define ^^label
	(lambda (name)
		(let ((n 0))
			(lambda ()
				(set! n (+ n 1))
			(string-append name (number->string n))))))


(define ^label-if3else (^^label "Lif3else"))

(define ^label-if3exit (^^label "Lif3exit"))

(define code-gen-if3 (lambda (e)
		(with e	(lambda (if3 test do-if-true do-if-false)
					(let ((code-test (code-gen test))
						(code-dit (code-gen do-if-true))
						(code-dif (code-gen do-if-false))
						(label-else (^label-if3else))
						(label-exit (^label-if3exit)))
					(string-append
						code-test nl ; when run, the result of the test will be in R0
						"CMP(R0, SOB_BOOLEAN_FALSE);" nl
						"JUMP_EQ(" label-else ");" nl
						code-dit nl
						"JUMP(" label-exit ");" nl
						label-else ":" nl
						code-dif nl
						label-exit ":"))))))

(define (make-string-of-chars list-of-chars number-of-elments type)
				(if (null? list-of-chars)
					(string-append "PUSH(IMM(" number-of-elments "));// LENGHT OF STRING" nl
					"CALL(" type ");" nl "DROP(" number-of-elments ");" nl "DROP(1);" nl )
				(string-append "PUSH(IMM(" (car list-of-chars) "));" nl (make-string-of-chars (cdr list-of-chars) number-of-elments) type)))

(define (string->chars e type)
	(let* ((exp (string->list e))
			(new-list (map (lambda(el)(number->string (char->integer el))) exp))
			(number-of-elments (number->string (length new-list))))
			(make-string-of-chars new-list number-of-elments type) 
			))


(define (string->chars e)
	(let* ((exp (string->list e))
			(new-list (map (lambda(el)(number->string (char->integer el))) exp))
			(number-of-elments (number->string (length new-list))))
			(make-string-of-chars new-list number-of-elments) 
			))


(define (code-gen-const e)
	(with e (lambda(const exp)
	(cond ((number? exp)(if (integer? exp)
							(string-append "MAKE_INTEGER("(number->string exp)");" nl )
							(string-append (string->chars (number->string exp)) )))
		  ((string? exp)(string->chars exp "MAKE_SOB_NUMBER"))
		  ((char? exp)(string-append "MAKE_CHAR(" (number->string (char->integer exp) "MAKE_SOB_STRING")  ");" nl))
		  ((boolean? exp)(if (equal? #f exp)
						(string-append "MAKE_BOOL(SOB_BOOLEAN_FALSE);" nl)
		  				(string-append "MAKE_BOOL(SOB_BOOLEAN_TRUE);" nl)))
		  ((symbol? exp)(string-append "MAKE_SYMBOL(" (symbol->string exp )");"  nl))

		  (else exp))	
	)))

	


(define (code-gen-pvar e)
	(with e (lambda(pvar var index)
	(string-append "MOV_PVAR(" (number->string index) ");" nl)
	)))

(define (code-gen-bvar e)
	(with e (lambda(name var i j)
	(string-append "MOV_BVAR(" (number->string i) "," (number->string j) ");" nl)
	)))

(define gen-code-params (lambda (params) 
					(if (null? params)
						(string-append "//end of params" nl )	
						(string-append (code-gen (car params))  "PUSH(R0); " nl  ( gen-code-params  (cdr params))))))

(define (code-gen-applic e)
	(with e (lambda (name operator params)
	(let* ((params-code (gen-code-params params))
			(proc-code (code-gen operator)))
			(string-append params-code	
				"PUSH(IMM("(number->string (length params))"));" nl
				"//**************proc code**********" nl	proc-code "//**************proc code**********" nl
				"CMP(IND(R0),T_CLOSURE);"	nl
				"JUMP_NE(lnot_proc);" nl
				"MOV(R1,INDD(R0 , IMM(1))); //push env" nl
				"PUSH(R1);" nl 
				"CALLA((INDD(R0 , IMM(2)))); // jump to code label" nl
				"MOV(R1,STARG(0));" nl
				"ADD(R1,2);" nl
				"DROP(IMM(R1)); //remove all" nl
			)))))

(define (code-gen-fvar e)
	(with e 
		(lambda(name op)
			(cond
				((equal? op 'cons)(string-append "MAKE_CLOSURE(CONS);" nl))
				((equal? op 'car)(string-append "MAKE_CLOSURE(CAR);" nl))
				((equal? op 'cdr)(string-append "MAKE_CLOSURE(CDR);" nl))
				((equal? op 'boolean?)(string-append "MAKE_CLOSURE(IS_BOOL);" nl))	
				((equal? op 'integer?)(string-append "MAKE_CLOSURE(IS_INTEGER);" nl))
				((equal? op 'string?)(string-append "MAKE_CLOSURE(IS_STRING);" nl))
				((equal? op 'char?)(string-append "MAKE_CLOSURE(IS_CHAR);" nl))
				((equal? op 'vector?)(string-append "MAKE_CLOSURE(IS_VECTOR);" nl))
				((equal? op 'symbol?)(string-append "MAKE_CLOSURE(IS_SYMBOL);" nl))	
				((equal? op 'pair?)(string-append "MAKE_CLOSURE(IS_PAIR);" nl))	
				((equal? op 'make-string)(string-append "MAKE_CLOSURE(MAKE_STRING);" nl))
				((equal? op 'char->integer)(string-append "MAKE_CLOSURE(CHAR_TO_INTEGER);" nl))
				((equal? op 'make-vector)(string-append "MAKE_CLOSURE(MAKE_VECTOR);" nl))
				((equal? op 'vector-length)(string-append "MAKE_CLOSURE(VECTOR_LENGTH);" nl))
				((equal? op 'vector-ref)(string-append "MAKE_CLOSURE(VECTOR_REF);" nl))
				((equal? op 'vector-set!)(string-append "MAKE_CLOSURE(VECTOR_SET);" nl))
			(else op))
		)
	)
)
(define (code-gen e)
	(cond ((tagged-with 'const e)(code-gen-const e))
	 	((tagged-with 'if3 e)(code-gen-if3 e))
	 	((tagged-with 'pvar e)(code-gen-pvar e))
	 	((tagged-with 'bvar e)(code-gen-bvar e))
	 	;((tagged-with 'lambda-simple e)	(with e (lambda (name param body)(code-gen body))))
	 	((tagged-with 'applic e)(code-gen-applic e))
	 	((tagged-with 'tc-applic e)(code-gen-applic e))
		((tagged-with 'fvar e)(code-gen-fvar e))
		((tagged-with 'lambda-simple e)(code-gen-lambda e))
										
	(else e)))


(define call-with-input-file
  (lambda (filename proc)
    (let ((p (open-input-file filename)))
      (let ((v (proc p)))
        (close-input-port p)
				(list->string v)))))

;(define call-with-output-file
;  (lambda (port proc list-to-print)
;      (proc port list-to-print)))


;(define write-whole-file
;  (lambda (p l)
;  	(let* ((element (if (null? l)l(car l))))
;  		(if null? element)
;  			(newline p)
;   		 (begin 
;   		 	(if	(equal? element #\newline)
;   				(newline p)
;   				(display element p))
;   			(write-whole-file (p (cdr l)))))))


;used for reading c macros
(define nl (list->string (list #\newline)))

(define read-whole-file-by-char
  (lambda (p)
   (letrec (
   	(f (lambda (x)
   		(if (eof-object? x)
   			'()
   		(cons x (f (read-char p)))))))
	(f (read-char p)))))

;used for reading scheme input
(define read-whole-file-by-token
  (lambda (p)
   (letrec (
   	(f (lambda (x)
   		(if (eof-object? x)
   			'()
   		(cons x (f (read p)))))))
	(f (read p)))))


(define (create-imports-macros-begining)
(call-with-input-file "pre_code.c" read-whole-file-by-char)) 


(define (create-imports-macros-end)
(call-with-input-file "post_code.c" read-whole-file-by-char)) 

(define (code-gen-text input-text output-file)
;(display (string-append  "MOV(R0,IMM(2));" nl "SHOW(\"READ IN STRING AT ADDRESS \", R0);" nl) output-file))
(display (code-gen input-text) output-file))


(define (compile-scheme-file input output)
	(let* (
			(output-file (open-output-file output 'replace))
			(input-file  (open-input-file input))
			(input-text (test (car (read-whole-file-by-token input-file))))
			
		)
		(begin 
			(display (create-imports-macros-begining)  output-file)
			(code-gen-text  input-text output-file )
			(display  (create-imports-macros-end)  output-file)
			(close-output-port output-file)
		)))

(define ^label-lambda-copy-old-env (^^label "L_lambda_copy_old_env"))
(define ^label-lambda-make-new-env (^^label "L_lambda_make_new_env"))
(define ^label-lambda-code (^^label "L_lambda_code"))
(define ^label-lambda-exit (^^label "L_lambda_exit"))
(define ^label-lambda-exit-loop (^^label "L_lambda_exit_loop"))
;
(define code-gen-lambda
	(lambda (e)
		(let* (	(vars (cadr e))
				(body (caddr e))
				(numOfVars (number->string (length vars) ))
				(label-copy-old-env (^label-lambda-copy-old-env))
				(label-make-new-env (^label-lambda-make-new-env))
				(label-code (^label-lambda-code))
				(label-exit (^label-lambda-exit))
				(label-exit-loop-old-env (^label-lambda-exit-loop))
				(label-exit-loop-new-env (^label-lambda-exit-loop)))
		(string-append
			"// Starting code-gen for lambda" nl
			(code-for-env-size "R3") nl
			"PUSH(R3); // store env size" nl
			"CALL(MALLOC); // allocate mem for new env" nl
			"DROP(IMM(1));" nl
			"MOV(R1,R0); // pointer to the new env;" nl
			"MOV(R2,FPARG(0)); // pointer to the old env" nl
			"MOV(R4,IMM(0)); // R4 is i" nl
			"MOV(R5,IMM(1)); // R5 is j" nl
			"// iterating to copy the old env" nl
			"// in to the new one" nl
			label-copy-old-env ":" nl
			"CMP(R4,R3);" nl
			"JUMP_EQ(" label-exit-loop-old-env ");" nl
			"MOV( INDD(R1,R5), INDD(R2,R4))" nl
			"INCR(R4); //++i" nl
			"INCR(R5); //++j" nl
			"JUMP(" label-copy-old-env "); // another iteration" nl
			label-exit-loop-old-env ": //end of for loop" nl
			nl
			"// Add the current params to the env" nl
			"PUSH(IMM(SCMNARGS)); // number of variables" nl
			"CALL(MALLOC);" nl
			"DROP(IMM(1));" nl
			"MOV(R3,R0);" nl
			"MOV(R4, IMM(0)); // i=0" nl
			label-make-new-env ": // 'for' loop" nl
			"CMP(R4,IMM(SCMNARGS));" nl
			"JUMP_EQ(" label-exit-loop-new-env ");" nl
			"MOV(R6,R4);" nl
			"ADD(R6,IMM(2));" nl
			"MOV(R5, R6);" nl
			"MOV(INDD(R3, R4), FPARG(R5));" nl
			"INCR(R4);" nl
			"JUMP(" label-make-new-env "); // another iteration" nl
			label-exit-loop-new-env ": // end of for loop" nl
			"MOV(IND(R1), R3); // move pointer to the pvars to the new env" nl
			"PUSH(IMM(3));" nl
			"CALL(MALLOC); // memory for the closure data struct" nl
			"DROP(IMM(1));" nl
			"MOV(INDD(R0, 0), T_CLOSURE);" nl
			"MOV(INDD(R0, 1), R1); // pointer to the new env" nl
			"MOV(INDD(R0, 2), LABEL(" label-code ")); // pointer to the code" nl
			"JUMP(" label-exit ");"
			label-code ": // the begining of the actual code of the lambda" nl
			"PUSH(FP);" nl
			"MOV(FP, SP);" nl
			"// TODO need to check arguments here" nl; TODO check arguments etc
			nl
			"// Here starts the code of the actual lambda" nl
			nl
			(code-gen body)
			nl
			"// Here ends the code of the actual lambda" nl
			nl
			"POP(FP);" nl
			"RETURN;" nl
			label-exit ":" nl

		))))

; This function creates code for storing the ENV's size
; to the desired register
; TODO
(define code-for-env-size
	(lambda (target-rgstr)
		"// TODO code-for-env-size"
	))
