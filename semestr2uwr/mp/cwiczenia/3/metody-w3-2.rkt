#lang racket

; sortowanie przez wstawianie - kolejność niemalejąca

(define (insert n xs)
  (if (null? xs)
      (list n)
      (if (< n (car xs))
          (cons n xs)
          (cons (car xs) (insert n (cdr xs))))))

(define (insertion-sort xs)
  (define (it xs ys)
    (if (null? xs)
        ys
        (it (cdr xs) (insert (car xs) ys))))
  (it xs null))

; kolejność nierosnąca

(define (insert-desc n xs)
  (if (null? xs)
      (list n)
      (if (> n (car xs))
          (cons n xs)
          (cons (car xs) (insert-desc n (cdr xs))))))

(define (insertion-sort-desc xs)
  (define (it xs ys)
    (if (null? xs)
        ys
        (it (cdr xs) (insert-desc (car xs) ys))))
  (it xs null))

; dowolny operator

(define (insert-generic lt n xs)
  (if (null? xs)
      (list n)
      (if (lt n (car xs))
          (cons n xs)
          (cons (car xs) (insert-generic lt n (cdr xs))))))

(define (insertion-sort-generic lt xs)
  (define (it xs ys)
    (if (null? xs)
        ys
        (it (cdr xs) (insert-generic lt (car xs) ys))))
  (it xs null))

; procedury sortujące używające wersji ogólnej

(define (insertion-sort-new xs)
  (insertion-sort-generic < xs))

(define (insertion-sort-desc-new xs)
  (insertion-sort-generic > xs))

(define (insertion-sort-string-new xs)
  (insertion-sort-generic string<? xs))

; porządek na parach liczba-ciąg znaków

(define (pair-lt p q)
  (cond [(< (car p) (car q)) #t]
        [(and (= (car p) (car q))
              (string<? (cdr p) (cdr q))) #t]
        [else #f]))

(define (generic-pair-lt car-lt cdr-lt)
  (define (pair-lt p q)
    (cond [(car-lt (car p) (car q)) #t]
          [(and (equal? (car p) (car q))
                (cdr-lt (cdr p) (cdr q))) #t]
          [else #f]))
  pair-lt)

