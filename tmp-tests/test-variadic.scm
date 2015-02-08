((lambda (a b . rest)
	(+ a b)) 1 2 3)

(define lambda-var
	(lambda (a b . args)
		(if	(= (car args) 1000000)
			(car (cdr args))
			(lambda-var 1 2 (+ 1 (car args)) (- (car (cdr args)) 1)))))

(lambda-var 'a 'b 1 (lambda-var 1 2 1 (lambda-var 1 2 1 2)))
