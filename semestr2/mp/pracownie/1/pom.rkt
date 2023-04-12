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
         table-sort
         table-select
         table-rename
         table-cross-join
         table-natural-join)

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
          [(null? s) #f]
          [(null? r) #f]
          [(equal?  (column-info-type (car s))
                    (cond [(string? (car r)) 'string]
                          [(number? (car r)) 'number]
                          [(boolean? (car r)) 'boolean]
                          [else #f]))
           (it (cdr r) (cdr s))]
          [else #f]))
  (if (it row (table-schema tab))
      (table (table-schema tab) (append (list row) (table-rows tab)))
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
          [(null? s) acc]
          [(null? (cdr c)) (if (equal? (column-info-name (car s)) (car c))
                               (append acc (list (car t)))
                               (it c (cdr s) acc (cdr t)))]
          [(equal? (column-info-name (car s)) (car c))
           (it (cdr c) (cdr s) (append acc (list (car t))) (cdr t))]
          [else (it c (cdr s) acc (cdr t))]))
  
  (define (it-r t) ;bo potrzebuje to zrobic dla wszystkich wierszy
    (cond [(null? t) null]
          [(null? (cdr t)) (it cols (table-schema tab) '() (car t))]
          [else (cons (it cols (table-schema tab) '() (car t)) (it-r (cdr t)))]))
  
  (table (it cols (table-schema tab) '() (table-schema tab))
         (it-r (table-rows tab)))
  )

; Sortowanie

(define (elem-cols s w c) ;wyciaganie z wiersza elementu z przeszukiwanej kolumny
  (if (equal? (column-info-name (car s)) c)
      (car w)
      (elem-cols (cdr s) (cdr w) c)))
;test
;(elem-cols (table-schema cities) (list "Wrocław" "Poland"  293 #f) 'area)
  
(define (min wx wy c tab) ;co jest mniejsze w zaleznosci od tego jakiego jest typu
  (define x (elem-cols (table-schema tab) wx (car c)))
  (define y (elem-cols (table-schema tab) wy (car c)))
  (cond [(string? x) (cond [(and (string=? y x) (null? (cdr c))) wx]
                           [(string=? y x) (min wx wy (cdr c) tab)]
                           [(string<? y x) wy]
                           [else wx])]
        [(number? x) (cond [(and (= x y) (null? (cdr c))) wx]
                           [(= x y) (min wx wy (cdr c) tab)]
                           [(> x y) wy]
                           [else wx])]
        [(boolean? x) (cond [(and (boolean=? x y) (null? (cdr c))) wx]
                            [(boolean=? x y) (min wx wy (cdr c) tab)]
                            [(and (boolean=? x #t) (boolean=? y #f)) wy]
                            [else wx])]
        [else (define x (symbol->string x))
              (define y (symbol->string y))
              (cond [(and (string=? y x) (null? (cdr c))) wx]
                    [(string=? y x) (min wx wy (cdr c) tab)]
                    [(string<? y x) wy]
                    [else wx])] ;'symbol
        ))
;test - a co jak ktos poda cos zlego
;(min (list "Wrocław" "Poland"  293 #f) (list "Warsaw"  "Poland"  517 #t) '(city) cities)
;(min (list "Wrocław" "Poland"  293 #f) (list "Warsaw"  "Poland"  517 #t) '(country capital) cities)

(define (minimum t w c tab) ;szuka wiersza z mnajmniejsza wartoscia w przeszukiwanej kolumnie
  (if (null? t)
      w
      (minimum (cdr t) (min w (car t) c tab) c tab)))
;test
;(minimum (table-rows cities) (list "Wrocław" "Poland"  293 #f) '(country city) cities)
  
(define (wytnij-wiersz w t) ;wycina podany wiersz z listy
  (cond [(null? t) null]
        [(equal? w (car t)) (cdr t)]
        [else (cons (car t) (wytnij-wiersz w (cdr t)))]))
;test
;(wyt (list "Warsaw"  "Poland"  517 #t) (table-rows cities))

(define (table-sort cols tab)
  (define (it t acc) ;szukam wiersza z minimum w tabeli, potem szukam kolejnego minimum w tym co w tabeli zostalo itd az tabela sie skonczy, jednoczesnie sklejam minima
    (if (null? t)
        acc
        (let [(m (minimum (cdr t) (car t) cols tab))] (it (wytnij-wiersz m t) (append acc (list m)))))) ; najw najm (cons m acc) a najm najw (append acc (list m))
  (table (table-schema tab) (it (table-rows tab) '()))
  )


; Selekcja za 2 pkt

(define-struct and-f (l r))
(define-struct or-f (l r))
(define-struct not-f (e))
(define-struct eq-f (name val))
(define-struct eq2-f (name name2))
(define-struct lt-f (name val))

(define (spelnia form w s)
  (cond [(and-f? form) (and (spelnia (and-f-l form) w s) (spelnia (and-f-r form) w s))]
        [(or-f? form) (or (spelnia (or-f-l form) w s) (spelnia (or-f-r form) w s))]
        [(not-f? form) (not (spelnia (not-f-e form) w s))]
        [(eq-f? form) (equal? (elem-cols s w (eq-f-name form)) (eq-f-val form))]
        [(eq2-f? form) (equal? (elem-cols s w (eq2-f-name form)) (elem-cols s w (eq2-f-name2 form)))]
        [(lt-f? form) (< (elem-cols s w (lt-f-name form)) (lt-f-val form))]
        [else #f]))
;test
;(spelnia (lt-f 'area 600) (list "Warsaw"  "Poland"  517 #t) (table-schema cities))
;(spelnia (lt-f 'area 400) (list "Warsaw"  "Poland"  517 #t) (table-schema cities))
;(spelnia (eq-f 'city "Wroclaw") (list "Warsaw"  "Poland"  517 #t) (table-schema cities))
;(spelnia (eq-f 'city "Warsaw") (list "Warsaw"  "Poland"  517 #t) (table-schema cities))
;(spelnia (eq2-f 'city 'country) (list "Warsaw"  "Poland"  517 #t) (table-schema cities))
;(spelnia (eq2-f 'city 'country) (list "Warsaw"  "Warsaw"  517 #t) (table-schema cities))
;(spelnia (or-f (lt-f 'area 400) (eq-f 'city "Warsaw")) (list "Warsaw"  "Poland"  517 #t) (table-schema cities))
;(spelnia (and-f (lt-f 'area 400) (eq-f 'city "Warsaw")) (list "Warsaw"  "Poland"  517 #t) (table-schema cities))
;(spelnia (not-f (lt-f 'area 400)) (list "Warsaw"  "Poland"  517 #t) (table-schema cities))

(define (table-select form tab)
  (define (it t acc)
    (cond [(null? t) acc]
          [(spelnia form (car t) (table-schema tab)) (it (cdr t) (append acc (car t)))]
          [else (it (cdr t) acc)]))
  (table (table-schema tab) (it (table-rows tab) '()))
  )

; Zmiana nazwy

(define (table-rename col ncol tab)
  (define (it s acc)
    (if (equal? (column-info-name (car s)) col)
        (append acc (list (column-info ncol (column-info-type (car s)))) (cdr s))
        (it (cdr s) (append acc (car s)))))
  (table (it (table-schema tab) '())
         (table-rows tab))
  )

; Złączenie kartezjańskie

(define (kartez_wiersz w t)
  (if (null? t)
      null
      (cons (append w (car t)) (kartez_wiersz w (cdr t)))))

(define (kartez t t2)
  (if (null? t)
      null
      (append (kartez_wiersz (car t) t2) (kartez (cdr t) t2))))

(define (table-cross-join tab1 tab2)
  (table (append (table-schema tab1) (table-schema tab2)) (kartez (table-rows tab1) (table-rows tab2)))
  )

;test
;(table-cross-join cities (table-rename 'country 'country2 countries))

; Złączenie

(define (is-in x s)
  (cond [(null? s) #f]
        [(equal? x (column-info-name (car s))) #t]
        [else (is-in x (cdr s))]))

(define (same s1 s2)
  (cond [(null? s1) null]
        [(is-in (column-info-name (car s1)) s2) (cons (column-info-name (car s1)) (same (cdr s1) s2))]
        [else (same (cdr s1) s2)]))

(define (inne l s acc)
  (cond [(null? l) acc]
        [(not (is-in (car l) s)) (inne (cdr l) s (cons acc (car l)))]
        [else (inne (cdr l) s acc)]))

(define (t-s l t)
  (if (null? l)
      t
      (t-s (cdr l) (table-select(eq2-f (car l)
                                               (string->symbol (string-append (symbol->string (car l)) "<3")))
                                        t))))

(define (t-r l t)
  (if (null? l)
      t
      (t-r (cdr l) (table-rename (car l)
                                 (string->symbol (string-append (symbol->string (car l)) "<3"))
                                 t))))

(define (table-natural-join tab1 tab2)
  (define l (same (table-schema tab1) (table-schema tab2)))
  (table-project (append (table-schema tab1) (inne l (table-schema tab2) '()))
                 (t-s l (table-cross-join tab1 (t-r l tab2))))
  )

;test
(table-natural-join cities countries)
;ten test wyrzuca taki blad
;  cdr: contract violation
;     expected: pair?
;     given: "Wrocław"
;ale nie umiem poprawic table-project tak zeby dzialalo...
;przez co nawet nwm czy tylko w tym tkwi problem...
;aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
;mam dosc! niby mam wszystko a mam tylko 2/13 testow dobrze
;czyli jest tak jakbym nie miala nic!
;i nawet nie wiem co jest zle!!!!!!!!!!!!!
;w dodatku mam 2% i 5% wiec zaraz mi sie wylaczy komputer!!! zycie mnie mnie