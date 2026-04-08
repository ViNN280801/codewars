global reverse_seq
extern malloc

section .text

; int *reverse_seq(int num, size_t *out_size)
; argument 1: edi = num (int, 32-bit)
; argument 2: rsi = out_size (pointer to size_t)
; returns:    rax = pointer to heap-allocated int array, or NULL

reverse_seq:
    ; === Prologue ===
    ; 4 pushes x 8 = 32 + 8 (ret addr) = 40 -- not divisible by 16
    ; sub rsp, 8 adds 8 -> 48, now divisible by 16
    push    rbp             ; save frame pointer (callee-saved)
    push    rbx             ; will store 'num' (callee-saved, survives call)
    push    r12             ; will store 'num_copy' (callee-saved, survives call)
    push    r13             ; will store 'out_size ptr' (callee-saved, survives call)
    sub     rsp, 8          ; align stack to 16 bytes

    mov     ebx, edi        ; rbx = num (int, 32-bit)
    mov     r13, rsi        ; r13 = out_size pointer (save before malloc trashes rsi)

    ; === if (num == 0) return NULL ===
    test    ebx, ebx        ; sets ZF if num == 0
    jz      .return_null

    ; === result = malloc(num * sizeof(int)) ===
    mov     edi, ebx        ; 1st argument to malloc: num
    shl     edi, 2          ; edi *= 4 (sizeof(int) = 4)
    call    malloc          ; rax = malloc(num * 4)
                            ; after call: rbx, r12, r13 intact (callee-saved)

    ; === if (result == NULL) return NULL ===
    test    rax, rax
    jz      .return_null

    mov     r12d, ebx       ; r12 = num_copy (original num, loop bound)

    ; === Fill loop: result[i] = num-- ===
    ; rax = pointer to array
    ; ebx = current num value (decrements each iteration)
    ; ecx = index i (increments each iteration)
    ; r12d = num_copy (fixed loop bound)
    xor     ecx, ecx        ; i = 0

.loop:
    cmp     ecx, r12d       ; if (i >= num_copy) break
    jae     .write_size
    mov     dword [rax + rcx*4], ebx    ; result[i] = num (int = 4 bytes, rcx*4)
    dec     ebx             ; num--
    inc     ecx             ; i++
    jmp     .loop

.write_size:
    mov     qword [r13], r12            ; *out_size = num_copy (size_t = 8 bytes)

    jmp     .done

.return_null:
    xor     eax, eax        ; rax = 0 = NULL

.done:
    ; === Epilogue -- restore in reverse order ===
    add     rsp, 8
    pop     r13
    pop     r12
    pop     rbx
    pop     rbp
    ret

section .note.GNU-stack noalloc noexec nowrite progbits
