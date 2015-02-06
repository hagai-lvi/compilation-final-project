(define lambda-opt
	(lambda args
		(if	(= (car args) 1000000)
			(car (cdr args))
			(lambda-opt (+ 1 (car args)) (- (car (cdr args)) 1)))))

(lambda-opt 1 (lambda-opt 1 (lambda-opt 1 2)))
