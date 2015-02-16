(define map
  ((lambda (y) 
     ((lambda (map1) 
  ((lambda (maplist) 
     (lambda (f . s) 
       (maplist f s))) 
   (y (lambda (maplist) 
        (lambda (f s) 
    (if (null? (car s)) '() 
        (cons (apply f (map1 car s)) 
        (maplist f (map1 cdr s))))))))) 
      (y (lambda (map1) 
     (lambda (f s) 
       (if (null? s) '() 
     (cons (f (car s)) 
           (map1 f (cdr s))))))))) 
   (lambda (f) 
     ((lambda (x) 
  (f (lambda (y z)
       ((x x) y z))))
      (lambda (x) 
  (f (lambda (y z)
       ((x x) y z))))))))

       (define Ym
  (lambda fs
    (let ((ms (map
    (lambda (fi)
      (lambda ms
        (apply fi (map (lambda (mi)
             (lambda args
               (apply (apply mi ms) args))) ms))))
    fs)))
      (apply (car ms) ms))))


;;; support-code.scm
;;;
;;; Part of the initial environment that you will need to provide with
;;; your compiler, but written in [very elementary] Scheme. Put
;;; otherwise, your compiler will have to be able to compile this code
;;; in order to provide it.
;;;
;;; Programmer: Mayer Goldberg, 2012

;;; the following should be re-implemented in cisc assembly:

(define bin+ (lambda (x y) (+ x y)))
(define bin- (lambda (x y) (- x y)))
(define bin* (lambda (x y) (* x y)))
(define bin/ (lambda (x y) (/ x y)))

;;; rename ++ to +

(define ++
  (letrec ((loop
      (lambda (s)
        (if (null? s)
      0
      (bin+ (car s)
      (loop (cdr s)))))))
    (lambda s (loop s))))

;;; rename ** to *

(define **
  (letrec ((loop
      (lambda (s)
        (if (null? s)
      1
      (bin* (car s)
      (loop (cdr s)))))))
    (lambda s (loop s))))

;;; rename -- to -

(define --
  (lambda (a . s)
    (if (null? s)
  (bin- 0 a)
  (bin- a (apply ++ s)))))

;;; rename // to /

(define //
  (lambda (a . s)
    (if (null? s)
  (bin/ 1 a)
  (bin/ a (apply ** s)))))

;;;

(define add1 (lambda (n) (bin+ n 1))) 
(define sub1 (lambda (n) (bin- n 1)))

(define order
  (lambda (<)
    (letrec ((loop
        (lambda (a s)
    (or (null? s)
        (and (< a (car s))
       (loop (car s) (cdr s)))))))
      (lambda (a . s)
  (loop a s)))))

;;; extension: a variadic not-equal
(define <>
  (letrec ((loop
      (lambda (a s)
        (or (null? s)
      (and (andmap (lambda (b) (not (= a b))) s)
           (loop (car s) (cdr s)))))))
    (lambda s
      (loop (car s) (cdr s)))))

(define not (lambda (x) (if x #f #t)))

(define foldr
  (lambda (binop final s)
    (letrec ((loop
        (lambda (s)
    (if (null? s) final
        (binop (car s) (loop (cdr s)))))))
      (loop s))))

(define compose
  (let ((binary-compose
   (lambda (f g)
     (lambda (x)
       (f (g x))))))
    (lambda s
      (foldr binary-compose (lambda (x) x) s))))

(define caar (compose car car))
(define cadr (compose car cdr))
(define cdar (compose cdr car))
(define cddr (compose cdr cdr))
(define caaar (compose car caar))
(define caadr (compose car cadr))
(define cadar (compose car cdar))
(define caddr (compose car cddr))
(define cdaar (compose cdr caar))
(define cdadr (compose cdr cadr))
(define cddar (compose cdr cdar))
(define cdddr (compose cdr cddr))
(define caaaar (compose car caaar))
(define caaadr (compose car caadr))
(define caadar (compose car cadar))
(define caaddr (compose car caddr))
(define cadaar (compose car cdaar))
(define cadadr (compose car cdadr))
(define caddar (compose car cddar))
(define cadddr (compose car cdddr))
(define cdaaar (compose cdr caaar))
(define cdaadr (compose cdr caadr))
(define cdadar (compose cdr cadar))
(define cdaddr (compose cdr caddr))
(define cddaar (compose cdr cdaar))
(define cddadr (compose cdr cdadr))
(define cdddar (compose cdr cddar))
(define cddddr (compose cdr cdddr))

(define ^variadic-right-from-binary
  (lambda (binary-op base-value)
    (letrec ((op-list
        (lambda (s)
    (if (null? s) base-value
        (binary-op (car s) (op-list (cdr s)))))))
      (lambda args
  (op-list args)))))

(define ^variadic-left-from-binary
  (lambda (binary-op base-value)
    (letrec ((op-list
        (lambda (acc s)
    (if (null? s) acc
        (op-list (binary-op acc (car s)) (cdr s))))))
      (lambda args
  (if (null? args) base-value
      (op-list (car args) (cdr args)))))))

(define ^char-op
  (lambda (int-op)
    (lambda (ch1 ch2)
      (int-op (char->integer ch1) (char->integer ch2)))))

;;; You need to have the following binary boolean predicates:
(define  bin<? <)
(define  bin=? =)

(define bin>? (lambda (a b) (bin<? b a)))
(define bin<=? (lambda (a b) (not (bin>? a b))))
(define bin>=? (lambda (a b) (not (bin<? a b))))

(define < (order bin<?))
(define <= (order bin<=?))
(define > (order bin>?))
(define >= (order bin>=?))

(define char=? (order (^char-op bin=?)))
(define char<=? (order (^char-op bin<=?)))
(define char<? (order (^char-op bin<?)))
(define char>=? (order (^char-op bin>=?)))
(define char>? (order (^char-op bin>?)))

(define char-uppercase?
  (lambda (ch)
    (and (char<=? #\A ch)
   (char<=? ch #\Z))))

(define char-lowercase?
  (lambda (ch)
    (and (char<=? #\a ch)
   (char<=? ch #\z))))

(define char-upcase
  (let ((char-aA (- (char->integer #\a) (char->integer #\A))))
    (lambda (ch)
      (if (char-lowercase? ch)
    (integer->char
     (- (char->integer ch) char-aA))
    ch))))

(define char-downcase
  (let ((char-aA (- (char->integer #\a) (char->integer #\A))))
    (lambda (ch)
      (if (char-uppercase? ch)
    (integer->char
     (+ (char->integer ch) char-aA))
    ch))))

(define char-ci<=?
  (order
   (lambda (ch1 ch2)
     (char<=? (char-upcase ch1) (char-upcase ch2)))))

(define char-ci<?
  (order
   (lambda (ch1 ch2)
     (char<? (char-upcase ch1) (char-upcase ch2)))))

(define char-ci=?
  (order
   (lambda (ch1 ch2)
     (char=? (char-upcase ch1) (char-upcase ch2)))))

(define char-ci>?
  (order
   (lambda (ch1 ch2)
     (char>? (char-upcase ch1) (char-upcase ch2)))))

(define char-ci>=?
  (order
   (lambda (ch1 ch2)
     (char>=? (char-upcase ch1) (char-upcase ch2)))))

(define string-upcase
  (lambda (string)
    (list->string
     (map char-upcase (string->list string)))))

(define string-downcase
  (lambda (string)
    (list->string
     (map char-downcase (string->list string)))))

(define even?
  (lambda (n)
    (zero? (remainder n 2))))

(define odd?
  (lambda (n)
    (not (zero? (remainder n 2)))))

(define length
  (lambda (s)
    (if (null? s) 0
  (add1 (length (cdr s))))))

(define list (lambda args args))

(define list-ref
  (lambda (s i)
    (if (zero? i) (car s)
  (list-ref (cdr s) (- i 1)))))

(define list?
  (lambda (e)
    (or (null? e)
  (and (pair? e)
       (list? (cdr e))))))

(define member?
  (lambda (a s)
    (ormap (lambda (b) (eq? a b)) s)))

(define negative? (lambda (n) (< n 0)))

(define positive? (lambda (n) (> n 0)))

(define zero? (lambda (x) (= x 0)))

(define vector (lambda args (list->vector args)))

(define ormap
  (lambda (f . s)
    (letrec ((loop
        (lambda (s)
    (and (pair? (car s))
         (or (apply f (map car s))
       (loop (map cdr s)))))))
      (loop s))))

(define andmap
  (lambda (f . s)
    (letrec ((loop
        (lambda (s)
    (or (null? (car s))
        (and (apply f (map car s))
       (loop (map cdr s)))))))
      (loop s))))

(define string->list
  (letrec ((loop
      (lambda (str n s)
        (if (= n -1) s
      (loop str
      (- n 1)
      (cons (string-ref str n) s))))))
    (lambda (str)
      (loop str (- (string-length str) 1) '()))))

(define binary-string=?
  (lambda (str1 str2)
    (let ((n1 (string-length str1))
    (n2 (string-length str2)))
      (and (= n1 n2)
     (let ((s1 (string->list str1))
     (s2 (string->list str2)))
       (andmap char=? s1 s2))))))

(define binary-string<?
  (lambda (str1 str2)
    (letrec ((loop
        (lambda (s1 s2)
    (cond ((null? s1) (pair? s2))
          ((null? s2) #f)
          ((char=? (car s1) (car s2))
           (loop (cdr s1) (cdr s2)))
          (else (char<? (car s1) (car s2)))))))
      (loop (string->list str1)
      (string->list str2)))))

(define binary-string>? (lambda (str1 str2) (binary-string<? str2 str1)))

(define binary-string<=?
  (lambda (str1 str2) (not (binary-string>? str1 str2))))

(define binary-string>=?
  (lambda (str1 str2) (not (binary-string<? str1 str2))))

(define string=? (order binary-string=?))
(define string<? (order binary-string<?))
(define string>? (order binary-string>?))
(define string<=? (order binary-string<=?))
(define string>=? (order binary-string>=?))

(define vector->list
  (letrec ((loop
      (lambda (v n s)
        (if (= n -1) s
      (loop v
      (- n 1)
      (cons (vector-ref v n) s))))))
    (lambda (v)
      (loop v (- (vector-length v) 1) '()))))

(define list->string
  (lambda (s)
    (let* ((n (length s))
     (str (make-string n)))
      (letrec ((loop
    (lambda (s i)
      (if (= i n) str
          (begin
      (string-set! str i (car s))
      (loop (cdr s) (+ i 1)))))))
  (loop s 0)))))

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

(define member
  (lambda (a s)
    (cond ((null? s) #f)
    ((equal? (car s) a) s)
    (else (member a (cdr s))))))

;;; this procedure is defined as an abstraction over assoc/assq,
;;; with the potential to define assoc over new and interesting
;;; predicates...

(define boolean=?
  (lambda (a b)
    (if (and (boolean? a) (boolean? b))
  (if a b (not b))
  #f ; should have generated an error message!
  )))

(define equal?
  (let ((void-object (if #f #f)))
    (letrec ((equal?
        (lambda (a b)
    (cond
     ;; bool
     ((and (boolean? a) (boolean? b))
      (boolean=? a b))
     ;; char
     ((and (char? a) (char? b)) (char=? a b))
     ;; nil
     ((null? a) (null? b))
     ;; number
     ((and (number? a) (number? b)) (= a b))
     ;; pair
     ((and (pair? a) (pair? b))
      (and (equal? (car a) (car b))
           (equal? (cdr a) (cdr b))))
     ;; string
     ((and (string? a) (string? b)) (string=? a b))
     ;; symbol
     ((and (symbol? a) (symbol? b)) (eq? a b))
     ;; vector
     ((and (vector? a) (vector? b)
           (= (vector-length a) (vector-length b)))
      (equal? (vector->list a) (vector->list b)))
     ;; void
     ((eq? a void-object) (eq? b void-object))
     (else #f)))))
      equal?)))

(define ^associate
  (lambda (equal?)
    (letrec ((run
        (lambda (a s)
    (cond ((null? s) #f)
          ((equal? (caar s) a) (car s))
          (else (run a (cdr s)))))))
      run)))

(define assoc (^associate equal?))

(define assq (^associate eq?))

(define void
  (let ((void-object
   (if #f #f)))
    (lambda () void-object)))

(define void?
  (let ((void-object (void)))
    (lambda (x) (eq? x void-object))))

(define string-append
  (lambda s
    (list->string (apply append (map string->list s)))))

(define vector-append
  (lambda s
    (list->vector (apply append (map vector->list s)))))

(define append
  (letrec ((app2
      (lambda (s1 s2)
        (if (null? s1) s2
      (cons (car s1)
       (app2 (cdr s1) s2)))))
     (appl
      (lambda (s1 s)
        (if (null? s) s1
      (app2 s1 (appl (car s) (cdr s)))))))
    (lambda s
      (if (null? s) '()
    (appl (car s) (cdr s))))))

(define reverse
  (letrec ((loop
      (lambda (s r)
        (if (null? s) r
      (loop (cdr s) (cons (car s) r))))))
    (lambda (s)
      (loop s '()))))

(define string-reverse
  (compose
   list->string
   reverse
   string->list))

(define list-ref
  (lambda (s i)
    (if (zero? i) (car s)
  (list-ref (cdr s) (- i 1)))))

(define list-set!
  (lambda (s i x)
    (if (zero? i) (set-car! s x)
  (list-set! (cdr s) (- i 1) x))))

(define max
  (let ((binary-max (lambda (a b) (if (> a b) a b))))
    (lambda (a . s)
      (foldr binary-max a s))))

(define min
  (let ((binary-min (lambda (a b) (if (< a b) a b))))
    (lambda (a . s)
      (foldr binary-min a s))))

;;; in principle, you need the (error ... ) procedure for this,
;;; but as long as you don't call it everything should be fine.
;;; alternately, you can implement it. :-)




#f
#t
'()
(or #t #t)
(if #f #f #t)
(and #t #t)
(or #f #t)
(or #f #f #f #t)
(or (or (or (or #f #f #f #f)
            (or #f #f #f #t))
        #f #f)
    #f)
(begin #f #f #f #f #t)
(begin (begin (begin #f) #f #f)
       #f #f #f #t)
((lambda (x) x) #t)
((lambda (x y) y) #f #t)
(let ((x #f) (y #t))
  (let ((x (if x #f #t))
        (y (if y #t #f)))
    (let ((x (if x #f #t))
          (y (if y #t #f)))
      (let ((x (if x #f #t))
            (y (if y #t #f)))
        (or x y)))))
(((lambda (x) x)
  (lambda (x) x)) #t)
((((lambda (x) (x x))
   (lambda (x) x))
  (lambda (x) x))
 #t)
(((((lambda (x) (x x))
    (lambda (x) (lambda (y) x)))
   #f) #t) #f)
(((((lambda (x) ((x x) (x x)))
    (lambda (x) (lambda (y) (x (x y)))))
   (lambda (x) (x (lambda (x) (lambda (y) (lambda (z) ((z y) x)))))))
  (lambda (x) ((x #f) #t)))
 (lambda (x) (lambda (y) y)))
3
'bla
'(1 2 3)
(define b '(4 5 6 78 9))
 (car b)
(define b '(4 5 6 78 9))
 (cdr b)
(define b '(4 5 6 78 9))
 (define e (cdr b))
 (car e)
(+ 85 96)
(eq? 'bla 'bla)
(= 20 20)
(apply + '(2 3 5 10))
(apply - '(10 3))
(define fact
    (lambda (n)
      (if (zero? n)
          1
          (* n (fact (- n 1))))))
 (fact 6)
(boolean? #f)
(not (boolean? 123))
(symbol? 'p)
(procedure? procedure?)
(= (car (cons 1 9)) 1)
(integer? 123)
(char? #\g)
(null? '())
(string? "abccd")
(symbol? 'lambda)
(vector? '#(1 2 3 6))
(not (vector? 1235))
(= 3 (vector-length '#(b #t ())))
(pair? '(a . o))
(zero? 0)
(let ((n 1000))
   (= n (string-length (make-string n))))   
(let ((n 1000))
   (= n (vector-length (make-vector n))))  
(let* ((v (make-vector 3))
  (vs! (lambda (i x) (vector-set! v i x))))
   (vs! 0 'a)
   (vs! 1 234)
   (vs! 2 #\P)
   (equal? v '#(a 234 #\P)))  
(let ((p (cons 'a 'b)))
   (set-car! p 'just)
   (set-cdr! p 'fine)
   (equal? p '(just . fine)))  
(let ((v '#(a b c)))
   (eq? 'c (vector-ref v 2)))   
(= 65 (char->integer #\A))
(= 3 (remainder 7 4))
(= 6 (* 1 2 3))
(= 6 (+ 1 2 3))
(= 1 (- 6 3 2))
(< 1 2 3 4 5)
(> 5 4 3 2 1)
(equal? '(2 . 3) (apply cons '(2 3)))
(eq? 'd (cadddr '(a b c d)))
(even? 4)
(odd? 5)
(equal? '(a b c d) (list 'a 'b 'c 'd))
(list? '())
(list? '(a b c))
(equal? '(2 3 4) (map add1 '(1 2 3)))
(equal? '(5 7 9) (map + '(1 2 3) '(4 5 6)))
(member? 'do '(a b c do re mi 1 2 3))
(negative? -4)
(not (string<=? "def" "abc"))
(= 10 (max 4 3 2 1 6 7 8 10))
(zero? (min 4 5 6 0 7 8 9)) 
(let ((a 1))
  (let ((b 2) (c 3))
    (let ((d 4) (e 5) (f 6))
      (= 720 (* a b c d e f)))))    
(define with (lambda (s f) (apply f s)))
 (define fact-1
  (lambda (n)
    (if (zero? n)
  (list 1 'fact-1)
  (with (fact-2 (- n 1))
    (lambda (r . trail)
      (cons (* n r)
        (cons 'fact-1 trail)))))))
 (define fact-2
  (lambda (n)
    (if (zero? n)
  (list 1 'fact-2)
  (with (fact-3 (- n 1))
    (lambda (r . trail)
      (cons (* n r)
        (cons 'fact-2 trail)))))))
 (define fact-3
  (lambda (n)
    (if (zero? n)
  (list 1 'fact-3)
  (with (fact-1 (- n 1))
    (lambda (r . trail)
      (cons (* n r) 
        (cons 'fact-3 trail)))))))
 (fact-1 6) 

(and
 (boolean? #t)
 (boolean? #f)
 (not (boolean? 1234))
 (not (boolean? 'a))
 (symbol? 'b)
 (procedure? procedure?)
 (eq? (car '(a b c)) 'a)
 (= (car (cons 1 2)) 1)
 (integer? 1234)
 (char? #\a)
 (null? '())
 (string? "abc")
 (symbol? 'lambda)
 (vector? '#(1 2 3))
 (not (vector? 1234))
 (not (string? '#(a b c)))
 (not (string? 1234))
 (= 3 (vector-length '#(a #t ())))
 (pair? '(a . b))
 (not (pair? '()))
 (zero? 0)
 (not (zero? 234))
 (= 97 (char->integer (string-ref "abc" 0)))
 (let ((n 10000))
   (= n (string-length (make-string n))))
 (let ((n 10000))
   (= n (vector-length (make-vector n))))
 (let* ((v (make-vector 3))
  (vs! (lambda (i x) (vector-set! v i x))))
   (vs! 0 'a)
   (vs! 1 234)
   (vs! 2 #\P)
   (equal? v '#(a 234 #\P)))
 (let ((p (cons 'a 'b)))
   (set-car! p 'just)
   (set-cdr! p 'fine)
   (equal? p '(just . fine)))
 (let ((v '#(a b c)))
   (eq? 'c (vector-ref v 2)))
 (= 65 (char->integer #\A))
 (let ((string (make-string 2)))
   (string-set! string 0 (integer->char 97))
   (string-set! string 1 (integer->char 98))
   (eq? 'ab (string->symbol string)))
 (let ((string (symbol->string 'abc)))
   (and (char=? (string-ref string 0) #\a)
  (char=? (string-ref string 1) #\b)
  (char=? (string-ref string 2) #\c)
  (= 3 (string-length string))))
 (= 3 (remainder 7 4))
 (= 6 (* 1 2 3))
 (= 1 (*))
 (= 234 (* 234))
 (= 6 (+ 1 2 3))
 (zero? (+))
 (= 234 (+ 234))
 (= 1 (- 6 3 2))
 (< 1 2 3 4 5)
 (> 5 4 3 2 1)
 (equal? '(2 . 3) (apply cons '(2 3)))
  (equal? '(a 1) (assoc 'a '((x 23) (b 2) (c 3) (a 1) (d 4))))
 (not (assoc 'a '((x 1) (y 2) (z 3))))
 )


(and
 (= 4 (sub1 5))
 (= -5 (sub1 -4))
 (= 5 (add1 4))
 (= -4 (add1 -5))
 (not #f)
 (not (not 34))
 (not (not 'a))
 (zero? ((compose add1 sub1) 0))
 (eq? 'd (cadddr '(a b c d)))
 (char=? #\a #\a)
 (char-ci=? #\a #\A)
 (char-lowercase? #\a)
 (not (char-lowercase? #\A))
 (char=? #\a (char-downcase #\A))
 (even? 4)
 (odd? 5)
 (not (even? 5))
 (not (odd? 4))
 (= 4 (length '(a b c d)))
 (equal? '(a b c d) (list 'a 'b 'c 'd))
 (eq? 'd (list-ref '(a b c d) 3))
 (list? '())
 (list? '(a b c))
 (not (list? 'a))
 (not (list? '(a . b)))
 (not (list? #f))
 (equal? '(2 3 4) (map add1 '(1 2 3)))
 (equal? '(5 7 9) (map + '(1 2 3) '(4 5 6)))
 (member? 'do '(a b c do re mi 1 2 3))
 (not (member? 'x '()))
 (not (member? 'foo! '(1 2 3 4 5 6)))
 (negative? -4)
 (not (negative? 0))
 (positive? 5)
 (not (positive? 0))
 (not (positive? -5))
 (equal? '#(4 9 6 3 5 1) (vector 4 9 6 3 5 1))
 (ormap even? '(1 3 5 7 9 0 -25))
 (andmap even? '())
 (string=? "Hello World!" (list->string (string->list "Hello World!")))
 (string<=? "abc" "abc")
 (string<=? "" "abc")
 (not (string<=? "def" "abc"))
 (equal? '(4 9 6 3 5 1) (vector->list (list->vector '(4 9 6 3 5 1))))
 (equal? '(a b c) (member 'a '(x y z a b c)))
 (equal? '(a b c d) (append '(a b) '(c d)))
 (equal? '(3 2 1) (reverse '(1 2 3)))
 (null? (reverse '()))
 (string=? "abc" (string-reverse (string-reverse "abc")))
 (eq? 'a (list-ref '(x y z a b c) 3))
 (= 10 (max 4 3 2 1 6 7 8 10))
 (zero? (min 4 5 6 0 7 8 9))
 )


(define even?
  (letrec ((even-1?
      (lambda (n)
        (or (zero? n)
      (odd-2? (- n 1) 'odd-2))))
     (odd-2?
      (lambda (n _)
        (and (positive? n)
       (even-3? (- n 1) (+ n n) (+ n n n)))))
     (even-3?
      (lambda (n _1 _2)
        (or (zero? n)
      (odd-5? (- n 1) (+ n n) (* n n) 'odd-5 'odder-5))))
     (odd-5?
      (lambda (n _1 _2 _3 _4)
        (and (positive? n)
       (even-1? (- n 1))))))
    even-1?))
(even? 4)

(let ((a 1))
  (let ((b 2) (c 3))
    (let ((d 4) (e 5) (f 6))
      (= 720 (* a b c d e f)))))


((lambda (x) (x x 1000000))
 (lambda (x n)
   (if (zero? n) #t
       (x x (- n 1)))))

(define test
  (lambda ()
    (let* ((f (lambda (s)
    (string->symbol
     (symbol->string s))))
     (g1 (gensym))
     (g2 (gensym))
     (g3 (gensym)))
      (and (eq? g1 g1)
     (eq? g2 g2)
     (eq? g3 g3)
     (not (eq? g1 g2))
     (not (eq? g2 g3))
     (not (eq? g1 g3))
     (eq? (f g1)
    (f (f g1)))
     (eq? (f (f g2))
    (f (f (f (f (f g2))))))
     (not (eq? g1 (f g1)))
     (not (eq? g3 (f (f (f (f (f g3)))))))
     (eq? (f (f g2))
    (f (f (f (f (f (f (f (f g2)))))))))))))
(test)

(((((lambda (x) (x (x x)))
    (lambda (x)
      (lambda (y)
  (x (x y)))))
   (lambda (p)
     (p (lambda (x)
    (lambda (y)
      (lambda (z)
        ((z y) x)))))))
  (lambda (x)
    ((x #t) #f)))
 (lambda (x)
   (lambda (y)
     x)))

     (define even?
  (letrec ((even-1?
      (lambda (n)
        (or (zero? n)
      (odd-2? (- n 1) 'odd-2))))
     (odd-2?
      (lambda (n _)
        (and (positive? n)
       (even-3? (- n 1) (+ n n) (+ n n n)))))
     (even-3?
      (lambda (n _1 _2)
        (or (zero? n)
      (odd-5? (- n 1) (+ n n) (* n n) 'odd-5 'odder-5))))
     (odd-5?
      (lambda (n _1 _2 _3 _4)
        (and (positive? n)
       (even-1? (- n 1))))))
    even-1?))
        
        (even? 4)

        (define test
  (let ((p1 (lambda (x1 x2 x3 x4 x5 x6 x7 x8 x9 x10)
        (lambda (z)
    (z x2 x3 x4 x5 x6 x7 x8 x9 x10 x1))))
  (s '(a b c d e f g h i j)))
    (lambda ()
      (equal? (((((((((((apply p1 s) p1) p1) p1) p1) p1) p1) p1) p1) p1)
         list)
        s))))

        (test)
        (let ((a 1))
  (let ((b 2) (c 3))
    (let ((d 4) (e 5) (f 6))
      (= 720 (* a b c d e f)))))
        (let ()
  ((lambda s
     (let ()
       ((lambda s s) s s s)))
   #t))


        (define fact
  (letrec ((fact-1
      (lambda (n r)
        (if (zero? n)
      r
      (fact-2 (- n 1)
        (* n r)
        'moshe
        'yosi))))
     (fact-2
      (lambda (n r _1 _2)
        (if (zero? n)
      r
      (fact-3 (- n 1)
        (* n r)
        'dana
        'michal
        'olga
        'sonia))))
     (fact-3
      (lambda (n r _1 _2 _3 _4)
        (if (zero? n)
      r
      (fact-1 (- n 1)
        (* n r))))))
    (lambda (n)
      (fact-1 n 1))))

        (fact 5)


        (define fact-1
  (lambda (n)
    (if (zero? n)
  (list 1 'fact-1)
  (with (fact-2 (- n 1))
    (lambda (r . trail)
      (cons (* n r)
        (cons 'fact-1 trail)))))))

(define fact-2
  (lambda (n)
    (if (zero? n)
  (list 1 'fact-2)
  (with (fact-3 (- n 1))
    (lambda (r . trail)
      (cons (* n r)
        (cons 'fact-2 trail)))))))

(define fact-3
  (lambda (n)
    (if (zero? n)
  (list 1 'fact-3)
  (with (fact-1 (- n 1))
    (lambda (r . trail)
      (cons (* n r)
        (cons 'fact-3 trail)))))))
(fact-3 10)


(((((lambda (x) ((x x) (x x)))
    (lambda (x)
      (lambda (y)
  (x (x y)))))
   (lambda (p)
     (p (lambda (x y)
    (lambda (p)
      (p y x))))))
  (lambda (z) (z #t #f)))
 (lambda (x y) x))
