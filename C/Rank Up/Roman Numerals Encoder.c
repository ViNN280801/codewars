// Task: Create a function taking a positive integer as its parameter and returning a
// string containing the Roman Numeral representation of that integer.

// Modern Roman numerals are written by expressing each digit separately starting with
// the left most digit and skipping any digit with a value of zero. In Roman numerals 1990
// is rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC. 2008 is written as 2000=MM, 8=VIII;
// or MMVIII. 1666 uses each Roman symbol in descending order: MDCLXVI.
// Example:
// solution(1000); // => "M"

// Help:
// Symbol    Value
// I          1
// V          5
// X          10
// L          50
// C          100
// D          500
// M          1,000

// Remember that there can't be more than 3 identical symbols in a row.
// More about roman numerals - http://en.wikipedia.org/wiki/Roman_numerals

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Maximum number allowed in Roman numerals is 3999 - MMMCMXCIX
const int max_value_Roman = 3999;
// Maximum length for string contains MMMCMXCIX number
// 9 chars and 10th is '\0'
const int max_size_Roman = 10;

// Returns integer number in Roman numerals as string (char *)
char *solution(int num)
{
    char *str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values_roman[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    // Check if number in valid intervals
    if (num > 0 && num <= max_value_Roman)
    {
        // Initializing char array for return it as result
        // Need little bit more memory for this string
        char *result_str = (char *)calloc(max_size_Roman, sizeof(char));

        // If memory allocation successfull -> continue working
        if (result_str)
        {
            // Using 'for' loop to iterate in roman values
            for (int index = 0; index < 13; index++)
            {
                // While number is more or equals null
                while (num - values_roman[index] >= 0)
                {
                    // Concatenating roman numerals into 'result_str'
                    strcat(result_str, str_romans[index]);
                    // Decrease number
                    num -= values_roman[index];
                }
            }
        }
        // If memory allocation failed -> print appropriate message and exit from programm with failure status
        else
        {
            printf("Can't allocate memory for array.\n");
            exit(EXIT_FAILURE);
        }

        // Returning result string
        return result_str;
    }
    // Else number is negative or equals to null
    else
        return "Can't represent this number in Roman numerals.\n";
}

int main(int argc, char *argv[])
{
    // Initializing string with roman numerals
    char *sln = solution(1990);

    // Printing result
    printf("%s\n", sln);

    // Deallocating memory
    free(sln);

    return EXIT_SUCCESS;
}
