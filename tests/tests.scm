;;; Copyright (c) 2012 Andrew W. Keep
;;; See the accompanying file Copyright for detatils
(load "compiler.scm")
(import
	(rnrs)
	(rough-draft unit-test)
	(rough-draft console-test-runner))

(define-test-suite parse-tests

	(define-test test-<lines>-1
		(assert-equal? (parse '(lambda (x y z) (if x y z))) '(lambda-simple (x y z) (if3 (var x) (var y) (var z))))
	)
	;TODO add test for parse let*
)


(define-test-suite compiler-tests

	(define-test test-improper-list?-1
		(assert-false (improper-list? '(1 2 3)))
		(assert-false (improper-list? 'a))
		(assert-true (improper-list? '(1 2 3 . 4)))
		(assert-true (improper-list? '(a b c . d)))
	)

	(define-test test-opt-lambda-args-list-1
		(assert-equal? (car (opt-lambda-args-list `(1 2 3 . 4 ) (lambda (x) x) )) `(1 2 3) )
		(assert-equal? (cdr (opt-lambda-args-list `(1 2 3 . 4 ) (lambda (x) x) )) 4 )
	)

	(define-test test-expand-letstar
		(assert-equal? (expand-letstar '((a 5) (b (+ a 5))) '(+ a b) `() )  `((lambda (a) ((lambda (b) (+ a b)) (+ a 5))) 5))
		(assert-equal? (expand-letstar '((a 5) (b (+ a 5))) '(+ a b) `((+ a b)) )  `((lambda (a) ((lambda (b) (begin (+ a b) (+ a b))) (+ a 5))) 5))
	)

	(define-test test-cond
		(assert-equal? (parse `(cond (a b c) (d e f) (else g h)))
			`(if3 (var a)
				 (seq ((var b) (var c)))
				 (if3 (var d)
							(seq ((var e) (var f)))
							(seq ((var g) (var h))))))
	)

	(define-test test-letrec
		(assert-equal? (format "~a" (parse '(letrec ((f1 (lambda (x) (+ 1 x))) (f2 (lambda (y) (* 1 y)))) 1)))
						"(applic (var Ym) ((lambda-simple (g0 f1 f2) (const 1)) (lambda-simple (g0 f1 f2) (lambda-simple (x) (applic (var +) ((const 1) (var x))))) (lambda-simple (g0 f1 f2) (lambda-simple (y) (applic (var *) ((const 1) (var y)))))))")
	)

	(define-test test-beginify
		(assert-equal? (beginify 'a) 'a)
		(assert-equal? (beginify 'a `b) `(begin a b))
		(assert-equal? (beginify 'a `b) `(begin a b))
		(assert-equal? (beginify `(+ 1 2) ) `(+ 1 2))
		(assert-equal? (beginify `(+ 1 2) `(+ 3 4) ) `(begin (+ 1 2) (+ 3 4)))
	)

	(define-test test-make-const-table
		(assert-equal? (make-const-table '(1 2 3))
			`( ,@(get-initial-const-tbl) (7 1 (T_INTEGER 1)) (9 2 (T_INTEGER 2))  (11 3 (T_INTEGER 3))))

		(assert-equal? (make-const-table '(1 "a" 3))
			`( ,@(get-initial-const-tbl) (7 1 (T_INTEGER 1)) (9 "a" (T_STRING 1 97)) (12 3 (T_INTEGER 3))))

		(assert-equal? (make-const-table '(1 "abc" 3))
			`( ,@(get-initial-const-tbl) (7 1 (T_INTEGER 1)) (9 "abc" (T_STRING 3 97 98 99)) (14 3 (T_INTEGER 3))))
	)

	(define-test test-get-const-location
		(assert-equal?	(get-const-location 1 (make-const-table '(1 2 3)))
						7)

		(assert-equal?	(get-const-location 2 (make-const-table '(1 2 3)))
						9)

		(assert-equal?	(get-const-location "2" (make-const-table '(1 "2" 3)))
						9)

		(assert-equal?	(get-const-location "abc" (make-const-table '(1 2 "a" "abc" 3)))
						14)
	)
)


(define-test-suite foo

	(define-test test-parse-or
		(assert-equal? (parse '(or)) '(const #f) )
		(assert-equal? (parse '(or #f)) '(const #f) )
		(assert-equal? (parse '(or 1)) '(const 1) )
		(assert-equal? (parse '(or 1 2 3)) '(or ((const 1) (const 2) (const 3))) )
		(assert-equal? (parse '(or a b c)) '(or ((var a) (var b) (var c) )) )
	)

	(define-test test-find-minor
		(assert-equal? (find-minor 'a '(a b c)) 0 )
		(assert-equal? (find-minor 'c '(a b c)) 2 )
		(assert-equal? (find-minor 'x '(a b c)) #f )
	)

	(define-test test-find-major-minor
		(assert-equal? (find-major-minor `a `((a) (x)) ) `(bvar a 0 0) )
		(assert-equal? (find-major-minor `x `((a x) (x) (x)) ) `(bvar x 0 1) )
		(assert-equal? (find-major-minor `not `((a b) (c) (d)) ) #f )
	)

	(define-test test-get-var-annotation
		(assert-equal? (get-var-annotation 'x '((x) (a) (b))) `(pvar x 0) )
		(assert-equal? (get-var-annotation 'x '((x y z) (x) (x))) `(pvar x 0) )
		(assert-equal? (get-var-annotation 'y '((x y z) (x) (x))) `(pvar y 1) )

		(assert-equal? (get-var-annotation 'a '((x) (a) (b))) `(bvar a 0 0) )
		(assert-equal? (get-var-annotation 'b '((x y z) (a b c) (a b c) (b))) `(bvar b 0 1) )

		(assert-equal? (get-var-annotation 'not '((a) (b) (c))) `(fvar not) )
	)

)

;(run-test-suites foo)
;(run-test foo first-test)
;(run-tests foo test-one)

(exit (+ (run-test-suites
							parse-tests
							compiler-tests)))
