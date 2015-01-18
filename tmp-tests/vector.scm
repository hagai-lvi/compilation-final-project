'#((2 3) (2 3) 4)
'#(#\a "abc" (1 2 3))

(vector-length (make-vector 3 '(2 3)))
(vector-length (make-vector 10 #\a))
(vector-length (make-vector 2))
(vector-length (make-vector 3 '((2 3) 2 3 (2 3))))
(vector-length (make-vector 0 '((2 3) 2 3 (2 3))))
(vector-set! (vector-set! (vector-set! (make-vector 3 #\a) 0 "this") 1 "is") 2 "sparta")
(vector-set! (make-vector 1 #\a) 0 "abc")


;actually should be void but for testing

(vector-ref (vector-set! (vector-set! (vector-set! (make-vector 3 #\a) 0 "this") 1 "is") 2 "sparta") 0)
(vector-ref (vector-set! (vector-set! (vector-set! (make-vector 3 #\a) 0 "this") 1 "is") 2 "sparta") 1)
(vector-ref (vector-set! (vector-set! (vector-set! (make-vector 3 #\a) 0 "this") 1 "is") 2 "sparta") 2)