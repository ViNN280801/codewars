#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t find_ch(char const *s, char tofind)
{
    for (size_t i = 0ul; i < strlen(s); ++i)
        if (s[i] == tofind)
            return i;
    return strlen(s);
}

char *name_shuffler(char *shuffled, const char *name)
{
    if (!name || strcmp(name, "") == 0)
    {
        shuffled = NULL;
        return NULL;
    }

    if (strcmp(name, " ") == 0)
        return " ";

    /* No need in codewars */
    /* if (shuffled)
        free(shuffled);
    shuffled = (char *)calloc(strlen(name), sizeof(char));
    if (!shuffled)
        return NULL; */

    size_t whitespace_pos = find_ch(name, ' ');
    if (whitespace_pos == strlen(name))
        return NULL;
    size_t idx = 0ul;
    for (size_t i = whitespace_pos + 1; i < strlen(name); ++i)
        shuffled[idx++] = name[i];
    shuffled[idx++] = ' ';
    for (size_t i = 0; i < whitespace_pos; ++i)
        shuffled[idx++] = name[i];
    shuffled[idx] = '\0';
    return shuffled;
}

int main()
{
    char const *s = "john McClane";
    char *sh = NULL;
    printf("%s\n", name_shuffler(sh, s));
    free(sh);

    return 0;
}
