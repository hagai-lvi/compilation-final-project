(boolean? 3)
(boolean? #t)
(integer? 3)
(integer? "abc")
(string? "abc")
(string? 2)
(vector? (make-vector 3 "abc"))
(string? (make-string 3 #\a))
(vector? "abc")
(zero? 0)
(zero? 1)
(procedure? procedure?)
(procedure? 1)
(pair? '())