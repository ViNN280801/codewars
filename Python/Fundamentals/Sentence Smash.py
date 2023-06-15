def smash(words: list) -> str:
    """ Returns sentence from list of words """
    return "".join([x + ' ' for x in words]).rstrip()

def smash_smart(words: list) -> str:
    """ Returns sentence from list of words """
    return ' '.join(words)


print(smash(['hello', 'world', 'this', 'is', 'great']))
print(smash_smart(['hello', 'world', 'this', 'is', 'great']))
