#include <stdio.h>

size_t get_strarr_size(char const *strings[]);

void print_strarr(char const *strs[])
{
    size_t size = get_strarr_size(strs);
    for (size_t i = 0ul; i < size; ++i)
        printf("%s\n", strs[i]);
}

#include <stdlib.h>
#include <string.h>

int cmp_str_by_len(void const *a, void const *b)
{
    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;
    return strlen(str_a) - strlen(str_b);
}

void swap_strs(char const **a, char const **b)
{
    char const *tmp = *a;
    *a = *b;
    *b = tmp;
}

size_t get_strarr_size(char const *strings[])
{
    if (!strings || !strings[0])
        return 0ul;
    size_t size = 0;
    while (strings[size] != NULL)
        size++;
    return size;
}

void sort_by_length(char const *strings[])
{
    if (!strings || !strings[0])
        return;

    size_t strarr_size = get_strarr_size(strings);
    if (strarr_size == 0ul)
        return;
    for (size_t i = 0ul; i < strarr_size; ++i)
        for (size_t j = i + 1ul; j < strarr_size; ++j)
            if (cmp_str_by_len(&strings[i], &strings[j]) > 0)
                swap_strs(&strings[i], &strings[j]);
}

int main()
{
    char const *strs[] = {"htrctymvoonv", "gxnelwtnduxlssiqxa", "", "zgwsiprulhkaeqyrujpn", "ysk", "vdennvlqwtmocbhwmqhnuzn", "muwdjwyvrdafrxsjtlvjpwtmljvag", "unsqlxchvxazzhsybbtnydewyshh", NULL};
    printf("Before sort:\n");
    print_strarr(strs);
    sort_by_length(strs);
    printf("\nAfter sort:\n");
    print_strarr(strs);

    return 0;
}
