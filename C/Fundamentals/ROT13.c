#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>

#define ALPHABETSIZE 26

static const char alphabet[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

size_t getPosOfCharInAlphabet(char const ch)
{
    for (size_t i = 0; i <= strlen(alphabet); i++)
        if (ch == alphabet[i])
            return i;
    return ALPHABETSIZE * 2 + 1;
}

char *rot13(char *str_out, char const *str_in)
{
    for (size_t i = 0; i <= strlen(str_in); i++)
    {
        size_t pos = getPosOfCharInAlphabet(str_in[i]);

        if (pos != ALPHABETSIZE * 2 + 1)
        {
            pos = (pos >= strlen(alphabet) / 2) ? pos - 26 : pos + 26;
            str_out[i] = alphabet[pos];
        }
        else
            str_out[i] = str_in[i];
    }
    str_out[strlen(str_in)] = '\0';
    return str_out;
}

int main()
{
    char const *in = "EBG13 rknzcyr.";
    char *out = (char *)calloc(strlen(in), sizeof *in);
    if (!out)
    {
        printf("Error while allocating memory of string. Exiting...\n");
        exit(-1);
    }
    rot13(out, in);
    printf("%s\n", out);

    char const *in2 = "This is my first ROT13 excercise!";
    out = (char *)realloc(out, strlen("This is my first ROT13 excercise!"));
    if (!out)
    {
        printf("Error while allocating memory of string. Exiting...\n");
        exit(-1);
    }
    rot13(out, in2);
    printf("%s\n", out);

    return 0;
}
