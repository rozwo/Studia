#lang racket

(require "streams.rkt")

(define s (stream-cons 1 (map2 * s (integers-from 1))))
;na poczatku w strumieniu musi cos byc
;bo potem sie do czegos odwoluje (wiec na poczatku jest (1 cos))
;bo tam jest mnozenie wiec 0 nie moze byc




;-------testy-------
;(stream-ref s 5)
