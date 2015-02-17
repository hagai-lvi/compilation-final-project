(define x (cons 1 2))
(set-car! x 3)
x
(set-cdr! x 4)
x
(cons 2 x)
x

(define y '#(1 2 3 #t #f x) )
(vector-set! y 2 1000)

y

(define z "123abc#t#f")
(string-set! z 2 #\z)
z

(make-string 3)
(make-vector 3)
