import string
from codecs import encode


def rot13(msg: str) -> str:
    """ Returns encoded string with rot13 cipher """
    return encode(msg, 'rot13')


def rot13WithoutCodecs(msg: str) -> str:
    """ Returns encoded string with rot13 cipher """
    firstPartOfAlphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'
    secndPartOfAlphabet = 'NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm'
    return msg.translate(string.maketrans(firstPartOfAlphabet, secndPartOfAlphabet))


print(rot13('EBG13 rknzcyr.'))
print(rot13('This is my first ROT13 excercise!'))

print(rot13WithoutCodecs('EBG13 rknzcyr.'))
print(rot13WithoutCodecs('This is my first ROT13 excercise!'))
