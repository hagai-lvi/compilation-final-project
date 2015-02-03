(load "pattern-matcher.scm")
(load "compiler-utils.scm")
(load "parser_expansions.scm")
(load "parser.scm")
(print-gensym #f)



;**********************************;;;;;;;;;;;;;;;;;;;;;;;;

(define ^^label
	(lambda (name)
		(let ((n 0))
			(lambda ()
				(set! n (+ n 1))
			(string-append name (number->string n))))))

(define ^argument-counter (^^label "agrument_number"))

(define ^label-if3else (^^label "Lif3else"))

(define ^label-if3exit (^^label "Lif3exit"))

(define code-gen-if3 (lambda (e const-table env-depth fvar-table)
		(with e	(lambda (if3 test do-if-true do-if-false)
					(let ((code-test (code-gen test const-table env-depth fvar-table))
						(code-dit (code-gen do-if-true const-table env-depth fvar-table))
						(code-dif (code-gen do-if-false const-table env-depth fvar-table))
						(label-else (^label-if3else ))
						(label-exit (^label-if3exit)))
					(string-append
						code-test nl ; when run, the result of the test will be in R0
						"CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);" nl
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
					(string-append "PUSH(IMM(" (car list-of-chars) "));" nl 
				(make-string-of-chars (cdr list-of-chars) number-of-elments type))))

(define (string->chars e type)
	(let* ((exp (string->list e))
			(new-list (map (lambda(el)(number->string (char->integer el))) exp))
			(number-of-elments (number->string (length new-list))))
			(make-string-of-chars new-list number-of-elments type) 
			))



(define (code-gen-const e const-table env-depth fvar-table)
	(with e (lambda (const exp)
		(string-append "MOV(R0,("(number->string (memory-getter exp const-table))"));" nl )
	;(cond ((number? exp)(if (integer? exp)
	;						(string-append "MOV(R0,("(number->string (memory-getter exp const-table))"));" nl )
	;						(string-append (string->chars (number->string exp) "MAKE_SOB_NUMBER") )))
	;	  ((string? exp)	(string-append "MOV(R0,("(number->string (memory-getter exp const-table))"));" nl ))
	;	  ((char? exp)(string-append "MOV(R0,("(number->string (memory-getter exp const-table))"));" nl ))
	;	  ((boolean? exp)(string-append "MOV(R0,("(number->string (memory-getter exp const-table))"));" nl ))
	;	  ((null? exp)(string-append "MOV(R0,("(number->string (memory-getter exp const-table))"));" nl ))
	;	  ((symbol? exp)(string-append "MAKE_SYMBOL(" (symbol->string exp )");"  nl))
	;	  ((list? exp)(string-append "MOV(R0,("(number->string (memory-getter exp const-table))"));" nl ))
	;	  ((void? exp)(string-append "MOV(R0,("(number->string (memory-getter exp const-table))"));" nl ))
	;	  ((vector? exp)
	;	  (else exp))	
	)))

	
(define applic-counter (^^label "application_number"))

(define (code-gen-pvar e const-table env-depth fvar-table)
	(with e (lambda(pvar var index)
	(string-append "MOV_PVAR(" (number->string index) ");" nl)
	)))

(define (code-gen-bvar e const-table env-depth fvar-table)
	(with e (lambda(name var i j)
	(string-append "MOV_BVAR(" (number->string i) "," (number->string j) ");" nl)
	)))

(define gen-code-params (lambda (params const-table env-depth fvar-table)
					(letrec ((args (^^label "agrument_number"))
							(applic (applic-counter))
					(f (lambda(params const-table env-depth fvar-table)
					(let ((argument (args)))
					(if (null? params)
						(string-append "//end of params" nl )	
						(string-append "//************************************start of " argument "***" applic "***************************************"  nl
						 (code-gen (car params) const-table env-depth fvar-table)  "PUSH(R0); " nl
						 		(string-append "//************************************end of " argument "* "applic "*****************************************"  nl
				
						   ( f  (cdr params) const-table env-depth fvar-table))))))))
					(f params const-table env-depth fvar-table))))
(define (code-gen-applic e const-table env-depth fvar-table)
	(with e (lambda(name operator params)
	(let* ((params-code (gen-code-params (reverse params) const-table env-depth fvar-table))
			(proc-code (code-gen operator const-table env-depth fvar-table)))
			(string-append 
						
				params-code	
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

(define code-gen-fvar (lambda (e const-table env-depth fvar-table)
	(with e 
		(lambda(name op)
			(string-append "MOV(R0,IND(" (number->string (memory-getter op fvar-table)) "));" nl)))))
			; (cond
			; 	((equal? op 'cons)(string-append "MAKE_CLOSURE(CONS);" nl))
			; 	((equal? op 'car)(string-append "MAKE_CLOSURE(CAR);" nl))
			; 	((equal? op 'cdr)(string-append "MAKE_CLOSURE(CDR);" nl))
			; 	((equal? op 'eq?)(string-append "MAKE_CLOSURE(EQ);" nl))
			; 	((equal? op 'null?)(string-append "MAKE_CLOSURE(IS_NULL);" nl))	
			; 	((equal? op 'boolean?)(string-append "MAKE_CLOSURE(IS_BOOL);" nl))	
			; 	((equal? op 'integer?)(string-append "MAKE_CLOSURE(IS_INTEGER);" nl))
			; 	((equal? op 'number?)(string-append "MAKE_CLOSURE(IS_NUMBER);" nl))
			; 	((equal? op 'string?)(string-append "MAKE_CLOSURE(IS_STRING);" nl))
			; 	((equal? op 'char?)(string-append "MAKE_CLOSURE(IS_CHAR);" nl))
			; 	((equal? op 'vector?)(string-append "MAKE_CLOSURE(IS_VECTOR);" nl))
			; 	((equal? op 'symbol?)(string-append "MAKE_CLOSURE(IS_SYMBOL);" nl))	
			; 	((equal? op 'zero?)(string-append "MAKE_CLOSURE(ZERO);" nl))	
			; 	((equal? op 'pair?)(string-append "MAKE_CLOSURE(IS_PAIR);" nl))	
			; 	((equal? op 'procedure?)(string-append "MAKE_CLOSURE(IS_PROC);" nl))	
			; 	((equal? op 'make-string)(string-append "MAKE_CLOSURE(MAKE_STRING);" nl))
			; 	((equal? op 'char->integer)(string-append "MAKE_CLOSURE(CHAR_TO_INTEGER);" nl))
			; 	((equal? op 'integer->char)(string-append "MAKE_CLOSURE(INTEGER_TO_CHAR);" nl))
			; 	((equal? op 'make-vector)(string-append "MAKE_CLOSURE(MAKE_VECTOR);" nl))
			; 	((equal? op 'vector-length)(string-append "MAKE_CLOSURE(VECTOR_LENGTH);" nl))
			; 	((equal? op 'vector-ref)(string-append "MAKE_CLOSURE(VECTOR_REF);" nl))
			; 	((equal? op 'vector-set!)(string-append "MAKE_CLOSURE(VECTOR_SET);" nl))
			; 	((equal? op 'string-length)(string-append "MAKE_CLOSURE(STRING_LENGTH);" nl))
			; 	((equal? op 'string-set!)(string-append "MAKE_CLOSURE(STRING_SET);" nl))
			; 	((equal? op 'string-ref)(string-append "MAKE_CLOSURE(STRING_REF);" nl))					
			; 	((equal? op 'set-car!)(string-append "MAKE_CLOSURE(SET_CAR);" nl))
			; 	((equal? op 'set-cdr!)(string-append "MAKE_CLOSURE(SET_CDR);" nl))
			; 	((equal? op '+ )(string-append "MAKE_CLOSURE(PLUS);" nl))
			; 	((equal? op '- )(string-append "MAKE_CLOSURE(MINUS);" nl))
			; 	((equal? op '* )(string-append "MAKE_CLOSURE(MULTIPLY);" nl))
			; 	((equal? op '/ )(string-append "MAKE_CLOSURE(DIV);" nl))
			; 	((equal? op '> )(string-append "MAKE_CLOSURE(BIGGER_THAN);" nl))
			; 	((equal? op '< )(string-append "MAKE_CLOSURE(LESS_THAN);" nl))
			; 	((equal? op '= )(string-append "MAKE_CLOSURE(NUMBER_EQUALS);" nl))
			;(else (error 'code-gen-fvar "Can't generate code for ~s" `(,name ,op))))))))


(define code-gen-seq (lambda (e const-table env-depth fvar-table)
	(with e (lambda (name applications)
	(apply string-append (map (lambda(exp)(code-gen exp const-table env-depth fvar-table)) applications)
	)))))

(define code-gen (lambda(e const-table env-depth fvar-table)
	(cond ((tagged-with 'const e)(code-gen-const e const-table env-depth fvar-table))
	 	((tagged-with 'if3 e)(code-gen-if3 e const-table env-depth fvar-table))
	 	((tagged-with 'pvar e)(code-gen-pvar e const-table env-depth fvar-table))
	 	((tagged-with 'bvar e)(code-gen-bvar e const-table env-depth fvar-table))
	 	((tagged-with 'applic e)(code-gen-applic e const-table env-depth fvar-table))
	 	((tagged-with 'tc-applic e)(code-gen-tp-applic e const-table env-depth fvar-table))
		((tagged-with 'fvar e)(code-gen-fvar e const-table env-depth fvar-table))
		((tagged-with 'lambda-simple e)(code-gen-lambda e const-table env-depth fvar-table))
		((tagged-with 'lambda-opt e)(code-gen-lambda-opt e const-table env-depth fvar-table))
		((tagged-with 'seq e)(code-gen-seq e const-table env-depth fvar-table))
		((tagged-with 'or e)(code-gen-or e const-table env-depth fvar-table))
		((tagged-with 'define e)(code-gen-define e const-table env-depth fvar-table))
		
										
	(else e))))

(define ^label-or-exit (^^label "L_OR_EXIT"))
(define code-gen-or
	(lambda (e const-table env-depth fvar-table)
		(with	e
				(lambda (or args)
					(let* (	(code-gen-args (map (lambda (e) (code-gen e const-table env-depth fvar-table)) args))
							(abl (all-but-last code-gen-args))
							(code-for-last (last-element code-gen-args))
							(label-or-exit (^label-or-exit))
							(code-for-all-but-last (map
														(lambda(e)
															(string-append
																e nl
																"CMP(R0, SOB_FALSE);" nl
																"JUMP_NE(" label-or-exit ");" nl)) 
														abl)))
						(string-append
							"// Starting code-gen for OR" nl
							(apply string-append code-for-all-but-last)
							code-for-last
							label-or-exit ":" nl

							)


					)))))


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







(define (create-imports-macros-begining)
(call-with-input-file "resources/pre_code.c" read-whole-file-by-char)) 


(define (create-imports-macros-end)
(call-with-input-file "resources/post_code.c" read-whole-file-by-char)) 

(define code-gen-text (lambda(input-text const-table fvar-table)
;(display (string-append  "MOV(R0,IMM(2));" nl "SHOW(\"READ IN STRING AT ADDRESS \", R0);" nl) output-file))
	(if (null? input-text)
		(string-append "")
		(string-append
			(code-gen (test (car input-text)) const-table 0 fvar-table)
			"PUSH(R0);" nl
			"CALL(WRITE_SOB);" nl
			"CALL(NEWLINE);" nl 
			"//END OF FIRST INPUT********************************************" nl
			(code-gen-text (cdr input-text) const-table fvar-table)))))


(define get-constant-table (lambda(input-text)
;(display (string-append  "MOV(R0,IMM(2));" nl "SHOW(\"READ IN STRING AT ADDRESS \", R0);" nl) output-file))
	(if (null? input-text)
		'()
		(cons 	(topo-sort (car input-text))
				(get-constant-table (cdr input-text))))))


(define get-fvar-table (lambda(input-text)
;(display (string-append  "MOV(R0,IMM(2));" nl "SHOW(\"READ IN STRING AT ADDRESS \", R0);" nl) output-file))
	(if (null? input-text)
		'()
		(cons 	(fvar-list-getter (test (car input-text)))
				(get-fvar-table (cdr input-text))))))

(define copy-const-table-to-memory (lambda (table index) 
(if (null? table)
	(string-append "//END OF memory allocation " nl) 
  (let* 
  	((exp (car table))
	(e (if (number? exp)
		(number->string exp)
		(symbol->string exp))))
	(string-append  "MOV(IND(" (number->string index) ") , IMM(" e "));" nl
(copy-const-table-to-memory (cdr table) (+ index 1)))
	))))


(define (flatten x)
    (cond ((null? x) '())
          ((not (pair? x)) (list x))
          (else (append (car x)
                        (flatten (cdr x))))))

(define (compile-scheme-file input output)
	(let* (
			(output-file (open-output-file output 'replace))
			(input-file  (open-input-file input))
			(input-text  (read-whole-file-by-token input-file))
			(const-table  (make-const-table (reverse (remove-duplicates (reverse (flatten (get-constant-table input-text)))))))
			(fvar-start-pos (+  (caar (reverse const-table )) (length (caddar (reverse const-table) ))))
			(fvar-init-table  (make-initial-fvars-table fvar-start-pos))
			(fvar-table (make-fvars-table (flatten (get-fvar-table input-text)) fvar-start-pos))
		)
		(begin 
			(display (create-imports-macros-begining)  output-file)
			(display (copy-const-table-to-memory (flatten (map append (map caddr const-table)))  1)  output-file)
			(display (copy-fvar-table-to-memory (map cadr fvars-map) fvar-start-pos) output-file)
			(display (code-gen-text  input-text const-table fvar-table) output-file)
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
	(lambda (e const-table env-depth fvar-table)
		(let* (	(vars (cadr e))
				(body (caddr e))
				(label-copy-old-env (^label-lambda-copy-old-env))
				(label-make-new-env (^label-lambda-make-new-env))
				(label-code (^label-lambda-code))
				(label-exit (^label-lambda-exit))
				(label-exit-loop-old-env (^label-lambda-exit-loop))
				(label-exit-loop-new-env (^label-lambda-exit-loop))
				(lambda-uid (string-append "lambda-" (getUID))))
		(string-append
			"// Starting code-gen for " lambda-uid nl
			"PUSHAD;" nl
			"MOV(R3, IMM(" (number->string env-depth) ")); // env depth" nl
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
			"JUMP(" label-exit ");" nl

		
			label-code ": // the begining of the actual code of the lambda" nl
			"PUSH(FP);" nl
			"MOV(FP, SP);" nl
			"// TODO need to check arguments here" nl; TODO check arguments etc
			nl
			"// Here starts the code of the actual lambda " lambda-uid nl
			nl
			(code-gen body const-table (+ 1 env-depth) fvar-table)
			nl
			"// Here ends the code of the actual lambda " lambda-uid nl
			nl
			"POP(FP);" nl
			"RETURN;" nl
			label-exit ":" nl
			"POPAD;" nl

		))))

(define code-gen-lambda-opt
	(lambda (e const-table env-depth fvar-table)
		(let* (	(vars (cadr e))
				(body (cadddr e))
				(label-copy-old-env (^label-lambda-copy-old-env))
				(label-make-new-env (^label-lambda-make-new-env))
				(label-code (^label-lambda-code))
				(label-exit (^label-lambda-exit))
				(label-exit-loop-old-env (^label-lambda-exit-loop))
				(label-exit-loop-new-env (^label-lambda-exit-loop))
				(label-loop-1 (string-append "lambda_opt_loop1" (getUID)))
				(label-loop-2 (string-append "lambda_opt_loop2" (getUID)))
				(label-exit-loop-2 (string-append "lambda_opt_exit_loop2" (getUID)))
				(label-exit-loop-1 (string-append "lambda_opt_exit_loop1" (getUID)))
				(lambda-uid (string-append "lambda-" (getUID))))
		(string-append
			"// Starting code-gen for " lambda-uid nl
			"MOV(R3, IMM(" (number->string env-depth) ")); // env depth" nl
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
			"JUMP(" label-exit ");" nl
			label-code ": // the begining of the actual code of the lambda" nl
			"PUSH(FP);" nl
			"MOV(FP, SP);" nl
			"PUSH(R1);" nl
			"PUSH(R2);" nl
			"PUSH(R3);" nl
			"PUSH(R4);" nl
			"PUSH(R5);" nl
			
			"MOV( R3, SCMNARGS); // total num of args" nl
			"MOV( R2, IMM(" (number->string (length vars)) "));" nl

			"MOV(R4,R3);" nl
			"SUB(R4,R2); // num of opt args in R4" nl
			label-loop-1 ":" nl
			"CMP(R3,R2);" nl
			"JUMP_EQ(" label-exit-loop-1 ");" nl
			"PUSH(SCMARG(R3-1));" nl
			"DECR(R3);" nl
			"JUMP(" label-loop-1 ");" nl
			nl
			label-exit-loop-1 ":" nl
			"PUSH(R4);" nl
			"CALL(MAKE_LIST);" nl
			"DROP(IMM(1)); //drop num of args" nl
			"DROP(IMM(R4)); //drop args " nl
			"MOV(R5,FP);" nl
			"SUB(R5, R2);" nl
			"SUB(R5, IMM(5));" nl
			"MOV(STACK(R5), R0);" nl
					
			"ADD(R5,IMM(" (number->string (length vars)) "));" nl
			"ADD(R5,IMM(1));"

			"MOV(STACK(R5),IMM(" (number->string (+ (length vars) 1)) "));" nl
				"INFO;"
			"MOV(R0,SP);" nl
			"MOV(R1,IMM(" (number->string (length vars) ) "));" nl
			"SUB(R0,R1);" nl
			"MOV(R2,FP);"

			""
			""
			"// TODO need to check arguments here" nl; TODO check arguments etc
			nl
			"// Here starts the code of the actual lambda " lambda-uid nl
			nl
			(code-gen body const-table (+ 1 env-depth) fvar-table)
			nl
			"// Here ends the code of the actual lambda " lambda-uid nl
			nl
			"POP(R5);" nl
			"POP(R4);" nl
			"POP(R3);" nl
			"POP(R2);" nl
			"POP(R1);" nl
			"POP(FP);" nl
			"RETURN;" nl
			label-exit ":" nl

		))))


(define (code-gen-define e const-table env-depth fvar-table)
	(with e (lambda (def name exp)
		(let* ((value (code-gen exp const-table env-depth fvar-table))
				(mem-loc (memory-getter (cadr name) fvar-table)))
			(string-append value "MOV(IND(" (number->string mem-loc) "), R0);" nl 
				"MOV(R0,IMM(1));" nl)))))


(define ^label-tp-applic-loop (^^label "L_tp_applic_loop"))
(define ^label-tp-applic-exit-loop (^^label "L_tp_applic_exit_loop"))
(define (code-gen-tp-applic e const-table env-depth fvar-table)
	(with e (lambda (name operator params)
	(let* ((params-code (gen-code-params (reverse params) const-table env-depth fvar-table))
			(proc-code (code-gen operator const-table env-depth fvar-table))
			(loop_label (^label-tp-applic-loop))
			(loop_label_exit (^label-tp-applic-exit-loop )))
			(string-append 

				params-code	

				"PUSH(IMM("(number->string (length params))"));" nl
				"//**************proc code**********" nl	proc-code "//**************proc code**********" nl

				"CMP(IND(R0),T_CLOSURE);"	nl
				"JUMP_NE(lnot_proc);" nl
				"MOV(R1,INDD(R0 , IMM(1))); //push env" nl
				"PUSH(R1);" nl 
				"MOV(R1,FPARG(-1));"	
				"PUSH(R1);//push RETURN ADR" nl
				
				"MOV(R3,FP);" nl
				"SUB(R3,FPARG(-2));" nl
				"MOV(R4,IMM(" (number->string (length params)) "));//NUMBER OF CURRENT ARGS" nl
				"ADD(R4,3);//number of total elemtns on stack" nl
				"MOV(R5,R4);//save for later "nl
				"MOV(R1,IMM(0));//counter"nl
				"MOV(R6,FP);"nl
	
				"MOV(R10,FP);" nl
				"SUB(R10,SCMNARGS); //new framepointer"  nl
				"SUB(R10,4);" nl
				"MOV(FP,R10);" nl

				loop_label ":" nl
				"CMP(R1,R4); " nl
				"JUMP_EQ("loop_label_exit ");" nl
				"MOV(R7,FP);" nl
				"ADD(R7,R1);" nl
				"MOV(R8,R6);" nl
				"ADD(R8,R1);" nl
				"MOV(STACK(R7),STACK(R8));" nl
				"INCR(R1);" nl
				"JUMP(" loop_label ");" nl
				loop_label_exit ":" nl
				"MOV(SP,FP);" nl
				"ADD(SP,R5);" nl
				"JUMPA((INDD(R0 , IMM(2)))); // jump to code label" nl
				
			)))))

;get a topological sorted list of constants and creates the constants table that looks like this:
; (	(1 	#<void> (t_void))
;	(2 	()		(t_nil))
;	...
; )
(define make-const-table
	(letrec ((f
	(lambda(exp current-list counter)
		(if (null? exp)
			current-list
			(let (	(e (car exp))
		 			(rest (cdr exp)))
		 			(cond
		 		 		((integer? e)
		 		 			(f rest `(,@current-list (,counter ,e (T_INTEGER ,e))) (+ counter 2)))
		 		 		((char? e)
		 		 			(f rest `(,@current-list (,counter ,e (T_CHAR ,(char->integer e)))) (+ counter 2)))
		 		 		((symbol? e)
		 		 			(f rest `(,@current-list (,counter ,e (T_SYMBOL ,e))) (+ counter 2)))
		 		 		((and (boolean? e) e)
		 		 			(f rest `(,@current-list (,counter ,e (T_BOOL 1))) (+ counter 2)))
		 		 		((and (boolean? e) (not e))
		 		 			(f rest `(,@current-list (,counter ,e (T_BOOL 0))) (+ counter 2)))
		 		 		((string? e)
		 		 			(f rest `(,@current-list (,counter ,e (T_STRING ,(string-length e) ,@(get-ascii-list e)))) (+ counter 2 (string-length e))))
		 		 		((pair? e)
		 		 			(let (	(the-car (get-const-location (car e) current-list))
		 		 					(the-cdr (get-const-location (cdr e) current-list)))
		 		 				(f rest `(,@current-list (,counter ,e (T_PAIR ,the-car ,the-cdr))) (+ counter 3 ))))
		 		 		((vector? e)
		 		 			(let ((locations (map (lambda(expr)(get-const-location expr current-list)) (vector->list  e )))
		 		 					(vec-length (vector-length e)))
		 		 				(f rest `(,@current-list (,counter ,e (T_VECTOR ,vec-length ,@locations))) (+ counter vec-length 2))))
		 		 		(else 'fail))))))) ; TODO exception? error?
	(lambda (exp)
		(f (filter (lambda (x) (not (null? x))) exp) (get-initial-const-tbl) 7))))


(define topo-sort (lambda(exp) 
	(let ((constant-list-before-sort   (remove-duplicates (const-list-getter (test exp))))) 
		  (cond ((null? constant-list-before-sort) '())
		   		(else (apply append (map (lambda(exp)(foo exp)) constant-list-before-sort)))))))
	
	
(define (append-list x)							 

	(if (and (^const? (car x)) (pair? (cdr x))(list? (cadr x)))
	(append (list (car x))(cadr x))
		(if (and (pair? x ) (list? (car x)))
			(car x)
		x)))

(define foo
  (lambda (e)	
    (cond
      ((or (number? e) (char? e)(string? e) (null? e))`(,e))
      ((pair? e)
       `( ,@(foo (car e)) ,@(foo (cdr e) ),e))
       ((vector? e)
        `( ,@(apply append
                      (map foo
                           (vector->list e))) ,e))
       ((symbol? e)
        `(,@(foo (symbol->string e))))
       )))

(define const-list-getter 
	(lambda (exp)
	(cond
		((or (null? exp)(symbol? exp)(tagged-with 'pvar exp)(tagged-with 'bvar exp)(tagged-with 'fvar exp))`(,@(list)))
		((tagged-with 'const exp)(with exp (lambda(name constr) (if (or (null? constr)(boolean? constr)(void? constr)) `(,@(list))  `(,constr)))))
		(else `(,@(const-list-getter  (car exp)) ,@(const-list-getter  (cdr exp)))))))


(define (remove-duplicates l)
  (cond ((null? l)
         '())
        ((member (car l) (cdr l))
         (remove-duplicates (cdr l)))
        (else
         (cons (car l) (remove-duplicates (cdr l))))))


(define memory-getter (lambda(value dic)(get-expression-of-variable (map car dic)(map cadr dic) value)))


(define get-expression-of-variable
  (lambda(mems values value)
              (cond ((null? values)
              	'error-not-found)
              	((equal? (car values) value)
              		(car mems))
              	(else (get-expression-of-variable (cdr mems)(cdr values) value)))))

(define make-fvars-table
	(letrec ((f (lambda (exp counter current-list)
				(if	(null? exp)
					current-list
					(f	(cdr exp)
						(+ 1 counter)
						`(,@current-list (,counter ,(car exp))))))))
	(lambda  (fvars-list mem-location)
				(let ((initial (make-initial-fvars-table mem-location)))
			(f fvars-list (+ mem-location (length initial)) initial)))))

(define fvar-list-getter (lambda (exp)
	(cond
		((or (null? exp)(symbol? exp)(tagged-with 'pvar exp)(tagged-with 'bvar exp)(tagged-with 'const exp))`(,@(list)))
		((tagged-with 'define exp) (with exp (lambda(def name obj)`,(cdr name))))
		(else `(,@(fvar-list-getter  (car exp)) ,@(fvar-list-getter  (cdr exp)))))))


 (define copy-fvar-table-to-memory (lambda (table index) 
(if (null? table)
	(string-append "//END OF memory allocation " nl) 
  (let* 
  	((exp (car table)))
	(string-append "MAKE_CLOSURE(" exp  ");" nl  
		"MOV(IND(" (number->string index) ") , R0);" nl
(copy-fvar-table-to-memory (cdr table) (+ index 1)))
	))))

(define make-initial-fvars-table
	(letrec ((f (lambda (processed-list not-processed-list counter)
				(if	(null? not-processed-list)
					processed-list
					(f	`(,@processed-list (,counter ,(car not-processed-list)))
						(cdr not-processed-list)
						(+ 1 counter))))))
	(lambda (initial-mem) 
		(f `() initial-fvars-list initial-mem))))
