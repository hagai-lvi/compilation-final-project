(define f-variadic
	(lambda (a b c d . rst)
		;(a (car rst) (car rst) (car rst) (car rst) (car rst))))
		;(car rst)))
		(g-variadic 1 2 3 4 5 6 7 )))

(define g-variadic
	(lambda (a b c d . rst)
		(+ a b c d (car rst) (car (cdr rst)))
		))

(define b 1)

(g-variadic 1 2 3 4 5 6 7 )

(f-variadic g-variadic 'b 'c 'd 1)
