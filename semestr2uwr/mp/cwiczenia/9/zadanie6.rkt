#lang plait

(define-type fragRacket
  (r-zmienna [x : Symbol])
  (r-liczba [n : Number])
  (r-lambda [var : (Listof fragRacket)] [wyr : fragRacket])
  (r-funkcja [f : fragRacket] [var : (Listof fragRacket)])
  (r-let [l : (Listof (fragRacket * fragRacket))] [wyr : fragRacket])
  (r-if [warunek : fragRacket] [t : fragRacket] [f : fragRacket])
  (r-cond [c : (Listof (fragRacket * fragRacket))]))
