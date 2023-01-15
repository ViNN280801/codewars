# Task: Write a function that when given a URL as a string, parses out just the domain name and returns it as a string. 
# For example:

# * url = "http://github.com/carbonfive/raygun" -> domain name = "github"
# * url = "http://www.zombie-bites.com"         -> domain name = "zombie-bites"
# * url = "https://www.cnet.com"                -> domain name = "cnet"

def domain_name(url):
    ''' Returns domain name from passed URL '''

    # Initializing tuple of strings which will be deleted in URL address
    to_delete = ('http://', 'https://', 'www.')

    # Iteration by elements of tuple to delete
    for i in to_delete:
        # If element in tuple in URL
        if i in url:
            # Replace this element to null-string
            url = url.replace(i, '')
    
    # Iteration by indeces and characters in string
    for index, character in enumerate(url):
        # If character is point
        if character == '.':
            # Slicing string to the point
            url = url[:index]

    # Returning result URL
    return url

# Testing function
print(domain_name('http://github.com/carbonfive/raygun'))
print(domain_name('http://www.zombie-bites.com'))
print(domain_name('https://www.cnet.comn'))
print(domain_name('http://google.com'))
print(domain_name('http://google.co.jp'))
print(domain_name('www.xakep.ru'))
print(domain_name('https://youtube.com'))
