(load "compiler.scm")

(define cons-expression?
	(lambda (exp)
		(and	(list? exp)
				(equal? (car exp) 'cons))))

(define empty-list?
	(lambda (exp)
		(or	(equal? exp '(list) )
			(equal? exp ''() ))))

(define append-strings
	(lambda (lst)
		(let ((appended-lst (map	(lambda (x)
					(if (list-of-strings? x)
						(apply string-append x)
						x))
						lst)))
		`(string-append ,@appended-lst)
		)))

(define list-of-strings?
	(lambda (x)
		(and (list? x)(andmap string? x))))
