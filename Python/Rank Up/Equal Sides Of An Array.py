# Task: You are going to be given an array of integers. Your job is to take that array and find an
# index N where the sum of the integers to the left of N is equal to the sum of the integers to the
# right of N. If there is no index that would make this happen, return -1.

# For example:

# Let's say you are given the array {1,2,3,4,3,2,1}:
# Your function will return the index 3, because at the 3rd position of the array,
# the sum of left side of the index ({1,2,3}) and the sum of the right side of the
# index ({3,2,1}) both equal 6.

# Let's look at another one.
# You are given the array {1,100,50,-51,1,1}:
# Your function will return the index 1, because at the 1st position of the array, the
# sum of left side of the index ({1}) and the sum of the right side of the index ({50,-51,1,1}) both equal 1.

# Last one:
# You are given the array {20,10,-80,10,10,15,35}
# At index 0 the left side is {}
# The right side is {10,-80,10,10,15,35}
# They both are equal to 0 when added. (Empty arrays are equal to 0 in this problem)
# Index 0 is the place where the left side and right side are equal.

# Note: Please remember that in most programming/scripting languages the index of an array starts at 0.

# Input:
# An integer array of length 0 < arr < 1000. The numbers in the array can be any integer positive or negative.

# Output:
# The lowest index N where the side to the left of N is equal to the side to the right of N. If you do not find an index that fits these rules, then you will return -1.

# Note:
# If you are given an array with multiple answers, return the lowest correct index.

def find_even_index_work(arr):
    ''' Returns index N where the sum of the integers to the left of N is equal to the sum of the integers to the right of N '''

    # Checking if size of array is more than 0 and less than 1000
    if len(arr) > 0 and len(arr) < 1000:
        # Iterating in list with 'for' loop and 'enumerate()' function which returns index and value
        for index, value in enumerate(arr):
            # 'left_sum' - sum up every element in list from 0 to required index
            left_sum = sum(arr[0:index])
            # 'right_sum' - sum up every element in list from required index to last index
            right_sum = sum(arr[index + 1:len(arr)])

            # Compare between sum of the left side and sum of the right side
            # If they are equals, return index
            if left_sum == right_sum:
                return index


def find_even_index(arr):
    ''' If 'find_even_index_work()' returns None type, returns -1 '''

    # Executing function 'find_even_index_work()' and return it result to 'index'
    index = find_even_index_work(arr)

    # If 'index' is None -> return -1
    if index is None:
        return -1
    # Else just return index
    else:
        return index


arr = [1, 2, 3, 4, 3, 2, 1]
print(find_even_index(arr))
arr = [1, 100, 50, -51, 1, 1]
print(find_even_index(arr))
arr = [1, 2, 3, 4, 5, 6]
print(find_even_index(arr))
arr = [20, 10, 30, 10, 10, 15, 35]
print(find_even_index(arr))
arr = [20, 10, -80, 10, 10, 15, 35]
print(find_even_index(arr))
arr = [10, -80, 10, 10, 15, 35, 20]
print(find_even_index(arr))
arr = list(range(1, 100))
print(find_even_index(arr))
arr = [0, 0, 0, 0, 0]
print(find_even_index(arr))
arr = [-1, -2, -3, -4, -3, -2, -1]
print(find_even_index(arr))
arr = list(range(-100, -1))
print(find_even_index(arr))


def clever_find_even_index(arr):
    ''' Returns index N where the sum of the integers to the left of N is equal to the sum of the integers to the right of N '''

    for i in range(len(arr)):
        if sum(arr[:i]) == sum(arr[i+1:]):
            return i
    return -1

print('Using clever funciton: ')

arr = [1, 2, 3, 4, 3, 2, 1]
print(find_even_index(arr))
arr = [1, 100, 50, -51, 1, 1]
print(find_even_index(arr))
arr = [1, 2, 3, 4, 5, 6]
print(find_even_index(arr))
arr = [20, 10, 30, 10, 10, 15, 35]
print(find_even_index(arr))
arr = [20, 10, -80, 10, 10, 15, 35]
print(find_even_index(arr))
arr = [10, -80, 10, 10, 15, 35, 20]
print(find_even_index(arr))
arr = list(range(1, 100))
print(find_even_index(arr))
arr = [0, 0, 0, 0, 0]
print(find_even_index(arr))
arr = [-1, -2, -3, -4, -3, -2, -1]
print(find_even_index(arr))
arr = list(range(-100, -1))
print(find_even_index(arr))