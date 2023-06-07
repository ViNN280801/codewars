#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool validate_pin(const char *pin)
{
    for (size_t i = 0; i < strlen(pin); i++)
        if (!isdigit(pin[i]))
            return false;
    return (strlen(pin) == 4 || strlen(pin) == 6) ? true : false;
}
