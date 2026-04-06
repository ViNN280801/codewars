global bin_to_dec

section .text

bin_to_dec:
    xor rax, rax
    jmp .loop

.loop:
  movzx   ecx, byte [rdi]   ; init ptr on rdi with zero extend
  test    ecx, ecx          ; if (*ptr == 0) break

  jz      .loop_end

  ; Gorner's method:
  ; unsigned bin_to_dec(const char *bin) {
  ;   unsigned result = 0;
  ;   while (*bin != '\0') {
  ;     result = result * 2 + (*bin - '0');
  ;     bin++;
  ;   }
  ;   return result;
  ; }
  sub     ecx, 0h30         ; ecx = *bin - '0'
  shl     rax, 1            ; rdx = result << 1 <=> rdx = result * 2
  add     rax, rcx          ; rdx = rdx + ecx
  inc     rdi               ; bin++
  jmp     .loop             ; making loop

.loop_end:
  ret
