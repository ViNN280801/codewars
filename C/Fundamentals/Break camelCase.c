#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Gets count of uppercased characters in the specified string
 * @param str string to find uppercased characters
 * @return Count of uppercased characters
 */
size_t get_uppercased_count(const char *str)
{
    size_t count = 0;
    for (size_t i = 0; i < strlen(str); i++)
        if (isupper(str[i]))
            count++;
    return count;
}

/**
 * @brief Splits camel case string into separate words. Separating with whitespace
 * @param camelCase string to split it
 * @return Result of split
 */
char *solution(const char *kcamelCase)
{
    if (!kcamelCase)
        return "";

    char *camelCase = (char *)calloc(strlen(kcamelCase) + 1, sizeof(char));

    // Checking of properly allocating memory
    if (!camelCase)
        return "";
    strcpy(camelCase, kcamelCase);
    camelCase[strlen(kcamelCase) + 1] = 0x00;

    // Get count of uppercased in the string
    size_t uppercased_count = get_uppercased_count(camelCase);

    // If specified string don't contents any uppercase -> just return itself
    if (uppercased_count == 0)
        return camelCase;

    // Allocating memory for new splitted by whitespaces string
    char *result = (char *)calloc(strlen(camelCase) + uppercased_count + 1, sizeof(char));

    if (!result)
        return "";

    result[strlen(camelCase) + uppercased_count + 1] = 0x00;

    // Adding characters from arg string to 'result' string
    for (size_t i = 0; i < strlen(camelCase); i++)
    {
        if (isupper(camelCase[i]))
        {
            char c_to_str[3];
            c_to_str[0] = ' ';
            c_to_str[1] = camelCase[i];
            c_to_str[2] = 0x00;
            strcat(result, c_to_str);
        }
        else
        {
            char c_to_str[2];
            c_to_str[0] = camelCase[i];
            c_to_str[1] = 0x00;
            strcat(result, c_to_str);
        }
    }
    return result;
}

char *solution_smart(const char *camelCase)
{
    if (!camelCase)
        return "";

    size_t in_len = strlen(camelCase);

    char *output = (char *)calloc(in_len * 2, sizeof(char));
    if (!output)
        return "";

    for (size_t i = 0, k = 0; i < in_len; i++, k++)
    {
        if (i >= 1 && isupper(camelCase[i]))
        {
            output[k] = ' ';
            k++;
        }
        output[k] = camelCase[i];
    }
    return output;
}

int main()
{
    printf("%s\n", solution(NULL));
    printf("%s\n", solution("breakCamel"));
    printf("%s\n", solution("identifier"));
    printf("%s\n", solution(""));
    printf("%s\n", solution("breakCamelCase"));
    printf("%s\n", solution("ehagdacHdcdfebbdCddHfcabhcFafegAbhdebGgh"));

    printf("%s\n", solution_smart(NULL));
    printf("%s\n", solution_smart("breakCamel"));
    printf("%s\n", solution_smart("identifier"));
    printf("%s\n", solution_smart(""));
    printf("%s\n", solution_smart("breakCamelCase"));
    printf("%s\n", solution_smart("ehagdacHdcdfebbdCddHfcabhcFafegAbhdebGgh"));

    return 0;
}
