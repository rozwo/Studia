#lang racket

(define (pot x) (* x x))

(define (? a b c) (cond [(and(> a b)(> c b))(+ (pot a)(pot c))]
                        [(and(> a c)(> b c))(+ (pot a)(pot b))]
                        [else (+ (pot b)(pot c))]))
(require rackunit)
(check-equal? (pot 5) 25)
(check-equal? (pot 123) 15129)
(check-equal? (? 2 3 4) 25)
(check-equal? (? 3 2 4) 25)
(check-equal? (? 4 3 2) 25)
