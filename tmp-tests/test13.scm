;;;file 13: lists, vectors, primitive functions on those.

(define list->vector
  (lambda (s)
    (let* ((n (length s))
     (v (make-vector n)))
      (letrec ((loop
    (lambda (s i)
      (if (= i n) v
          (begin
      (vector-set! v i (car s))
      (loop (cdr s) (+ i 1)))))))
  (loop s 0)))))

(define length
  (lambda (s)
    (if (null? s) 0
  (+ 1 (length (cdr s))))))

(define list (lambda args args))
(define d '(1 2 3))
(define e (list 1 2 3 4))
(define f (cons '(1 2) (cons (list 3 4) (cons '(5 6 7)'()))))
d
e
f
(car d)
(cdr e)
(map car f)
(map cons e '(1 2 3 4))


(define a '#(1 2 3))
(define b (list->vector '( 1 2 3 4)))
(define c (make-vector 5 5))
a
b
c
(vector-length a)
(vector-length b)
(vector-length c)
(vector-ref a 2)
(vector-ref b 3)
(vector-ref c 4)
