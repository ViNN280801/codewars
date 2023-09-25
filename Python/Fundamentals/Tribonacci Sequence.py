def tribonacci(signature: list, n: int) -> list:
    if len(signature) == 0 or len(signature) < 3 or n == 0:
        return []

    res = signature
    if (n <= 3):
        return res[:n]

    for i in range(3, n):
        res.append(res[i - 1] + res[i - 2] + res[i - 3])

    return res
