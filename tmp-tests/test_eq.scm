
(define list (lambda args args))

(define length
  (lambda (s)
    (if (null? s) 0
  (+ 1 (length (cdr s))))))

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


(define foo
	(lambda ()
		(string->symbol
			(list->string
				(list #\a)))))
(eq? (foo) (foo))
