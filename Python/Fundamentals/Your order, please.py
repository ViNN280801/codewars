import re


def order(sentence: str) -> str:
    """ Returns words in specified position (where position of each)
    word is in the word """
    # If sentence is empty -> return empty string
    if not sentence:
        return ""

    # Splitting sentence on words; var 'words' is a list of strings
    words = sentence.split()

    # For each word in sentence is applied 're.findall()' that returns list of matches
    # We expexted that word can contain only 1 number of order, we applying [0] index
    # At the third step extracted number of ordering from word is converting to 'int' type
    # At the final step tuple is created that contains position and word:
    # "(int(re.findall(r'\d+', word)[0]), word)" -> "(pos, word)" for each word in the sentence
    words_with_positions = [
        (int(re.findall(r'\d+', word)[0]), word) for word in words]

    # Iterating by list of tuples that are sorted by positions
    # Underscore '_' used because we are only interested in second variable of a tuple (word)
    sorted_words = [word for _, word in sorted(words_with_positions)]

    # Connecting words with whitespaces with method 'join()' of a string
    return " ".join(sorted_words)


def order_smart(words):
    return ' '.join(sorted(words.split(), key=lambda w: sorted(w)))


print(order("is2 Thi1s T4est 3a"))
print(order("4of Fo1r pe6ople g3ood th5e the2"))
print(order(""))
print(order("3of Fo2r pe4ople g1ood th5e the6"))
