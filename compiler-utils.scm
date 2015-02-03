
(define *reserved-words*
  '(and begin cond define do else if lambda
    let let* letrec or quasiquote unquote 
    unquote-splicing quote set!))



(define *void-object* (void))
(define (void? exp)(equal? *void-object* exp))

(define with (lambda (s f)
					(apply f s)))

(define tagged-with
	(lambda (tag exp)
		(eq? tag (car exp))))


; Create a uniquw string id
(define getUID
		(let ((n 0))
			(lambda ()
				(set! n (+ n 1))
			(number->string n))))

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

;get a string and return a list of the ascii numbers that are representing the chars in the string
; i.e. (get-ascii-list "abc") returns (97 98 99)
(define get-ascii-list
	(lambda (str)
		(map char->integer (string->list str))))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Accessors for the constants table
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define get-const-location
	(lambda (const const-table)
		(cond	((null? const-table) #f)
				((equal? const (get-const-table-row-representation (car const-table)) )
					(get-const-table-row-mem-location (car const-table)))
				(else (get-const-location const (cdr const-table) ))
					)))

(define get-const-table-row-mem-location
	(lambda (const-table-row)
		(car const-table-row)))

(define get-const-table-row-representation
	(lambda (const-table-row)
		(cadr const-table-row)))

(define get-const-table-row-value
	(lambda (const-table-row)
		(caddr const-table-row)))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; an initial constants tbl that will include void, nill, #t and #f
(define get-initial-const-tbl
	(lambda()
	`(	(1 ,*void-object* (T_VOID))
		(2 () (T_NIL))
		(3 #f (T_BOOL 0))
		(5 #t (T_BOOL 1))
		)))

(define nl (list->string (list #\newline)))

;used for reading c macros
(define read-whole-file-by-char
  (lambda (p)
   (letrec (
   	(f (lambda (x)
   		(if (eof-object? x)
   			'()
   		(cons x (f (read-char p)))))))
	(f (read-char p)))))

;used for reading scheme input
(define read-whole-file-by-token
  (lambda (p)
   (letrec (
   	(f (lambda (x)
   		(if (eof-object? x)
   			'()
   		(cons x (f (read p)))))))
	(f (read p)))))

; get a non-null list and return all the args but the last
(define all-but-last
	(lambda (list)
		(let* (	(reversed (reverse list)))
			(reverse (cdr reversed))
				)))
; get a non null list and return the last element
(define last-element
	(lambda (list)
		(car (reverse list))))

(define initial-fvars-list
	`(	cons car cdr eq? null? boolean? integer?
		number? string? char? vector? symbol? zero?
		pair? procedure? make-string char->integer
		integer->char make-vector vector-length
		vector-ref vector-set! string-length
		string-set! string-ref set-car! set-cdr!
			+ - * / > < =  apply))


; map between scheme fvar name to the compiler's fvar name
(define fvars-map `(
	('cons				"CONS")
	('car				"CAR")
	('cdr				"CDR")
	('eq?				"EQ")
	('null?				"IS_NULL")
	('boolean?			"IS_BOOL")
	('integer?			"IS_INTEGER")
	('number?			"IS_NUMBER")
	('string?			"IS_STRING")
	('char?				"IS_CHAR")
	('vector?			"IS_VECTOR")
	('symbol?			"IS_SYMBOL")
	('zero?				"ZERO")
	('pair?				"IS_PAIR")
	('procedure?		"IS_PROC")
	('make-string		"MAKE_STRING")
	('char->integer		"CHAR_TO_INTEGER")
	('integer->char		"INTEGER_TO_CHAR")
	('make-vector		"MAKE_VECTOR")
	('vector-length		"VECTOR_LENGTH")
	('vector-ref		"VECTOR_REF")
	('vector-set!		"VECTOR_SET")
	('string-length		"STRING_LENGTH")
	('string-set!		"STRING_SET")
	('string-ref		"STRING_REF")
	('set-car!			"SET_CAR")
	('set-cdr!			"SET_CDR")
	('+					"PLUS")
	('-					"MINUS")
	('*					"MULTIPLY")
	('/					"DIV")
	('>					"BIGGER_THAN")
	('<					"LESS_THAN")
	('=					"NUMBER_EQUALS")
	('apply 			"APPLY")))
