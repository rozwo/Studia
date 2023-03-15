#lang racket

; cytowanie list i stałych

(list 1 2 3)
; '(1 2 3)

'1
; 1

'#t
; #t

; symbole

'list
; 'list

list
; #<procedure:list>

'null ; uwaga: słowo null to też symbol
; 'null

symbol?
; #<procedure:symbol?>

(symbol? 'abc)
; #t

(string->symbol "abc")
; 'abc

; forma specjalna quote

(quote list)
; 'list

; (quote 1 2 3)
; quote: bad syntax in: (quote 1 2 3)

(define x (list 1 2 3))
(quote x)
; 'x

(quote (1 2 3))
; '(1 2 3)

; cytowanie list

'(1 2 3)
; '(1 2 3)

(list 1 2 3)
; '(1 2 3)

'(1 2 (3 4))
; '(1 2 (3 4))

(list 1 2 (list 3 4))
; '(1 2 (3 4))

'(1 2 (3 4))
; '(1 2 (3 4))

(list '1 '2 '(3 4))
; '(1 2 (3 4))

(list 1 2 (list 3 4))
; '(1 2 (3 4))

(list 1 2 '(3 4))
; '(1 2 (3 4))

(equal? '(1 2 (3 4)) (list 1 2 (list 3 4)))
; #t

; notacja z kropką

(cons 1 2)
; '(1 . 2)

(cons 0 (cons 1 2))
; '(0 1 . 2)

'(0 1 . 2)
; '(0 1 . 2)

'(0 1 . ())
; '(0 1)

; '(0 1 . 2 3)
; read-syntax: illegal use of `.`

'(0 1 . (2 3))
; '(0 1 2 3)

; procedury eq? i equal?

eq?
; #<procedure:eq?>

equal?
; #<procedure:equal?>

(equal? '(1 2) '(1 2))
; #t

(eq? '(1 2) '(1 2))
; #f

(eq? '() '())
; #t

(eq? 1 1)
; #t

(eq? 'abc 'abc)
; #t

(eq? "abc" "abc")
; #t

(make-string 3 #\a)
; "aaa"

(eq? "aaa" (make-string 3 #\a))
; #f

(equal? "aaa" (make-string 3 #\a))
; #t

(eq? "aaa" (make-string 3 #\a))
; #f

(string->symbol "aaa")
; 'aaa

'aaa
; 'aaa

(equal? (string->symbol "aaa") 'aaa)
; #t

(eq? (string->symbol "aaa") 'aaa)
; #t

; kwazicytowania

`()
; '()

`(1 2 3)
; '(1 2 3)

`(1 2 3 4 5 . 6)
; '(1 2 3 4 5 . 6)

`(1 2 ,list)
; '(1 2 #<procedure:list>)

`(1 2 ,(+ 1 2))
; '(1 2 3)

`(1 2 (+ 1 2))
; '(1 2 (+ 1 2))

`(1 2 ,(list 1 '(+ 2 3)))
; '(1 2 (1 (+ 2 3)))

`(1 2 ,(list 1 `(+ 2 3)))
; '(1 2 (1 (+ 2 3)))

`(1 2 ,(list 1 `(+ 2 ,(- 3 2))))
; '(1 2 (1 (+ 2 1)))

(quasiquote 1)
; 1

(quasiquote (unquote (+ 2 2)))
; 4

`,(+ 2 2)
; 4

'`(1 2)
; '`(1 2)

(car '`(1 2))
; 'quasiquote

(car ',(1 2))
; 'unquote

(car ',`(1 2))
; 'unquote

',`(1 2)
; ',`(1 2)

',,,,,(1 2)
; ',,,,,(1 2)

; ,,,,,(1 2)
; unquote: not in quasiquote in: (unquote (unquote (unquote (unquote (unquote (1 2))))))

; `,,,,,(1 2)
; unquote: not in quasiquote in: (unquote (unquote (unquote (unquote (1 2)))))

; '`,,,,,(1 2)
'`,,,,,(1 2)
