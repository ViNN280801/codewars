def multiplication_table(size: int) -> list[list[int]]:
    """ 
    Creates a multiplication table of the given size

    Args:
        size(int): The size of the table (it should be a square table)

    Returns: 
        Multiplication table n x n size 
    """

    result = [[0 for _ in range(size)] for _ in range(size)]

    # Filling first horizontal and vertical values of a multiplication table
    for i in range(size):
        result[i][0] = result[0][i] = i + 1

    # Filling the remaining elements
    for i in range(size):
        for j in range(size):
            result[i][j] = result[0][j] * result[i][0]

    return result


def multiplicationTable(size):
    return [[j*i for j in range(1, size+1)] for i in range(1, size+1)]


print(multiplication_table(3))
