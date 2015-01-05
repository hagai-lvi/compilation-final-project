(load "compiler.scm")

(define cons-expression?
	(lambda (exp)
		(and	(list? exp)
				(equal? (car exp) 'cons))))

(define empty-list?
	(lambda (exp)
		(or	(equal? exp '(list) )
			(equal? exp ''() ))))
