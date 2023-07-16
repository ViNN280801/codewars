#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

// Describes words as word (char *) and it's length
typedef struct
{
    char *word;
    size_t len;
    int position;
} wpair_t;

/**
 * @brief Gets count of words in the sentence
 * @param sentence specified sentence
 * @returns Count of words in the specified sentence
 */
size_t count_of_words_in_sentence(char const *sentence)
{
    // If sentence is null pointer returns zero
    if (!sentence)
        return 0;

    // Counter of words
    int counter = 0;

    // Iterating by each symbol in sentence
    for (size_t i = 0; i < strlen(sentence) + 1; i++)
        // If symbol is whitespace or nil terminating symbol ('\0')
        // increasing counter
        if (sentence[i] == ' ' || sentence[i] == 0x00)
            counter++;

    return counter;
}

/**
 * @brief Separates sentence on words and it's lengths
 * @param sentence specified sentence
 * @return Array that contains words and it's lengths
 */
wpair_t *get_words_from_sentence(char const *sentence)
{
    // Get count of words in the sentence
    size_t wc = count_of_words_in_sentence(sentence);

    // Check that specified string is not null pointer and that count of words not null
    // (sentence isn't empty)
    if (!sentence || wc == 0)
        return NULL;

    // Allocating memory for array of words and it's lengths
    wpair_t *words = (wpair_t *)calloc(wc, sizeof(wpair_t));

    // Checking of properly memory allocation
    if (!words)
        return NULL;

    // Variable for length of current word and index of array to store it
    size_t len = 0, lenIdx = 0;

    // Iterating by each symbol in the sentence
    for (size_t i = 0; i < strlen(sentence) + 1; i++)
    {
        // Increasing length of word while not meets whitespace or nil terminating symbol ('\0')
        len++;
        if (sentence[i] == ' ' || sentence[i] == 0x00)
        {
            // Decreasing length (because whitespace or termination sign is counts)
            len--;

            // Filling words length
            words[lenIdx].len = len;

            // Move to next word
            lenIdx++;

            // Zeroing out counter
            len = 0;
        }
    }

    // Allocating memory in array of 'wpair_t' to store words of the specified sentence
    for (size_t i = 0; i < wc; i++)
    {
        words[i].word = (char *)calloc(words[i].len, sizeof(char));
        if (!words[i].word)
            return NULL;
    }

    // Index of symbol in the word
    size_t wordChIdx = 0;

    // Filling array of words with words
    for (size_t i = 0; i < wc; i++)
    {
        for (size_t j = 0; j < words[i].len; j++)
        {
            // Memorizing the order number of a word
            if (isdigit(sentence[wordChIdx]))
                words[i].position = sentence[wordChIdx] - '0';

            words[i].word[j] = sentence[wordChIdx];
            wordChIdx++;
        }
        // Skipping whitespaces
        wordChIdx++;
    }

    return words;
}

// Comparator func to work with 'qsort()'
int comp_wpair_t(const void *a, const void *b)
{
    const wpair_t *orderA = (wpair_t *)a, *orderB = (wpair_t *)b;
    return orderA->position - orderB->position;
}

char *order_words(char *ordered, const char *sentence)
{
    // Checking sentence
    if (!sentence)
        return "";

    size_t wc = count_of_words_in_sentence(sentence);
    wpair_t *words = get_words_from_sentence(sentence);

    if (!words)
        return "";

    // Sorting words by it's ordering numbers
    qsort(words, wc, sizeof(wpair_t), comp_wpair_t);

    // Making a sentence in a given in words order
    size_t pos = 0;
    for (size_t i = 0; i < wc; i++)
    {
        strcpy(ordered + pos, words[i].word);
        pos += words[i].len;

        // Don't need to add whitespace in a end of the string
        if (i != wc - 1)
        {
            ordered[pos] = ' ';
            pos++;
        }
    }

    // Adding nil terminating symbol to the end of the ordered sentence
    ordered[pos] = 0x00;

    // Clear allocated memory
    if (words)
    {
        for (size_t i = 0; i < wc; i++)
            free(words[i].word);
        free(words);
    }
    // Zeroing out pointer
    words = NULL;

    return ordered;
}

char *order_words_smart(char *ordered, const char *words)
{
    int index = 1, i = 0, j = 0;

    while (words[i])
    {
        if (words[i] - '0' == index)
        {
            while (words[i - 1] != ' ' && i >= 1)
                i--;
            while (words[i] && words[i] != ' ')
                ordered[j++] = words[i++];
            ordered[j++] = ' ';
            i = -1;
            index++;
        }
        i++;
    }
    ordered[j - 1] = '\0';
    return ordered;
}

char *order_words_another_smart(char *ordered, const char *words)
{
    char *adress, order = '1', *result = ordered;
    while ((adress = strchr(words, order++)) != NULL)
    {
        while (adress != words && *(adress - 1) != ' ')
        {
            adress--;
        }
        while (*(adress) != ' ' && *(adress) != '\0')
        {
            *(result++) = *(adress++);
        }
        *(result++) = ' ';
    }
    *--result = '\0';
    return ordered;
}

int main()
{
    char *ordered = (char *)calloc(strlen("1 o2af rat3oxbcxe smsnsft4lu rzkrefdx5 yv6avphki") + 1, sizeof(char));
    if (!ordered)
        return 1;
    char *p = order_words(ordered, "1 o2af rat3oxbcxe smsnsft4lu rzkrefdx5 yv6avphki");

    printf("%s\n", p);

    if (ordered)
        free(ordered);
    ordered = NULL;

    return EXIT_SUCCESS;
}
