#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Makes sentence from words
 * @param words words to make a sentence
 * @param nb_words count of words
 * @return Sentence which composed from passed words
 */
char *smash(const char *const words[], size_t nb_words)
{
    if (!words)
        return "";

    // Calculating size of sentence
    size_t size = 0ul;
    for (size_t i = 0ul; i < nb_words; i++)
        for (size_t j = 0ul; j < strlen(words[i]); j++)
            size++;

    // To assign end symbol with nil termination '\0'
    size += nb_words;

    // Allocating memory for sentence string
    char *sentence = (char *)calloc(size, sizeof(char));

    // Check if memory allocated properly
    if (!sentence)
        return "";

    // Filling sentence with words
    size_t res_idx = 0ul;
    for (size_t i = 0ul; i < nb_words; i++)
    {
        for (size_t j = 0ul; j < strlen(words[i]); j++)
        {
            sentence[res_idx] = words[i][j];
            res_idx++;
        }
        sentence[res_idx] = ' ';
        res_idx++;
    }

    // Adding termination symbol to the end of the string
    sentence[size - 1ul] = 0x00;
    return sentence;
}

/**
 * @brief Makes sentence from words
 * @param words words to make a sentence
 * @param count count of words
 * @return Sentence which composed from passed words
 */
char *smash_smart(const char **words, size_t count)
{
    int total_len = count - 1;
    for (int x = 0; x < count; ++x)
        total_len += strlen(words[x]);

    char *r = malloc(total_len + 1);
    if (!r)
        return 0;

    for (int x = 0, fwd = 0; x < count; ++x)
        fwd += sprintf(r + fwd, "%s ", words[x]);

    r[total_len] = 0;
    return r;
}

#define ARSZ(x) sizeof x / sizeof &x[0]

int main()
{
    const char *const words[] = {"hello", "world", "this", "is", "great"};
    const char *const words_2[] = {"a", "b", "c", "d"};
    const char *const words_3[] = {"hello", "world"};
    printf("%s*\n", smash(words, ARSZ(words)));
    printf("%s*\n", smash(words_2, ARSZ(words_2)));
    printf("%s*\n", smash(words_3, ARSZ(words_3)));

    return 0;
}
