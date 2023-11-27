#include <string.h>

char *remove_mark(char *string)
{
    size_t len = strlen(string);
    if (len-- != 0 && string[len] == '!')
        string[len] = 0x00;
    return string;
}
