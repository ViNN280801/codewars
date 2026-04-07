default rel ; -> PIE (Position Independent Code)

section .rodata
  phrase0 db "I love you"  , 0
  phrase1 db "a little"    , 0
  phrase2 db "a lot"       , 0
  phrase3 db "passionately", 0
  phrase4 db "madly"       , 0
  phrase5 db "not at all"  , 0

section .data
  petal_table dq phrase0, phrase1, phrase2, phrase3, phrase4, phrase5

section .text
global how_much_i_love_you

how_much_i_love_you:
  dec     edi                    ; nb_petals--
  movsxd  rax, edi               ; (int64_t)(nb_petals - 1)
  xor     rdx, rdx               ; rdx = 0
  mov     rcx, 6                 ; idiv=>rax/rcx, rdx=remainder; rcx = 6;
  div    rcx                    ; rax = rax / 6, rdx = rax % 6, where rdx - index
  jns     .done                  ; if rdx >= 0

.done:
  lea     rax, [petal_table]     ; rax = &petal_table
  mov     rax, [rax + rdx*8]     ; rax = &petal_table + index*8, where 8 - sizeof ptr
  ret
