#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

size_t count_of_upper(char const *word)
{
    size_t counter = 0ul;
    for (size_t i = 0ul; i < strlen(word); ++i)
        if (isupper(word[i]))
            ++counter;
    return counter;
}

size_t *find_capitals(char const *word, size_t *uppercase_count)
{
    if (!word)
        return NULL;

    *uppercase_count = count_of_upper(word);

    size_t *capitals = (size_t *)calloc(*uppercase_count, sizeof(size_t));
    if (!capitals)
        return NULL;
    for (size_t i = 0ul, idx = 0ul; i < strlen(word); ++i)
        if (isupper(word[i]))
        {
            capitals[idx] = i;
            ++idx;
        }

    return capitals;
}

int main()
{
    size_t uppercase_count = 0ul, *capitals = find_capitals(NULL, &uppercase_count);
    if (!capitals)
        return 1;

    printf("Size = %lu\n", uppercase_count);
    for (size_t i = 0ul; i < uppercase_count; ++i)
        printf("%lu ", capitals[i]);
    printf("\n");

    if (capitals)
        free(capitals);
    capitals = NULL;

    return 0;
}
