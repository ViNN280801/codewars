// Task:
// Welcome.
// In this kata you are required to, given a string, replace every letter with its position in the alphabet.
// If anything in the text isn't a letter, ignore it and don't return it.
// "a" = 1, "b" = 2, etc.

// Example
// alphabet_position("The sunset sets at twelve o' clock.")
// Should return "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11" ( as a string )

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

// Returns positions of character in alphabet as int.
// If there is no such character, returns -1
int getpos_in_alphabet(char character)
{
    if (character >= 'a' && character <= 'z')
        return character - 'a' + 1;
    else if (character >= 'A' && character <= 'Z')
        return character - 'A' + 1;
    else
        return -1;
}

// Returns string with positions of each character in 'text'
char *alphabet_position(const char *text)
{
    // Allocating memory for int array with 'calloc()' function
    int *positions_arr = (int *)calloc(strlen(text), sizeof(int));

    // Need to allocate more memory for string than to int array
    char *str = (char *)calloc(strlen(text) * 4UL, sizeof(char));

    // If 'positionArr' is not NULL (if 'calloc()' can allocate memory)
    if (positions_arr)
    {
        for (size_t index = 0UL; index < strlen(text); index++)
        {
            // Writing positions of each characters into integer array
            positions_arr[index] = getpos_in_alphabet(text[index]);
        }

        // Initializing temporaly buffer to store inetegers from 'positions_arr' array
        char buff[BUFFER_SIZE];
        // Checking on successfull memory allocation
        if (str)
        {
            // Iteration in 'text' variable character by character
            for (size_t index = 0UL; index < strlen(text); index++)
            {
                // No need to store symbols not from alphabet
                if (positions_arr[index] != -1)
                {
                    // Writing position to temporaly buffer
                    snprintf(buff, BUFFER_SIZE, "%d ", positions_arr[index]);
                    // Concatenating all positions in one char array, called 'str'
                    strcat(str, buff);
                }
            }
            // Removing last space from result string 'str'
            str[strlen(str) - 1] = '\0';
        }
        // If memory allocation was failed -> print & exit from program
        else
        {
            printf("Error. Can't allocate memory.\n");
            exit(EXIT_FAILURE);
        }
    }
    // If memory allocation was failed -> print & exit from programu
    else
    {
        printf("Error. Can't allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    // Freeing out memory of integer array
    free(positions_arr);

    // Returning string with positions of each character in given string
    return str;
}

int main(int argc, char *argv[])
{
    const char *text = "The sunset sets at twelve o' clock.";
    printf("%s\n", alphabet_position(text));

    return EXIT_SUCCESS;
}