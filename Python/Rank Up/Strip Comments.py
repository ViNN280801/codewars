def strip_comments(strng: str, markers: list) -> str:
    """ Returns string with stripped out all comments,
    that are enumerated in 'markers' list """

    # Splitting list by endline symbol
    lst = strng.split('\n')

    # Init result list
    res = list()

    # Iterate by string in splitted 'strng' variable
    for el in lst:
        # Init new string to add into all characters
        # that are not a delimeter from the 'markers' variable
        s = str()

        # Iterating by symbols in each string of splitted 'strng' variable
        for c in el:
            # If delimeters list contains the character from string -> break loop
            if c in markers:
                break
            # Otherwise -> adding it to a new string variable
            else:
                s += c
        # At first, we run "rstrip()" method, that strips out all whitespaces
        # from the right side of the string.
        # Then adding collected by characters string to the result list
        res.append(s.rstrip())

    # At last step we converting resulting list to string
    # with the endline delimeter
    # In other words, suggest, that we have a list ['This', 'is', 'a', 'string']
    # and method "join()" will make following substitution:
    # 'This' + '\n' + 'is' + '\n' + 'a' + '\n' + 'string'
    return '\n'.join(res)


print(strip_comments(
    'apples, pears # and bananas\ngrapes\nbananas !apples', ['#', '!']))
print(strip_comments('a #b\nc\nd $e f g', ['#', '$']))
print(strip_comments(' a #b\nc\nd $e f g', ['#', '$']))
print(strip_comments('#', ['#']))
print(strip_comments('\n§', ['§']))
print(strip_comments('apples, pears\ngrapes\nbananas !', ['!']))
print(strip_comments(
    '\tapples strawberries\n= watermelons lemons\ncherries\n@ pears avocados',
    ['.', "'", '-', '@', '#', ',', '=', '^', '?']))
