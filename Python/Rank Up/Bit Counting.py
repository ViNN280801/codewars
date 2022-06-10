# Task: Write a function that takes an integer as input, and returns the number 
# of bits that are equal to one in the binary representation 
# of that number. You can guarantee that input is non-negative.

# Example: The binary representation of 1234 is 10011010010, 
# so the function should return 5 in this case

def count_bits(param):
    # Returns count of 1 in binary representation
    if param < 0:
        param = -1 * param
    
    param = bin(param)

    count = 0
    for bit in str(param):
        if bit == '1':
            count += 1
    return count

print(count_bits(1234))

def clever_count_bits(param):
    # Returns count of 1 in binary representaion
    return bin(param).count('1')

print(count_bits(1234))