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


(define with (lambda (s f) (apply f s)))

(letrec ((fact-1
 (lambda (n)
   (if (zero? n)
1
(* n (fact-2 (- n 1))))))
(fact-2
 (lambda (n)
   (if (zero? n)
1
(* n (fact-3 (- n 1))))))
(fact-3
 (lambda (n)
   (if (zero? n)
1
(* n (fact-4 (- n 1))))))
(fact-4
 (lambda (n)
   (if (zero? n)
1
(* n (fact-5 (- n 1))))))
(fact-5
 (lambda (n)
   (if (zero? n)
1
(* n (fact-1 (- n 1)))))))
  (fact-1 10))
