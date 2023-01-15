// Task: A pangram is a sentence that contains every single letter of the alphabet at least once.
// For example, the sentence "The quick brown fox jumps over the lazy dog" is a pangram, because
// it uses the letters A-Z at least once (case is irrelevant).
// Given a string, detect whether or not it is a pangram. Return True if it is, False if not. Ignore numbers and punctuation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFF_SIZE 256

// Returns true if 'str_in' is pangram
bool is_pangram(const char *str_in)
{
    // Create a hash table to mark the characters
    // present in the string
    bool mark[26];
    for (int i = 0; i < 26; i++)
        mark[i] = false;

    // For indexing in mark[]
    int index;

    // Traverse all characters
    size_t size = strlen(str_in);
    for (int i = 0; i < size; i++)
    {

        // If uppercase character, subtract 'A'
        // to find index.
        if ('A' <= str_in[i] && str_in[i] <= 'Z')
            index = str_in[i] - 'A';

        // If lowercase character, subtract 'a'
        // to find index.
        else if ('a' <= str_in[i] && str_in[i] <= 'z')
            index = str_in[i] - 'a';

        // If this character is other than english
        // lowercase and uppercase characters.
        else
            continue;

        mark[index] = true;
    }

    // Return false if any character is unmarked
    for (int i = 0; i <= 25; i++)
        if (mark[i] == false)
            return (false);

    // If all characters were present
    return (true);
}

int main(int argc, char *argv[])
{
    // Initializing array of characters, allocating 256 bytes for store this string
    char *str = calloc(BUFF_SIZE, sizeof(char));

    // Initializing template string for checking
    const char *pangram = "The quick , brown fox jumps over the lazy dog!";
    const char *not_pangram = "The quick, brown fox jumped over the lazy dog!";

    if (is_pangram(pangram) && !is_pangram(not_pangram))
    {
        printf("String: %s - is pangram\n", pangram);
        printf("String: %s - is not a pangram\n", not_pangram);
    }

    if (str != NULL)
    {
        printf("Enter string: ");
        // "%[^\n] format allows to scanf string with spaces while \n"
        scanf("%[^\n]", str);

        if (is_pangram(str) == 0)
            printf("String is not a pangram.\n");
        else
            printf("String is a pangram.\n");
    }
    else
    {
        printf("Memory allocating error was occured. Exiting.\n");
        exit(1);
    }

    free(str);

    return 0;
}