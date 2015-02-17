'#((2 3) (2 3) 4)
'#(#\a "abc" (1 2 3))

(vector-length (make-vector 3 '(2 3)))
(vector-length (make-vector 10 #\a))
(vector-length (make-vector 2))
(vector-length (make-vector 3 '((2 3) 2 3 (2 3))))
(vector-length (make-vector 0 '((2 3) 2 3 (2 3))))
(define a (make-vector 3 #\a))
(vector-set! a 0 "this")
(vector-set! a 1 "is")
(vector-set! a 2 "sparta")
a
(define b (make-vector 1 #\a))
(vector-set! b 0 "abc")
b

(vector-ref a 0)
(vector-ref a 1)
(vector-ref a 2)
