def capitals(word: str) -> list:
    return [idx for idx, ch in enumerate(word) if ch.isupper()]


print(capitals("CodEWaRs"))
