;;; support-code.scm
;;;
;;; Part of the initial environment that you will need to provide with
;;; your compiler, but written in [very elementary] Scheme. Put
;;; otherwise, your compiler will have to be able to compile this code
;;; in order to provide it.
;;;
;;; Programmer: Mayer Goldberg, 2012

;;; the following should be re-implemented in cisc assembly:

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
;;; bin<?
;;; bin=?





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
     ;; nil
     ((null? a) (null? b))
     ;; number
     ((and (number? a) (number? b)) (= a b))
     ;; pair
     ((and (pair? a) (pair? b))
      (and (equal? (car a) (car b))
           (equal? (cdr a) (cdr b))))
     ;; string
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

(define a (vector->list (list->vector (append '(1 2 3 4) '( 5 6 7 8) ))))
(define b (list->vector (string->list  "abcdef")))
(define c "abc")
a
(min 2 3 4)
(max 2 3 4)

(reverse a)
(string-reverse c)

(vector-append b (vector '(1 2 3)))

((order <) a)

(define c-accumulate-op-initial
 (lambda (op initial)
 (letrec ((iter (lambda (sequence)
 (if (null? sequence)
 initial
(op (car sequence) (iter (cdr sequence)))))))
 iter)))

(define add-accum (c-accumulate-op-initial + 0))

 (add-accum '(1 2 3))
 