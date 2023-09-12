#include <stddef.h>
#include <string.h>

int is_vowel(char ch) { return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; }

size_t get_count(char const *s)
{
    size_t count = 0ul;

    for (size_t i = 0ul; i < strlen(s); i++)
        if (is_vowel(s[i]))
            count++;

    return count;
}
