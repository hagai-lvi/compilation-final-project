
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


(define (beginify exp1 . lst)
	(if (and (list? lst) (> (length lst) 0))
	    `(begin ,exp1 ,@lst)
	    exp1))

(define quote?
  (lambda (tag)
    (lambda (e)
      (and (pair? e)
	   (eq? (car e) tag)
	   (pair? (cdr e))
	   (null? (cddr e))))))

(define quasiquote? 
	(lambda (e)
 (eq? e 'quasiquote)))

(define unquote? (quote? 'unquote))
(define unquote-splicing? (quote? 'unquote-splicing))

(define (improper-list? x)
	(and 	(pair? x)
			(not (null? (cdr (last-pair x))))))

(define (get-opt-lambda-mandatory-args x) (car x))
(define (get-opt-lambda-optional-args x) (cdr x))