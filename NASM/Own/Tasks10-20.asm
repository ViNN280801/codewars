global gcd

; ==== Task 1 ====
; global gcd
; int gcd(int a, int b)
; Найди наибольший общий делитель двух чисел (алгоритм Евклида).
; Подсказка: используй цикл с вычитанием или делением (idiv).
; Учти, что gcd(n, 0) = |n|.
; ===== ==== =====

; -------------------------------------------------------------
; Сигнатура: int gcd(int a, int b)
; Аргументы: edi = a, esi = b
; Возврат:   eax = результат
; Детали:    32-битные целые со знаком. Используй edx для остатка от idiv.
; -------------------------------------------------------------
gcd:
  test edi, edi
  jns  .gcd_abs_b
  neg edi

  .gcd_abs_b:
    test esi, esi
    jns  .gcd_begin
    neg  esi

  .gcd_begin:
    test edi, edi    ; if (a == 0) rax = b; ret
    jz   .gcd_ret_a
    test esi, esi    ; if (b == 0) rax = a; ret
    jz   .gcd_ret_b
    cmp  edi, esi    ; if (a == b) rax = a; ret
    je   .gcd_ret_a
    jg   .gcd_agb
    jl   .gcd_alb
    ret

    .gcd_agb:
      sub edi, esi   ; a -= b
      jmp .gcd_begin

    .gcd_alb:
      sub esi, edi   ; b -= a
      jmp .gcd_begin

    .gcd_ret_a:
      mov eax, edi
      ret

    .gcd_ret_b:
      mov eax, esi
      ret

; Clang's 22.1.0 -O2 std::gcd analysis and reverting to C code:
std_gcd(int, int):
        ; Used registers:
        ;   r8d - temp variable to interoperate with result
        ;   ecx - variable for the ctz result
        ;   edx - second variable for the ctz result

        mov     r8d, edi        ; r8d = edi => r8d = a => 5th arg (System V) 32 bit
        neg     r8d             ; r8d = -r8d
        cmovs   r8d, edi        ; if (edi is signed (SF=1)) => r8d = edi => r8d = a; r8d = (edi < 0) ? edi : r8d; r8d = (a < 0) ? a : r8d;
        mov     eax, esi        ; eax (result register) = esi => eax = b
        neg     eax             ; eax = -eax
        cmovs   eax, esi        ; if (esi is signed (SF=1)) => eax = esi => eax = a; eax = (SF=1) ? esi : eax; eax = (esi < 0) ? esi : eax;
        test    edi, edi        ; edi & edi => a & a
        je      .LBB0_6         ; if (edi == 0) => if (a == 0) -> goto .LBB0_6
        test    esi, esi        ; esi & esi => b & b
        je      .LBB0_2         ; if (esi == 0) => if (b == 0) -> goto .LBB0_2
        rep       bsf edi, edi  ; edi = ctz(edi) => edi = trailing zeros count in edi (a)
        mov     ecx, edi        ; ecx = edi => ecx = a; ecx is a 4th arg (loop counter)
        shr     r8d, cl         ; r8d >>= cl (1 byte register); shr -> shift right <-> div to 2
        rep       bsf edx, esi  ; edx = ctz(esi) => edx = ctz(b)
        mov     ecx, edx        ; ecx = edx
        shr     eax, cl         ; eax >>= cl
        cmp     edi, edx        ; comparing edi with edx
        cmovb   edx, edi        ; edx = (CF=1) ? edi : edx; b - means below; edx = (edx < edi) ? edi : edx;
        cmp     r8d, eax        ; comparing r8d with eax
.LBB0_4:
        mov     esi, eax        ; esi = eax; b = eax
        cmovb   esi, r8d        ; using result of comparing `cmp r8d, eax`; esi = (esi < r8d) ? r8d : esi => b = (b < r8d) ? r8d : b
        je      .LBB0_5         ; if (r8d == eax) goto .LBB0_5
        cmp     r8d, eax        ; comparing r8d with eax
        cmova   eax, r8d        ; eax = (eax > r8d) ? r8d : eax
        mov     r8d, esi        ; r8d = esi; r8d = b
        sub     eax, esi        ; eax -= esi; eax -= b
        rep       bsf ecx, eax  ; ecx = ctz(eax)
        shr     eax, cl         ; eax >>= cl
        cmp     esi, eax        ; comparing esi (aka `b`) with eax
        jmp     .LBB0_4         ; goto .LBB0_4 (.LBB0_4 is a loop while)
.LBB0_5:
        mov     ecx, edx        ; ecx = edx
        shl     esi, cl         ; esi <<= cl => b <<= cl
        mov     eax, esi        ; eax = esi  => eax = b
.LBB0_6:
        ret                     ; end of the control flow for this function
.LBB0_2:
        mov     eax, r8d        ; eax = r8d
        ret                     ; end of the control flow for this function


; C level 1 reversing: https://godbolt.org/z/13cq57z34
; C level 2 upgrading: https://godbolt.org/z/1bjYe9sdd

; ==== Task 2 ====
; global popcount
; unsigned int popcount(unsigned int n)
; Верни количество установленных битов (population count).
; Подсказка: классический трюк n &= (n-1) в цикле, или сдвиги с проверкой CF.
; ===== ==== =====

; -------------------------------------------------------------
; Сигнатура: unsigned int popcount(unsigned int n)
; Аргументы: edi = n
; Возврат:   eax = результат
; Детали:    беззнаковое 32-битное число. eax используется как счётчик бит.
; -------------------------------------------------------------
popcount:
  ; TODO: реализовать
  ret


; ==== Task 3 ====
; global sum_64
; long long sum_64(const long long *arr, int n)
; Верни сумму элементов массива 64-битных целых чисел.
; Подсказка: шаг итерации 8 байт, аккумулятор должен быть 64-битным.
; ===== ==== =====

; -------------------------------------------------------------
; Сигнатура: long long sum_64(const long long *arr, int n)
; Аргументы: rdi = arr (указатель), esi = n
; Возврат:   rax = результат
; Детали:    long long = 8 байт. Используй rax для суммы, rcx для индекса.
;            Доступ к элементу: [rdi + rcx*8]
; -------------------------------------------------------------
sum_64:
  ; TODO: реализовать
  ret


; ==== Task 4 ====
; global sqrt_newton
; double sqrt_newton(double num)
; Вычисли квадратный корень методом Ньютона-Рафсона с точностью 1e-7.
; Подсказка: начальное приближение x = num/2.0; x = 0.5 * (x + num/x).
; Повторяй пока |x*x - num| > epsilon.
; ===== ==== =====

; -------------------------------------------------------------
; Сигнатура: double sqrt_newton(double num)
; Аргументы: xmm0 = num (System V ABI передаёт double в xmm0)
; Возврат:   xmm0 = результат
; Детали:    Используй инструкции xmm: subsd, mulsd, divsd, addsd.
;            Для абсолютного значения используй andnpd с маской знака или fabs-like логику.
; -------------------------------------------------------------
sqrt_newton:
  ; TODO: реализовать
  ret


; ==== Task 5 ====
; global mean_long_double
; long double mean_long_double(const long double *arr, int n)  (* задача со звёздочкой)
; Вычисли среднее арифметическое массива long double.
; Подсказка: в Linux x86-64 long double обычно 80-bit (x87) или 128-bit (xmm).
; Для портативности используй x87 FPU: fld, fadd, fidiv, fstp.
; ===== ==== =====

; -------------------------------------------------------------
; Сигнатура: long double mean_long_double(const long double *arr, int n)
; Аргументы: rdi = arr, esi = n
; Возврат:   xmm0 (или st0) = результат
; Детали:    x87 FPU работает со стеком регистров st0..st7.
;            Загрузка: fld tbyte [rdi + rcx*10] (или *16 если выровнено).
;            Деление: fidiv esi. Сохранение: fstp qword [rsp] -> movq xmm0, [rsp].
;            Не забудь выровнять стек, если будешь вызывать libc.
; -------------------------------------------------------------
mean_long_double:
  ; TODO: реализовать
  ret


; ==== Task 6 ====
; global swap_via_stack
; void swap_via_stack(int *a, int *b)
; Поменяй местами значения по двум указателям, используя стек для временной переменной.
; Подсказка: push/pop или работа через [rsp].
; ===== ==== =====

; -------------------------------------------------------------
; Сигнатура: void swap_via_stack(int *a, int *b)
; Аргументы: rdi = a, rsi = b
; Возврат:   нет (void)
; Детали:    Демонстрация работы со стеком. Выдели место через sub rsp, 4 или используй push/pop.
;            Не забудь восстановить rsp перед ret.
; -------------------------------------------------------------
swap_via_stack:
  ; TODO: реализовать
  ret


; ==== Task 7 ====
; global reverse_inplace
; void reverse_inplace(char *str)
; Разверни null-terminated строку на месте (in-place).
; Подсказка: два указателя (начало/конец), сдвигай их к центру, меняй байты местами.
; ===== ==== =====

; -------------------------------------------------------------
; Сигнатура: void reverse_inplace(char *str)
; Аргументы: rdi = str
; Возврат:   нет
; Детали:    Найди конец строки (пока != 0), затем цикл while (begin < end).
;            Для обмена используй стек, r8/r9 или xchg byte [rdi], [rsi].
; -------------------------------------------------------------
reverse_inplace:
  ; TODO: реализовать
  ret


; ==== Task 8 ====
; global find_max_ptr
; const int* find_max_ptr(const int *arr, int n)
; Верни указатель на максимальный элемент массива. Если n <= 0, верни NULL.
; Подсказка: храни указатель на текущий максимум в регистре (например, r8).
; ===== ==== =====

; -------------------------------------------------------------
; Сигнатура: const int* find_max_ptr(const int *arr, int n)
; Аргументы: rdi = arr, esi = n
; Возврат:   rax = указатель на максимум или NULL
; Детали:    Сравнивай значения, а не указатели. При обновлении максимума сохраняй адрес.
;            Проверка n <= 0 обязательна в начале.
; -------------------------------------------------------------
find_max_ptr:
  ; TODO: реализовать
  ret


; ==== Task 9 ====
; global stack_local_array_sum
; int stack_local_array_sum(int n)
; Выдели массив из n int на стеке, заполни его квадратами индексов (0..n-1), верни сумму.
; Подсказка: sub rsp, n*4. Обеспечь выравнивание стека до 16 байт перед любыми вызовами (and rsp, -16).
; ===== ==== =====

; -------------------------------------------------------------
; Сигнатура: int stack_local_array_sum(int n)
; Аргументы: edi = n
; Возврат:   eax = сумма
; Детали:    Демонстрация работы с локальным стековым кадром.
;            Доступ к i-му элементу: [rsp + rcx*4].
;            Суммируй в eax, затем восстанови rsp (add rsp, size) перед ret.
; -------------------------------------------------------------
stack_local_array_sum:
  ; TODO: реализовать
  ret


; ==== Task 10 ====
; global find_min_max
; void find_min_max(const int *arr, int n, int *min_out, int *max_out)
; Найди минимальный и максимальный элемент массива, запиши их по указателям.
; Подсказка: используй callee-saved регистры (rbx, r12-r15) для хранения текущих min/max.
; Обязательно сделай пролог/эпилог (push/pop).
; ===== ==== =====

; -------------------------------------------------------------
; Сигнатура: void find_min_max(const int *arr, int n, int *min_out, int *max_out)
; Аргументы: rdi = arr, esi = n, rdx = min_out, rcx = max_out
; Возврат:   нет
; Детали:    System V ABI требует сохранения rbx, r12, r13, r14, r15 при использовании.
;            Проверка NULL для min_out/max_out не требуется по условию, но n <= 0 -> выход.
;            Запись результатов: mov [rdx], ebx / mov [rcx], r12d
; -------------------------------------------------------------
find_min_max:
  ; TODO: реализовать
  ret

section .note.GNU-stack noalloc noexec nowrite progbits

