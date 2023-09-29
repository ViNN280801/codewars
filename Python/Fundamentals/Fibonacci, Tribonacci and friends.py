def Xbonacci(signature: list, n: int) -> list:
    idx = 0
    while len(signature) < n:
        signature.append(sum(signature[idx:]))
        idx += 1
    return signature[:n]
