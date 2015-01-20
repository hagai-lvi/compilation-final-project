(load "compiler-utils.scm")
(load "pattern-matcher.scm")
(load "parser_expansions.scm")


(define (^const? x)
	(or 	(boolean? x)
			(char? x)
			(number? x)
			(string? x)
			(void? x)
			))

(define (var? x)
(and (symbol? x)(let ((p (member x *reserved-words*)))
	(if p #f #t))))

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


(define (get-lambda-arguments exp)
	(if (=(length exp)0)
		'()
		(cons (cadar exp) (get-lambda-arguments (cdr exp)))))

(define (let-vars-expressions-list? list)
	(andmap (lambda (x)vector for each sheme
				(and (list? x) (var? (car x))))
			list))

(define (get-lambda-variables vars)
	(if (=(length vars)0)
		'()
		(cons (caar vars) (get-lambda-variables (cdr vars)))))


;splits the improper list to a pair of proper list and single argument: (opt-lambda-args-list '(a b c . d)) returns '((a b c) . d)
(define (opt-lambda-args-list args-list succ)
	(if (not (pair? args-list))
	    (succ (cons '() args-list))
	    (opt-lambda-args-list (cdr args-list) (lambda (partial-args-list) 
	    (succ (cons (cons (car args-list) (car partial-args-list)) (cdr partial-args-list)))))))

(define (reg-lambda-args-list? list)
	(if (not (list? list))
	    #f
	    (andmap var? list)))


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

	(define (pe->lex-pe pe)
		(treverse pe '(())))

	(define (treverse pe bound-list)
		(cond 
			((null? pe) pe)
			((or (^const? pe)(symbol? pe)(vector? pe))pe)
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
