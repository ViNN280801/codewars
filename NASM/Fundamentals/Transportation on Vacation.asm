global rental_car_cost

section .text

rental_car_cost:
    imul eax, edi, 40 ; cost = days * 40
    cmp edi, 7        ; if days >= 7
    jge .L1           ; goto .L1
    cmp edi, 3        ; if days >= 3
    jge .L2           ; goto .L2
    ret               ; else -> result will be in eax as days * 40

.L1:
  sub eax, 50
  ret

.L2:
  sub eax, 20
  ret

