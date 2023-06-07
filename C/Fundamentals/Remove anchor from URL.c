#include <string.h>

char *remove_url_anchor(const char *url_in)
{
    return strtok(strdup(url_in), "#");
}
