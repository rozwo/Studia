#lang racket 

(provide (struct-out column-info)
         (struct-out table)
         (struct-out and-f)
         (struct-out or-f)
         (struct-out not-f)
         (struct-out eq-f)
         (struct-out eq2-f)
         (struct-out lt-f)
         table-insert
         table-project
       ;  table-sort
      ;   table-select
         table-rename
    ;     table-cross-join
   ;      table-natural-join
         )

(define-struct column-info (name type) #:transparent)

(define-struct table (schema rows) #:transparent)

(define cities
  (table
   (list (column-info 'city    'string)
         (column-info 'country 'string)
         (column-info 'area    'number)
         (column-info 'capital 'boolean))
   (list (list "Wrocław" "Poland"  293 #f)
         (list "Warsaw"  "Poland"  517 #t)
         (list "Poznań"  "Poland"  262 #f)
         (list "Berlin"  "Germany" 892 #t)
         (list "Munich"  "Germany" 310 #f)
         (list "Paris"   "France"  105 #t)
         (list "Rennes"  "France"   50 #f))))

(define countries
  (table
   (list (column-info 'country 'string)
         (column-info 'population 'number))
   (list (list "Poland" 38)
         (list "Germany" 83)
         (list "France" 67)
         (list "Spain" 47))))

(define (empty-table columns) (table columns '()))

; Wstawianie

(define (table-insert row tab)
  (define (it r s)
    (cond [(and (null? r) (null? s)) #t]
          [(equal?  (column-info-type (car s))
                    (cond [(string? (car r)) 'string]
                          [(number? (car r)) 'number]
                          [(boolean? (car r)) 'boolean]
                          [else #f]))
           (it (cdr r) (cdr s))]
          [else #f]))
  (if (it row (table-schema tab))
      (cons row tab)
      "error")
  ;;lece po kolei kolumnami i sprawdzam czy sa tego typu co te co dostalam i czy jest ich tyle ile chce
  ;;jesli tak to dodaje row do reszty (cons row tab)?
  ;;jak nie to wyrzuc error
  )


;(cons row tab)
;(car (table-rows tab))
;(column-info-type (car (table-schema t)))

; Projekcja

(define (table-project cols tab)
  (define (it c s acc t)
    (cond [(null? c) acc]
          [(equal? (column-info-name (car s)) (car c))
           (it (cdr c) (cdr s) (append acc (list (car t))) (cdr t))]
          [else (it c (cdr s) acc (cdr t))]))
  (define (it-r t) ;bo potrzebuje to zrobic dla wszystkich wierszy
    (if (null? t)
        null
        (cons (it cols (table-schema tab) '() (car t)) (it-r (cdr t)))))
  (table (it cols (table-schema tab) '() (table-schema tab))
         (it-r (table-rows tab)))
  )


; Selekcja

(define-struct and-f (l r))
(define-struct or-f (l r))
(define-struct not-f (e))
(define-struct eq-f (name val))
(define-struct eq2-f (name name2))
(define-struct lt-f (name val))


; Zmiana nazwy

(define (table-rename col ncol tab)
  (define (it s acc)
    (cond [(equal? (column-info-name (car s)) col)
           (append acc (list (column-info ncol (column-info-type (car s)))) (cdr s))]
          [else (it (cdr s) (append acc (car s)))]))
  (table (it (table-schema tab) '())
         (table-rows tab))
  )

; Sortowanie

(define (table-sort cols tab)
  ;; uzupełnij
  #f
  )



