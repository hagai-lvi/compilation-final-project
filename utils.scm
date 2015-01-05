
(define tagged-with
	(lambda (tag exp)
		(eq? tag (car exp))))


(define (id x) x)

(define with (lambda (s f)
					(apply f s)))


; return a pair that contain the head of the list and the last element of the list
; example: (seperate-last-element '(1 2 3 4) returns '((1 2 3) . 4)
(define (seperate-last-element list)
	(letrec ((f (lambda (list succ)
					(if (null? (cdr list))
					    (succ `() (car list))
					    (f (cdr list) (lambda (rest last)
					    					(succ (cons (car list) rest) last)))))))
	(f list (lambda (x y) (cons x y)))))


(define (add-list new-list bound-list)
	(cons new-list bound-list))
