#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void removeChar(char *str, char c)
{
    char *src = NULL, *dst = NULL;
    for (src = dst = str; *src != '\0'; src++)
    {
        *dst = *src;
        if (*dst != c)
            dst++;
    }
    *dst = '\0';
}

void remove_exclamation_marks(const char *str_in, char *str_out)
{
    strcpy(str_out, str_in);
    removeChar(str_out, '!');
    printf("str_out = %s\n", str_out);
}

void remove_exclamation_marks_clever(const char *str_in, char *str_out)
{
    do
    {
        if (*str_in != '!')
            *str_out++ = *str_in;
    } while (*str_in++);
}
