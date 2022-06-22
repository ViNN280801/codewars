// Task: The rgb function is incomplete. Complete it so that passing in RGB
// decimal values will result in a hexadecimal representation being returned.
// Valid decimal values for RGB are 0 - 255. Any values that fall out of that
// range must be rounded to the closest valid value.
// Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.

// The following are examples of expected output values:
// char output[7] = {0};

// rgb(255, 255, 255, output);
// output == "FFFFFF";

// rgb(255, 255, 300, output);
// output == "FFFFFF";

// rgb(0, 0, 0, output);
// output == "000000";

// rgb(148, 0, 211, output);
// output == "9400D3";

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns passed value if it's interval is [0; 255]
// Otherwise returns closest valid value
int check_RGB_value(int value)
{
    // Checking intervals of value
    if (value >= 0 && value <= 255)
        return value;
    // If value is negative -> return closest valid value, so it is 0
    else if (value < 0)
        return 0;
    // Last case:
    // If value is bigger than 255 -> return closest valid value which is 255
    else
        return 255;
}

// Returns hexadecimal representation of passed value
const char *int_to_hex(int value)
{
    // Initializing char array
    char *pair = NULL;

    // Following line is necessary for reallocating memory 
    // When use in bigger loops allocation can reach max buffer size
    // This line deallocating memory from pair to store 3 bytes all time
    pair = (char *)realloc(pair, 0UL);

    // Allocating 3 bytes for store pair of symbols and '\0' symbol
    pair = (char *)calloc(3UL, sizeof(char));

    // Checking and reassigning RGB value
    value = check_RGB_value(value);

    // Composing a string with format "%02X"
    // Note '02' says that the string stores 2 characters
    // If the string stores 1 character, then add 0 to beginning of string
    snprintf(pair, sizeof(char) * 3UL, "%02X", value);

    // Returning hexadecimal value as string
    return pair;
}

// Returns 0 if integer converts to RGB successfully
// Otherwise return -1
int rgb(int r, int g, int b, char *output)
{
    // Copying symbols from 'r' value to output
    strcpy(output, int_to_hex(r));

    // Concatenating strings with hexadecimal representations
    strcat(output, int_to_hex(g));
    strcat(output, int_to_hex(b));

    if (output != NULL)
        // Returning result string
        return 0;
    else
        return -1;
}

int main()
{
    // Initializing integer arrays which contains RGB values
    int r[] = {0, 1, 255, 254, -20, 370, 12, 315, 417, 111};
    int g[] = {0, 2, 255, 253, 275, 262, -149, 12, -103, 82};
    int b[] = {0, 3, 255, 252, 125, -121, -49, 154, -35, 26};

    // Initializing size of input
    size_t input_sz = sizeof(r) / sizeof(int);

    // Initializing
    char output[input_sz][7];

    // Initializing known results
    char *expected[] = {"000000", "010203", "FFFFFF", "FEFDFC", "00FF7D", "FFFF00", "0C0000", "FF0C9A", "FF0000", "6F521A"};

    // Using 'for' loop for iterate by elements in array
    for (size_t i = 0UL; i < input_sz; i++)
    {
        // Filling 'output' variable
        rgb(r[i], g[i], b[i], output[i]);

        // Compare results
        if (strcmp(output[i], expected[i]) == 0)
            printf("OK\n");
        else
            printf("Error\n");
    }

    return 0;
}
