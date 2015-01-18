(load "compiler-utils.scm")
(load "parser_expansions.scm")


(define (^const? x)
	(or 	(boolean? x)
			(char? x)
			(number? x)
			(string? x)
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

