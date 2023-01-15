# Task: The marketing team is spending way too much time typing in hashtags.
# Let's help them with our own Hashtag Generator!

# Here's the deal:

#     It must start with a hashtag (#).
#     All words must have their first letter capitalized.
#     If the final result is longer than 140 chars it must return false.
#     If the input or the result is an empty string it must return false.

# Examples
# " Hello there thanks for trying my Kata"  =>  "#HelloThereThanksForTryingMyKata"
# "    Hello     World   "                  =>  "#HelloWorld"
# ""                                        =>  false

def generate_hashtag(s):
    '''
    Returns string where all first letters of each word is capitalized and at the begginning of sentence is hashtag (#)
    If length of final result is longer than 140 chars -> return False 
    If the input or the result string is empty -> also return False
    '''
    # Converting 's' to string type
    s = str(s)
    # If string is empty -> return False
    if s == '':
        return False

    # Splitting sentence by spaces, then capitalize each word
    s = [word.capitalize() for word in s.split()]
    # Converting list to string
    s = ''.join(s)
    # Adding hashtag in the begginning of result string
    s = '#' + s

    # Check if result string is less than 140 characters or string is empty
    if s == '' or len(s) <= 140:
        return s
    else:
        return False


print(generate_hashtag('do we   have   a hashtag'))
print(generate_hashtag(''))
print(generate_hashtag('c i n'))
print(generate_hashtag('CodeWars is nice'))
