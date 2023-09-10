numbers_from_0_to_19 = ['', 'one', 'two', 'three', 'four', 'five',
                        'six', 'seven', 'eight', 'nine', 'ten',
                        'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen',
                        'sixteen', 'seventeen', 'eighteen', 'nineteen']

tens_from_20_to_90 = ['', '', 'twenty', 'thirty', 'forty',
                      'fifty', 'sixty', 'seventy', 'eighty', 'ninety']


def form_numerical_string(n: int, s: str) -> str:
    if (n >= 1000):
        s = form_numerical_string(n // 1000, s)
        tmp = f" {'thousand'}{' ' if n % 1000 else ''}"
        return form_numerical_string(n % 1000, s + tmp)
    elif (n >= 100):
        s = form_numerical_string(n // 100, s)
        tmp = f" {'hundred'}{' ' if n % 100 else ''}"
        return form_numerical_string(n % 100, s + tmp)
    elif (n >= 20):
        tmp = tens_from_20_to_90[n // 10]
        if (n % 10):
            tmp += '-'
        return form_numerical_string(n % 10, s + tmp)
    else:
        s += numbers_from_0_to_19[n]
        return s


def number2words(n: int) -> str:
    if (n == 0):
        return 'zero'
    s = ''
    return form_numerical_string(n, s)


words = "zero one two three four five six seven eight nine" + \
    " ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty" + \
    " thirty forty fifty sixty seventy eighty ninety"
words = words.split(" ")


def number2words_smart(n):
    if n < 20:
        return words[n]
    elif n < 100:
        return words[18 + n // 10] + ('' if n % 10 == 0 else '-' + words[n % 10])
    elif n < 1000:
        return number2words(n // 100) + " hundred" + (' ' + number2words(n % 100) if n % 100 > 0 else '')
    elif n < 1000000:
        return number2words(n // 1000) + " thousand" + (' ' + number2words(n % 1000) if n % 1000 > 0 else '')


n = int()
while (True):
    s = ''
    n = int(input("Enter value: "))
    if (n == 9999999):
        break
    print(f'{n} -> {form_numerical_string(n, s)}')
