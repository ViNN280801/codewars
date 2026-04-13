; =============================================================
; Описание: данный файл нужен для реализации задач на NASM
; Платформа: x86-64 Linux (System V AMD64 ABI)
; Компиляция: nasm -f elf64 file.asm -o file.o
; =============================================================

; ---- external symbols ----
; -------------------------

; ---- exporting symbols ----
global double_it
global is_even
global abs_val
global max_of_two
global sum_array
global count_char
global is_power_of_two
global fib
global str_len
global make_squares
; ---------------------------

; ---- constants ----
; BUFFER_SIZE equ 256
; -------------------

; ---- read-only section ----
section .rodata
; ---------------------------

; ---- initilized data section ----
section .data
; ---------------------------------

; ---- uninitialized data section (do not get space in file) ----
section .bss
; ---------------------------------------------------------------

section .text

; ==== Task 1 ====
; global double_it
; int double_it(int n)
; Верни n * 2.
; Подсказка: умножение на 2 можно выразить
; одной битовой операцией без imul.
; ===== ==== =====

; -------------------------------------------------------------
; Сигнатура: int double_it(int n)
; Аргументы: edi = n
; Возврат:   eax = результат
; Детали:    используем регистры с префиксом "e", потому что они 32 битные, int = 4 байта на x64
; -------------------------------------------------------------
double_it:
  ; Используем загрузку эффективного адреса, чтобы не менять пришедший аргумент
  ; "Эффективный адрес" - это просто вычисленное число по формуле [base+index*scale+displacement]
  ;   base - любой регистр общего назначения
  ;   index - любой регистр кроме rsp
  ;   scale - 1, 2, 4, или 8 (для элементов 1/2/4/8 байт)
  ;   displacement - константа (8 или 32 бита
  lea eax, [edi + edi] ; говорим "вычисли edi+edi и положи результат в eax"
  ret                  ; возвращаем поток управления

; ==== Task 2 ====
; global is_even
; int is_even(int n)
; Верни 1 если n чётное, 0 если нечётное.
; Подсказка: проверь самый младший бит через AND.
; Затем инвертируй результат.
; ===== ==== =====

; -------------------------------------------------------------
; Сигнатура: int is_even(int n)
; Аргументы: edi = n
; Возврат:   eax = результат
; Реал. С:   на С реализация выглядела бы как return n & 1
; -------------------------------------------------------------
is_even:
  ; Идея: перекладываем значение из входного аргумента edi в результатовый eax
  ;       применяем побитовое И с 1, как в С
  ;       применяем исключающее ИЛИ (XOR) с 1, потому что:
  ;                                                         0 xor 0 = 0
  ;                                                         0 xor 1 = 1
  ;                                                         1 xor 0 = 1
  ;                                                         1 xor 1 = 0
  ;       следовательно, берем xor именно с 1: 0 xor 1 = 1; 1 xor 1 = 0, поэтому,
  ;       если в eax будет лежать 0, то станет 1, если 1, то 0.
  mov eax, edi
  and eax, 1
  xor eax, 1
  ret

; ==== Task 3 ====
; global abs_val
; int abs_val(int n)
; Верни |n|.
; Подсказка: если n < 0 - нужно его отрицать (neg).
; Используй cmp и условный переход.
; ===== ==== =====

; -------------------------------------------------------------
; Сигнатура: int abs_val(int n)
; Аргументы: edi = n
; Возврат:   eax = результат
; Реал. С:   на С реализация выглядела бы как return (n >= 0) ? n : -n; или return (n < 0) ? -n : n;
; -------------------------------------------------------------
abs_val:
  cmp edi, 0          ; сравниваем edi с нулем, чтобы установить все флаги
  jl  .abs_val_negate ; jump if lower (SF!=OF) => (Sign Flag != Overflow Flag), т.е. старший бит = 0 != нет знакового переполнения
  jmp .abs_val_done

  .abs_val_negate:
    neg edi   ; добавляем унарный - к edi
    jmp .abs_val_done

  .abs_val_done:
    mov eax, edi ; записываем результат в eax
    ret

; ==== Task 4 ====
; global max_of_two
; int max_of_two(int a, int b)
; Верни максимум из двух чисел.
; a приходит в edi, b приходит в esi.
; Подсказка: cmp + cmov (без явного jmp!).
; ===== ==== =====
max_of_two:
  mov    eax, esi   ; перемещаем 2-й аргумент в результат
  cmp    eax, edi   ; edi - 1-й аргумент, esi - 2-й аргумент; сравниваем их
  cmovl  eax, edi   ; if (eax < edi)  eax = edi
  ret

; ==== Task 5 ====
; global sum_array
; int sum_array(const int *arr, int n)
; Верни сумму всех элементов массива.
; arr в rdi, n в esi.
; Подсказка: цикл с dec + jnz,
; читай элементы через [rdi + rcx*4].
; ===== ==== =====
sum_array:
  xor eax, eax    ; eax = 0, выступает в качестве аккумулятора (итоговой суммы)
  xor ecx, ecx    ; ecx = 0, выступает в роли счетчика по циклу

  test rdi, rdi       ; if (rdi == NULL) -> exit
  jz  .sum_array_end

  test esi, esi          ; if (esi <= 0) -> exit
  jle  .sum_array_end

  .sum_array_loop:
    cmp ecx, esi        ; сравниваем ecx и esi, где esi - второй аргумент, он же размер массива
    jge .sum_array_end  ; if (ecx >= esi) -> выход

    add eax, [rdi + rcx * 4] ; eax += [rdi + rcx*4], 4 потому что sizeof(int) на x64 = 4 байта
    inc ecx                  ; ++ecx
    jmp .sum_array_loop      ; переходим на начало цикла

  .sum_array_end:
    ret

; ==== Task 6 ====
; global count_char
; int count_char(const char *str, char c)
; Посчитай сколько раз символ c встречается в строке str.
; str в rdi, c в sil (8-bit часть rsi).
; Подсказка: итерируй как в bin_to_dec,
; сравнивай текущий байт с sil через cmp.
; ===== ==== =====
count_char:
  xor eax, eax  ; обнуляем результирующий регистр eax
  xor rcx, rcx  ; обнуляем регистр счетчика rcx

  test rdi, rdi         ; если в rdi был передан нулевой адрес - выходим из функции
  jz   .count_char_end

  .count_char_loop:
    movzx edx, byte [rdi + rcx]        ; читаем 1 байт в edx
    test  edx, edx                     ; проверяем *rdi+rcx, что он не '\0'
    jz    .count_char_end              ; если '\0' - выходим
    inc   rcx                          ; инкрементируем счетчик цикла
    cmp   dl, sil                      ; сравниваем байт dl с переданным sl (char c)
    jne   .count_char_skip             ; если *rdx+rcx != rsi, то пропускаем шаг
    inc   eax                          ; иначе инкрементируем результат

  .count_char_skip:
    jmp .count_char_loop ; делаем петлю для цикла

  .count_char_end:
    ret   ; возвращаем поток управления

; ==== Task 7 ====
; global is_power_of_two
; int is_power_of_two(unsigned int n)
; Верни 1 если n является степенью двойки, иначе 0.
; Подсказка: степень двойки имеет ровно один бит.
; Классический трюк: n & (n-1) == 0.
; Также n не должно быть равно 0.
; ===== ==== =====
is_power_of_two:
  xor  eax, eax                 ; eax = 0
  test edi, edi                 ; если edi <= 0, то выходим из функции
  jle  .is_power_of_two_lezero

  lea  ecx, [edi-1]  ; ecx = edi-1
  and  edi, ecx      ; edi & ecx => edi & (edi-1)
  test edi, edi      ; установка флагов для edi
  setz al            ; если ZF=1, то устанавливаем 1 бит в al
  ret

  .is_power_of_two_lezero:
    ret

; ==== Task 8 ====
; global fib
; long long fib(int n)
; Верни n-е число Фибоначчи (fib(0)=0, fib(1)=1).
; Подсказка: тебе нужны два регистра для
; предыдущего и текущего значения.
; Используй loop или dec + jnz.
; Не используй рекурсию.
; ===== ==== =====
fib:
  cmp  edi, 1      ; if (edi <= 1) -> goto .fib_leone
  jle  .fib_leone

  push r12 ; prev
  push r13 ; cur
  push r14 ; next

  xor r12, r12  ; prev = 0
  mov r13, 1    ; cur  = 1
                ; r14 is next

  mov ecx, 1    ; i = 1

  .fib_loop:
    lea r14, [r12 + r13] ; next = prev + cur
    mov r12, r13         ; prev = cur
    mov r13, r14         ; cur  = next

    inc ecx   ; ++i

    cmp ecx, edi   ; if (ecx <= edi) -> goto .fib_loop
    jle .fib_loop

  mov rax, r13   ; rax = cur

  pop r12
  pop r13
  pop r14

  ret

  .fib_leone:
    movsxd rax, edi   ; rax = edi with sing extend
    ret

; ==== Task 9 ====
; global str_len
; size_t str_len(const char *str)
; Верни длину строки без нулевого терминатора.
; Аналог strlen из libc.
; Подсказка: структура почти идентична bin_to_dec -
; итерируй по байтам пока не встретишь 0.
; Считай количество байт до нуля.
; ===== ==== =====
str_len:
  xor   rax, rax      ; rax = 0

  .str_len_loop:
    movzx rdx, byte [rdi + rax] ; читаем один байт строки в edx: rdx = *(rdi + counter)
    test  rdx, rdx              ; if (rcx == 0) -> break loop
    jz   .str_len_end
    inc  rax                    ; ++rax (counter)
    test rcx, rcx               ; if (rcx != 0) -> goto begin of loop  
    jne  .str_len_loop

  .str_len_end:
    ret

; ==== Task 10 ====
; global make_squares
; int *make_squares(int n, size_t *out_size)
; Выдели массив из n элементов через malloc.
; Заполни его квадратами: result[i] = (i+1)*(i+1).
; Запиши n в *out_size.
; Верни указатель или NULL если n <= 0.
; Подсказка: структура почти идентична Reversed sequence —
; те же пролог/эпилог с callee-saved регистрами,
; тот же паттерн с malloc и проверкой NULL.
; Для квадрата используй imul.
; ===== ==== =====

section .note.GNU-stack noalloc noexec nowrite progbits
