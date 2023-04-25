#lang racket

;wystawianie na zewnatrz (program w wielu plikach (abstrakcja danych))
(provide
         mqueue?
         nonempty-mqueue?
         (contract-out ;dzieki temu kontrakty sa sprawdzane tylko na granicy modulow
                       [mqueue-empty? (-> mqueue? boolean?)]
                       [make-mqueue   (-> mqueue?)]
                       [mqueue-push   (-> mqueue? any/c void?)]
                       [mqueue-pop    (-> mqueue? any/c)]
                       [mqueue-join   (-> nonempty-mqueue? nonempty-mqueue? void?)]))

;tworzymy mutowalna strukture
(struct mqueue
  ([front #:mutable]
   [back  #:mutable]))

;umawiamy sie ze pusta kolejka ma null z przodu i z tylu
(define (mqueue-empty? q)
  (and (null? (mqueue-front q))
       (null? (mqueue-back  q))))

;tworzymy pusta kolejke
(define (make-mqueue)
  (mqueue null null))

;XD co to robi?
(define (mqueue-push q x)
  (define p (mcons x null))
  (if (mqueue-empty? q)
      (set-mqueue-front! q p)
      (set-mcdr! (mqueue-back q) p))
  (set-mqueue-back! q p))

(define (nonempty-mqueue? q)
  (and (mqueue? q) (mpair? (mqueue-front q))))

;zdjecie elementu z kolejki
;potrzebujemy kontraktu zeby nie zdejmowac elementu z pustej kolejki
(define/contract (mqueue-pop q)
  (-> nonempty-mqueue? any/c)
  (define p (mqueue-front q))
  (set-mqueue-front! q (mcdr p))
  (if (null? (mcdr p))
      (begin ;begin - wykonuje ciag wyrazen i zwraca wynik ostatniego
        (set-mqueue-back! q null)
        (mcar p))
      (mcar p)))

;laczenie kolejek
;na koniec czyscimy drugą kolejke poniewaz nie chcemy zeby elementy nalezaly do wiecej
;niż 1 kolejki na raz
(define (mqueue-join q1 q2)
  ;przypadki jednej pustej lub obu (nie piszemy)
  (set-mcdr! (mqueue-back q1) (mqueue-front q2))
  (set-mqueue-back! q1 (mqueue-back q2))
  (set-mqueue-front! q2 null)
  (set-mqueue-back!  q2 null))
