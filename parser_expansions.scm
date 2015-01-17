
(load "compiler-utils.scm")


(define expand-qq
  (lambda (e)
    (cond ((unquote? e) (cadr e))
	  ((unquote-splicing? e)
	   (error 'expand-qq "unquote-splicing here makes no sense!"))
	  ((pair? e)
	   (let ((a (car e))
		 (b (cdr e)))
	     (cond ((unquote-splicing? a) `(append ,(cadr a) ,(expand-qq b)))
		   ((unquote-splicing? b) `(cons ,(expand-qq a) ,(cadr b)))
		   (else `(cons ,(expand-qq a) ,(expand-qq b))))))
	  ((vector? e) `(list->vector ,(expand-qq (vector->list e))))
	  ((or (null? e) (symbol? e)) `',e)
	  (else e))))

(define expand-letstar (lambda (exp-list body1 body-rest)
	(if (= (length exp-list) 0)
	    (apply beginify `(,body1 ,@body-rest))
	    (let*( 	(seperated-exp-list (seperate-last-element exp-list))
				(last (cdr seperated-exp-list))
				(rest (car seperated-exp-list)))
		(expand-letstar rest `((lambda (,(car last)) ,(apply beginify `(,body1 ,@body-rest)) ) ,(cadr last)) `())
	))))

(define (expand-cond cond-list)
	(letrec ((f (lambda (cond-list succ)
					(cond 	((null? cond-list) (succ cond-list))
							((and (eqv? `else (caar cond-list)) (null? (cdr cond-list)) ) (succ `(begin ,@(cdar cond-list)))) ; TODO handle else
							((and (eqv? `else (caar cond-list)) (not (null? (cdr cond-list))) ) (error `expand-cond (format "else clause must be the last in a cond expression."))) ; TODO ERROR
							(else 	(f 	(cdr cond-list)
										(lambda (rest)
											(if 	(null? rest)
													(succ `(if ,(caar cond-list) (begin ,@(cdar cond-list)) ))
													(succ `(if ,(caar cond-list) (begin ,@(cdar cond-list)) ,rest))))))))))
		(f cond-list (lambda (x) x))))

(define expand-letrec
  (lambda (letrec-expr)
    (with letrec-expr
      (lambda (_letrec ribs . exprs)
	(let* ((fs (map car ribs))
	       (lambda-exprs (map cdr ribs))
	       (nu (gensym))
	       (nu+fs `(,nu ,@fs))
	       (body-f `(lambda ,nu+fs ,@exprs))
	       (hofs
		(map (lambda (lambda-expr) `(lambda ,nu+fs ,@lambda-expr))
		  lambda-exprs)))
	  `(Ym ,body-f ,@hofs))))))

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
