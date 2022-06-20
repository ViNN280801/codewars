# Task: Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

# array = [[1,2,3],
#          [4,5,6],
#          [7,8,9]]
# snail(array) #=> [1,2,3,6,9,8,7,4,5]

# For better understanding, please follow the numbers of the next array consecutively:

# array = [[1,2,3],
#          [8,9,4],
#          [7,6,5]]
# snail(array) #=> [1,2,3,4,5,6,7,8,9]

# NOTE: The idea is not sort the elements from the lowest value to the highest; the idea is to traverse the 2-d array in a clockwise snailshell pattern.
# NOTE 2: The 0x0 (empty matrix) is represented as en empty array inside an array [[]].

def get_ext_square(snail_map):
    ''' Returns external square of matrix '''
    # Initializing size of passed list
    list_size = len(snail_map)

    # If size of list equals 1 -> return 1st row of passed list
    if list_size == 1:
        return snail_map[0]

    # Initializing first row of passed list
    first_row = snail_map[0]
    # Initializing empty second row of passed list
    second_row = []

    # If size of list is bigger or equals to 3
    if list_size >= 3:
        # Using 'for' loop in range: [1; size - 1]
        for i in range(1, list_size - 1):
            # Adding elements to second row
            second_row.append(snail_map[i][list_size - 1])

    # Initializing third row of passed list
    third_row = snail_map[list_size - 1]
    # Reversing this row
    third_row.reverse()

    # Initializing empty fourth row of passed list
    fourth_row = []

    # If size of list is bigger or equals to 3
    if list_size >= 3:
        # Using 'for' loop in range: [1; size - 1]
        for i in range(1, list_size - 1):
            # Adding elements fourth second row
            fourth_row.append(snail_map[i][0])

    # Reversing fourth row
    fourth_row.reverse()

    # Returning total result row
    return first_row + second_row + third_row + fourth_row


def cut_ext_square(snail_map):
    ''' Returns new matrix (NxN) without external square '''
    # Initializing new matrix as list
    internal = []

    # Using 'for' loop in range: [1; size - 1]
    for i in range(1, len(snail_map) - 1):
        # Adding to empty list internal square of matrix
        internal.append(snail_map[i][1:len(snail_map) - 1])

    # Returning internal square
    return internal


def snail(snail_map):
    ''' Returns snail sorted (clockwise) list from 2 dimension array'''
    # Initializing result list
    result = []

    # While size of argument list is bigger than 3
    while len(snail_map) >= 3:
        # Adding to result external square of matrix
        result += get_ext_square(snail_map)
        # Removing from argument lsit elements which already used
        snail_map = cut_ext_square(snail_map)

    # Adding to result external square of matrix
    result += get_ext_square(snail_map)

    # Returning result snail sorted (clockwise) list
    return result


# Checking correctness of funciton:
print('Checking \'snail()\' function:')
# Checking #1:
# Initialization of array
int_array = [[1, 2, 3],
             [4, 5, 6],
             [7, 8, 9]]
# Printing result
print(snail(int_array))

# Checking #2:
# Initialization of array
int_array = [[1, 2, 3, 4],
             [5, 6, 7, 8],
             [9, 10, 11, 12],
             [13, 14, 15, 16]]
# Printing result
print(snail(int_array))

# Checking #3:
# Initialization of array
int_array = [[]]
# Printing result
print(snail(int_array))

# Checking #4:
# Initialization of array
int_array = [[1, 2, 3],
             [4, 5, 6],
             [7, 8]]
# Printing result
print(snail(int_array))

# Clever solution from codewars.com (20.06.2022)
import numpy as np

def snail_clever(array):
    ''' Returns snail sorted (clockwise) list from 2 dimension array'''
    # I only added handling errors for this function
    try:
        m = []
        array = np.array(array)
        while len(array) > 0:
            m += array[0].tolist()
            array = np.rot90(array[1:])
        return m
    except:
        return []

# Checking correctness of funciton:
print('\nChecking clever \'snail()\' function:')
# Checking #1:
# Initialization of array
int_array = [[1, 2, 3],
             [4, 5, 6],
             [7, 8, 9]]
# Printing result
print(snail_clever(int_array))

# Checking #2:
# Initialization of array
int_array = [[1, 2, 3, 4],
             [5, 6, 7, 8],
             [9, 10, 11, 12],
             [13, 14, 15, 16]]
# Printing result
print(snail_clever(int_array))

# Checking #3:
# Initialization of array
int_array = [[]]
# Printing result
print(snail_clever(int_array))

# Checking #4:
# Initialization of array
int_array = [[1, 2, 3],
             [4, 5, 6],
             [7, 8]]
# Printing result
print(snail_clever(int_array))

# Deallocating memory from global variable
del int_array