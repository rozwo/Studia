#lang racket

;zadanie 9

(define (minimum xs)
  (define (min xs m)
    (cond [(null? xs) m]
          [(< (car xs) m)
            (min (cdr xs) (car xs))]
          [else (min (cdr xs) m)]))
  (min xs +inf.0))

(define (delete-x x xs)
  (cond [(null? xs) null]
        [(= x (car xs)) (cdr xs)]
        [else (cons (car xs) (delete-x x (cdr xs)))]))

(define (select xs)
  (if (null? xs)
      null
      (cons (minimum xs) (delete-x (minimum xs) xs))))

(define (select-sort xs)
  (if (null? xs)
      null
      (cons (car (select xs)) (select-sort (cdr (select xs))))))



;zadanie 10

(define (dl xs)
  (define (it l xs)
    (if (null? xs)
        l
        (it (+ l 1) (cdr xs))))
  (it 0 xs))

(define (cz_list xs n)
  (define (cz1_list xs n)
    (if (= n 0)
        null
        (cons (car xs) (cz1_list (cdr xs) (- n 1)))))
  (define (cz2_list xs n)
    (if (= n 0)
        xs
        (cz2_list (cdr xs) (- n 1))))
  (cons (cz1_list xs n) (cz2_list xs n)))

(define (split xs)
  (define n (dl xs))
  (if (even? n)
      (cz_list xs (/ n 2))
      (cz_list xs (+ (floor (/ n 2)) 1))))

(define (merge xs ys)
  (cond [(null? xs) ys]
        [(null? ys) xs]
        [else (if (< (car xs) (car ys))
                  (cons (car xs) (merge (cdr xs) ys))
                  (cons (car ys) (merge xs (cdr ys))))]))


(define (merge-sort xs)
  (define ys (split xs))
  (if (or (= (dl xs) 0) (= (dl xs) 1))
      xs
      (merge (merge-sort (car ys)) (merge-sort (cdr ys)))))















