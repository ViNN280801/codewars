def get_even_numbers(arr: list) -> list:
    """ 
    Filtering list 'arr': removing all odd numbers from it

    Args:
        arr (list): list to filter

    Returns:
        list: New filtered list without the odd numbers
    """

    return list(filter(lambda x: x % 2 == 0, arr))


def get_even_numbers_another(arr):
    return [x for x in arr if x % 2 == 0]


print(get_even_numbers([2, 4, 5, 6, 7, 8]))
print(get_even_numbers_another([2, 4, 5, 6, 7, 8]))
