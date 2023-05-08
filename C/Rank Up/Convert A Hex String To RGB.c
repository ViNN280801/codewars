// Task: When working with color values it can sometimes be useful to extract
// the individual red, green, and blue (RGB) component values for a color.
// Implement a function that meets these requirements:

// Accepts a case-insensitive hexadecimal color string as its parameter (ex. "#FF9933" or "#ff9933")
// Returns a Map<String, int> with the structure {r: 255, g: 153, b: 51} where r, g, and b range from 0 through 255

// Note: your implementation does not need to support the shorthand form of hexadecimal notation (ie "#FFF")

// Example:
// "#FF9933" --> {r: 255, g: 153, b: 51}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/// @brief Allocates memory for pointer on "char" type
/// @param size size of string to allocate
/// @return Pointer on string with allocated memory
char *alloc_pchar(size_t size)
{
    // Allocating memory for string
    char *str = (char *)calloc(size, sizeof(char));

    // Check if memory allocates properly
    if (!str)
    {
        printf("Error: str_to_upper(char *): Can't allocate memory\n");
        exit(1);
    }
    return str;
}

/// @brief Deallocates memory of 'pchar'
/// @param pchar pointer to deallocate it's memory
void dealloc_pchar(char *pchar)
{
    free(pchar);
    pchar = NULL;
}

/// @brief Converts string represented in hex to integer value
/// @param hex string to convert
/// @return Converting of hex result
int hex_to_int(const char *hex)
{
    return (int)strtol(hex, NULL, 16);
}

typedef struct
{
    int r, g, b;
} rgb_t;

rgb_t hex_str_to_rgb(const char *hex_str)
{
    if (strlen(hex_str) != 7)
    {
        printf("Error: hex_str_to_rgb(const char *): \"%s\" is invalid notation\n", hex_str);
        exit(1);
    }
    char *red = alloc_pchar(2), *green = alloc_pchar(2), *blue = alloc_pchar(2);

    red[0] = hex_str[1];
    red[1] = hex_str[2];

    green[0] = hex_str[3];
    green[1] = hex_str[4];

    blue[0] = hex_str[5];
    blue[1] = hex_str[6];

    rgb_t rgb;
    rgb.r = hex_to_int(red);
    rgb.g = hex_to_int(green);
    rgb.b = hex_to_int(blue);

    dealloc_pchar(red);
    dealloc_pchar(green);
    dealloc_pchar(blue);

    return rgb;
}

rgb_t hex_str_to_rgb_clever(const char *hex_str)
{
    unsigned int r, g, b;
    sscanf(hex_str, "#%2x%2x%2x", &r, &g, &b);
    return (rgb_t){r, g, b};
}

int main()
{
    printf("%d %d %d\n", hex_str_to_rgb("#FF9933").r, hex_str_to_rgb("#FF9933").g, hex_str_to_rgb("#FF9933").b);
    printf("%d %d %d\n", hex_str_to_rgb("#beaded").r, hex_str_to_rgb("#beaded").g, hex_str_to_rgb("#beaded").b);
    printf("%d %d %d\n", hex_str_to_rgb("#000000").r, hex_str_to_rgb("#000000").g, hex_str_to_rgb("#000000").b);
    printf("%d %d %d\n", hex_str_to_rgb("#111111").r, hex_str_to_rgb("#111111").g, hex_str_to_rgb("#111111").b);

    printf("\n%d %d %d\n", hex_str_to_rgb_clever("#FF9933").r, hex_str_to_rgb_clever("#FF9933").g, hex_str_to_rgb_clever("#FF9933").b);
    printf("%d %d %d\n", hex_str_to_rgb_clever("#beaded").r, hex_str_to_rgb_clever("#beaded").g, hex_str_to_rgb_clever("#beaded").b);
    printf("%d %d %d\n", hex_str_to_rgb_clever("#000000").r, hex_str_to_rgb_clever("#000000").g, hex_str_to_rgb_clever("#000000").b);
    printf("%d %d %d\n", hex_str_to_rgb_clever("#111111").r, hex_str_to_rgb_clever("#111111").g, hex_str_to_rgb_clever("#111111").b);

    return 0;
}
