#lang racket

;zadanie 7
;Lepszą reprezentacją kolejki jest para list:
;pierwsza to prefiks kolejki, a druga to sufiks w odwróconej kolejności.

;pusta kolejka
#;(define empty-queue
  null)
(define empty-queue
  (cons '() '()))

;czy kolejka jest pusta ?
#;(define (empty? q)
  (null? q))
(define (empty? q)
  (null? (car q)))

;dodaj element na koniec kolejki
#;(define (push-back x q)
  (append q (list x)))

;np (reload (list 3 4 5) (list 2 1 0)) robi '(0 1 2 3 4 5)
;potrzebna do (reload (list) (list 2 1 0)) robi '(0 1 2)
(define (reload xs ys)
  (if (null? ys)
      xs
      (reload (cons (car ys) xs) (cdr ys))))

(define (push-back x q)
  (cond [(null? q) (cons (list x) q)]
        [(null? (car q))
         (cons (reload (car q) (cons x (cdr q))) '())]
        [else (cons (car q) (cons x (cdr q)))]))

;podejrzyj element na poczatku kolejki
#;(define (front q)
  (car q))
(define (front q)
  (cond [(null? q)
         "kolejka jest pusta"]
        [(null? (car q))
         (car (reload '() (cdr q)))] ;chociaz tak usuwam ze jesli nie poda tego uzytkownik to nie bedzie takiej sytuacji
        [else (car (car q))]))

;zdejmij element z przodu kolejki
#;(define (pop q)
  (cdr q))
(define (pop q)
  (cond [(null? q)
         "kolejka jest pusta - nie mozna nic usunac"]
        [(null? (car q))
         (cons (cdr (reload '() (cdr q)) '()))]
        [(null? (cdr (car q)))
         (cons (reload '() (cdr q)) '())]
        [else (cons (cdr (car q)) (cdr q))]))




