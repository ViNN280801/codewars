#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 * @brief Splits IPv4 on integer values
 * @param IPv4 string that represents IPv4 address
 * @return Pointer on array of integer values
 */
int *get_vals_from_IPv4(char const *IPv4)
{
    // Memory allocation and check of properly allocation
    char *tmp = (char *)calloc(3ul, sizeof(char));
    if (!tmp)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(1);
    }

    int *vals = (int *)calloc(4ul, sizeof(int));
    if (!vals)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(1);
    }

    // Filling values to dynamically arrays
    size_t tmp_idx = 0ul, vals_idx = 0ul;
    for (size_t i = 0ul; i < strlen(IPv4) + 1ul; i++)
    {
        tmp[tmp_idx] = IPv4[i];
        tmp_idx++;

        // If symbols is dot or index is the last character
        if (IPv4[i] == '.' || i == strlen(IPv4))
        {
            // Adding nil-terminating symbol
            tmp[tmp_idx - 1] = 0x00;

            // Clearing out index
            tmp_idx = 0ul;

            // Converting tmp string to integer representation
            // and putting result to values array
            vals[vals_idx] = atoi(tmp);

            // Moving to the next index in values array
            vals_idx++;
        }
    }

    // Deallocating memory and clearing out pointer
    free(tmp);
    tmp = NULL;

    return vals;
}

/**
 * @brief Splits IPv4 on integer values
 * @param IPv4 string that represents IPv4 address
 * @return Pointer on array of integer values
 */
int *get_vals_from_IPv4_ver2(char const *IPv4)
{
    // Allocating memory and checking it
    int *vals = (int *)calloc(4ul, sizeof(int));
    if (!vals)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(1);
    }

    // Get values one by one
    sscanf(IPv4, "%d.%d.%d.%d", &vals[0], &vals[1], &vals[2], &vals[3]);

    return vals;
}

/**
 * @brief Converts integer value to a hex string
 * @param value integer value to convert
 * @param maxlen Maximum number of bytes to be used in the buffer.
 * @param format format to display ("0x%X", 0x%x, etc.)
 * The generated string has a length of at most n-1, leaving space
 * for the additional terminating null character. [src: https://cplusplus.com/reference/cstdio/snprintf/]
 * @return Hex string represented as "char *" (!!! Don't forget to deallocate memory !!!)
 */
char *int_to_hex(int value, size_t maxlen, char const *format)
{
    char *hex = (char *)calloc(maxlen, sizeof(char));
    if (!hex)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(1);
    }
    snprintf(hex, maxlen, format, value);
    hex[maxlen + 1] = 0x00;
    return hex;
}

/**
 * @brief Converts hex string to an integer value
 * @param hex hex string
 * @param format format to display (0xFF; 0xff; FF -> 255)
 * @return Integer value converts from hex string
 */
unsigned int hex_to_int(const char *hex, const char *format)
{
    unsigned res = 0;
    sscanf(hex, format, &res);
    return res;
}

/**
 * @brief Converts IPv4 address to hexadecimal string
 * @param IPv4 string that contains IPv4 address
 * @return String that represents IPv4 address in hex
 */
char *IPv4_to_hex(char const *IPv4)
{
    // At first getting all numbers to separate array
    int *vals = get_vals_from_IPv4_ver2(IPv4);

    /* --- Converting value one by one and putting result to common string --- */
    char *result = (char *)calloc(11ul, sizeof(char));
    if (!result)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(1);
    }
    strcat(result, "0x");

    for (short i = 0; i < 4; i++)
    {
        // Converting integer to hex with precision 2 digits (symbols)
        char *hexval = int_to_hex(vals[i], 6ul, "%.2x");
        strcat(result, hexval);

        free(hexval);
        hexval = NULL;
    }
    result[11ul] = 0x00;

    free(vals);
    vals = NULL;

    return result;
}

/**
 * @brief Receives two IPv4 addresses, and returns the number of
 * addresses between them (including the first one, excluding the last one).
 * Assumes that all inputs will be valid IPv4 addresses in the form of strings.
 * And the last address will always be greater than the first one.
 * @param start 1st IPv4 address
 * @param end 2nd IPv4 address
 * @return Number of addresses between them
 */
uint32_t ips_between(const char *start, const char *end) { return hex_to_int(IPv4_to_hex(end), "0x%x") - hex_to_int(IPv4_to_hex(start), "0x%x"); }

/* === Smart sln === */
#include <inttypes.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

uint32_t ips_between_smart(const char *start, const char *end) { return ntohl(inet_addr(end)) - ntohl(inet_addr(start)); }
/* === End of smart sln === */

/* === Another smart sln === */
#define IP2UINT32(i1, i2, i3, i4) i1 << 24 | i2 << 16 | i3 << 8 | i4

uint32_t ips_between_another_smart(const char *start, const char *end)
{
    int is[4], ie[4], s, e;

    sscanf(start, "%d.%d.%d.%d", &is[0], &is[1], &is[2], &is[3]);
    sscanf(end, "%d.%d.%d.%d", &ie[0], &ie[1], &ie[2], &ie[3]);

    s = IP2UINT32(is[0], is[1], is[2], is[3]);
    e = IP2UINT32(ie[0], ie[1], ie[2], ie[3]);

    return e - s;
}
/* === End of another smart sln === */

int main()
{
    printf("result = %u\n", ips_between("10.0.0.0", "10.0.0.50"));
    printf("result = %u\n", ips_between("10.0.0.0", "10.0.1.0"));
    printf("result = %u\n", ips_between("20.0.0.10", "20.0.1.0"));

    printf("\nresult = %u\n", ips_between_smart("10.0.0.0", "10.0.0.50"));
    printf("result = %u\n", ips_between_smart("10.0.0.0", "10.0.1.0"));
    printf("result = %u\n", ips_between_smart("20.0.0.10", "20.0.1.0"));

    printf("\nresult = %u\n", ips_between_another_smart("10.0.0.0", "10.0.0.50"));
    printf("result = %u\n", ips_between_another_smart("10.0.0.0", "10.0.1.0"));
    printf("result = %u\n", ips_between_another_smart("20.0.0.10", "20.0.1.0"));

    return 0;
}
