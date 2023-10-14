#lang racket
;Róża Wójcicka - pracownia 2 - 4.06.2023
;szablon z pliku circuitsim.rkt

(require data/heap)

;--------------------------------------------------------------------------------------------------------------------------
(provide sim? wire?
         (contract-out
          [make-sim        (-> sim?)]
          [sim-wait!       (-> sim? positive? void?)]
          [sim-time        (-> sim? real?)]
          [sim-add-action! (-> sim? positive? (-> any/c) void?)]

          [make-wire       (-> sim? wire?)]
          [wire-on-change! (-> wire? (-> any/c) void?)]
          [wire-value      (-> wire? boolean?)]
          [wire-set!       (-> wire? boolean? void?)]

          [bus-value (-> (listof wire?) natural?)]
          [bus-set!  (-> (listof wire?) natural? void?)]

          [gate-not  (-> wire? wire? void?)]
          [gate-and  (-> wire? wire? wire? void?)]
          [gate-nand (-> wire? wire? wire? void?)]
          [gate-or   (-> wire? wire? wire? void?)]
          [gate-nor  (-> wire? wire? wire? void?)]
          [gate-xor  (-> wire? wire? wire? void?)]

          [wire-not  (-> wire? wire?)]
          [wire-and  (-> wire? wire? wire?)]
          [wire-nand (-> wire? wire? wire?)]
          [wire-or   (-> wire? wire? wire?)]
          [wire-nor  (-> wire? wire? wire?)]
          [wire-xor  (-> wire? wire? wire?)]

          [flip-flop (-> wire? wire? wire? void?)]))

;--------------------------------------------------------------------------------------------------------------------------
;struktury: sim, wire

;sim - symulacja: czas (current-time), kolejka akcji (action-queue)
(struct sim ([current-time #:mutable] [action-queue #:mutable]) #:transparent)

;wire - przewód: symulacja (do której należy wartość (val), lista akcji, którą wykonuje (actions))
(struct wire ([sim] [val #:mutable] [actions #:mutable]) #:transparent)

;--------------------------------------------------------------------------------------------------------------------------
(define (make-sim) ;tworzy symulacje z pustą kolejką akcji
  (sim 0 (make-heap (lambda (a b) (<= (cdr a) (cdr b)))))) ;(make-heap <=) makes a new empty heap

(define (pom sim max-time)
  (if (= (heap-count (sim-action-queue sim)) 0)
      (void) ;jesli puste to koncz
      (let ([min-pair (heap-min (sim-action-queue sim))])
        (if (< max-time (cdr min-pair))
            (void) ;jesli skonczyl sie czas to koncz
            (begin
              (heap-remove-min! (sim-action-queue sim))
              (set-sim-current-time! sim (cdr min-pair))
              ((car min-pair))
              (pom sim max-time)))))) ;jak nie to rob i reszta
  
(define (sim-wait! sim time) ;wykonujesz akcje az czas bedzie jak czas poczatkowy + t
    (pom sim (+ time (sim-time sim))))

(define (sim-time sim) (sim-current-time sim)) ;zwraca czas

;heap = (pary czas akcja)
(define (sim-add-action! sim delay action) ;dodaje akcje do kolejki
  (heap-add! (sim-action-queue sim) (cons action (+ delay (sim-time sim))))) ;(heap-add! h v) adds each v to the heap

;--------------------------------------------------------------------------------------------------------------------------
(define (make-wire sim) (wire sim #f '())) ;#f - wartosc, pusta lista akcji

(define (wire-on-change! wire action) ;dodajesz do listy akcji daną akcję ;troche jak add-action! z podrecznika
  (begin
    (set-wire-actions! wire (cons action (wire-actions wire)))
    (sim-add-action! (wire-sim wire) (cdr action) (car action))))

(define (wire-value wire)
  (wire-val wire))

(define (call-action actions sim) ;funkcja pomocnicza do wire-set!
  (if (null? actions)
      (void)
      (begin ;(heap-add! h v) adds each v to the heap
        (heap-add! (sim-action-queue sim) (cons (car (car actions)) (+ (cdr (car actions)) (sim-time sim))))
        (call-action (cdr actions) sim))))

(define (wire-set! wire state) ;jesli wartosc sie zmienila wywoluja akcje przewodu (odpalenie każdej z nich) ;troche jak set-signal! z podrecznika
  (if (eq? state (wire-val wire))
      (void) ;funkcja ktora nic nie robi
      (begin
        (set-wire-val! wire state)
        (call-action (wire-actions wire) (wire-sim wire)))))

;--------------------------------------------------------------------------------------------------------------------------

(define (bus-set! wires value)
  (match wires
    ['() (void)]
    [(cons w wires)
     (begin
       (wire-set! w (= (modulo value 2) 1))
       (bus-set! wires (quotient value 2)))]))

(define (bus-value ws)
  (foldr (lambda (w value) (+ (if (wire-value w) 1 0) (* 2 value)))
         0
         ws))

;--------------------------------------------------------------------------------------------------------------------------
;Czas po jakim po zmianie wejścia bramki zmieni się jej wyjście powinien wynosić 1
;dla wszystkich bramek, oprócz alternatywy wykluczającej (XOR), dla której ten czas wynosi 2.
(define not-delay 1)
(define and-delay 1)
(define nand-delay 1)
(define or-delay 1)
(define nor-delay 1)
(define xor-delay 2)

(define (gate-not output input) ;troche jak inverter z podrecznika
  (define not-action
    (lambda ()
      (wire-set! output (not (wire-val input)))))
  (begin (wire-on-change! input (cons not-action not-delay))))

(define (gate-and output a1 a2) ;troche jak and-gate z podrecznika
  (define and-action
    (lambda ()
      (wire-set! output (and (wire-val a1) (wire-val a2)))))
  (begin
    (wire-on-change! a1 (cons and-action and-delay))
    (wire-on-change! a2 (cons and-action and-delay))))

;pozostale analogicznie do poprzednich

(define (gate-nand output a1 a2)
  (define nand-action
    (lambda ()
      (wire-set! output (not (and (wire-val a1) (wire-val a2))))))
  (begin
    (wire-on-change! a1 (cons nand-action nand-delay))
    (wire-on-change! a2 (cons nand-action nand-delay))))

(define (gate-or output a1 a2)
  (define or-action
    (lambda ()
      (wire-set! output (or (wire-val a1) (wire-val a2)))))
  (begin
    (wire-on-change! a1 (cons or-action or-delay))
    (wire-on-change! a2 (cons or-action or-delay))))

(define (gate-nor output a1 a2)
  (define nor-action
    (lambda ()
      (wire-set! output (not (or (wire-val a1) (wire-val a2))))))
  (begin
    (wire-on-change! a1 (cons nor-action nor-delay))
    (wire-on-change! a2 (cons nor-action nor-delay))))

(define (gate-xor output a1 a2)
  (define xor-action
    (lambda ()
      (wire-set! output (xor (wire-val a1) (wire-val a2)))))
  (begin
    (wire-on-change! a1 (cons xor-action xor-delay))
    (wire-on-change! a2 (cons xor-action xor-delay))))
;--------------------------------------------------------------------------------------------------------------------------
;tworzysz nowy przewod, łaczysz podane z tym bramką (! bramka przyjmuje out in (in))
(define (wire-not input)
  (define wire-output (make-wire (wire-sim input)))
  (begin (gate-not wire-output input) wire-output))

(define (wire-and a1 a2)
  (define wire-output (make-wire (wire-sim a1)))
  (begin (gate-and wire-output a1 a2) wire-output))

(define (wire-nand a1 a2)
  (define wire-output (make-wire (wire-sim a1)))
  (begin (gate-nand wire-output a1 a2) wire-output))

(define (wire-or a1 a2)
  (define wire-output (make-wire (wire-sim a1)))
  (begin (gate-or wire-output a1 a2) wire-output))

(define (wire-nor a1 a2)
  (define wire-output (make-wire (wire-sim a1)))
  (begin (gate-nor wire-output a1 a2) wire-output))

(define (wire-xor a1 a2)
  (define wire-output (make-wire (wire-sim a1)))
  (begin (gate-xor wire-output a1 a2) wire-output))
;--------------------------------------------------------------------------------------------------------------------------

(define (flip-flop out clk data)
  (define sim (wire-sim data))
  (define w1  (make-wire sim))
  (define w2  (make-wire sim))
  (define w3  (wire-nand (wire-and w1 clk) w2))
  (gate-nand w1 clk (wire-nand w2 w1))
  (gate-nand w2 w3 data)
  (gate-nand out w1 (wire-nand out w3)))
