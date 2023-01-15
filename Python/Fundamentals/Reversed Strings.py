# Returns reversed string
def reverse_string(string):
    # Initializing variable for store reversed string
    reversed_string = ''
    # Iteration in string by symbols using 'range()' and 'len()' functions
    for symbol in range(len(string) - 1, -1, -1):
        # Adding character by character to 'reversed_string'
        reversed_string += str(string[symbol])
    # Return reversed string
    return reversed_string

# Printing result of working of 'reverse_string()' function
print(reverse_string('Hello, World!'))
