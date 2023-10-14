#lang racket

;zadanie 1
;zdefiniuj procedurę cycle!, która zapętla listę mutowalną,
;czyli przepina wskaźnik ogona ostatniego elementu na początek listy

(define (cycle! xs)
  ;lista mutowalna to lista par np: (mcons 1 (mcons 2 ...(mcons 6 '()))))))
  (define (list-na-listmut xs)
    (if (null? xs)
        null
        (mcons (car xs) (list-na-listmut (cdr xs)))))
  ;na przyklad (mcons 6 '()) ;gdzie '() oznacza koniec listy
  (define (ostatnia-para xs)
    (if (null? (mcdr xs))
        xs
        (ostatnia-para (mcdr xs))))
  ;funkcja zmien-wskaznik bierze liste mutowalna jej ostatnia pare
  ;i '() zmienia na xs a pozniej wypisuje xs
  ; wtedy przykladowa lista: #0=(mcons 1 (mcons 2 ...(mcons 6 #0#))))))
  (define (zmien-wskaznik xs)
    (set-mcdr! (ostatnia-para xs) xs)
    xs)
    
  (zmien-wskaznik (list-na-listmut xs)))

;test
;(cycle! (list 1 2 3 4 5 6))

;zadanie 2
;zdefiniuj procedurę mreverse!, która odwraca listę mutowalną „w miejscu”,
;czyli nie tworzy nowych bloczków mcons-em, a odpowiednio przepina wskaźniki

;mreverse z mcons-em
#;(define (mreverse! xs)
  (define (it xs acc)
    (if (null? xs)
        acc
        (it (mcdr xs) (mcons (mcar xs) acc))))
  (it xs '()))

(define (mreverse! xs)
  (define (it xs prev)
    (cond [(null? xs) prev] ;xs to null
          [(null? (mcdr xs)) (set-mcdr! xs prev) xs] ;jesteśmy na ostatnim elem
          [else (let ([tmp (mcdr xs)]) ;tmp to wskaźnik na kolejny elem
                  (set-mcdr! xs prev) ;ustawiamy wskaźnik na poprzeni elem
                  (it tmp xs))])) ;przechodzimy do kolejnego elem,
                                   ;tym razem prev to wskaźnik na fragment odwróconej listy xs
  (it xs null))


;test
;(define l1 (mcons 1 (mcons 2 (mcons 3 (mcons 4 (mcons 5 (mcons 6 '())))))))
;(mreverse! l1)