def remove(s: str) -> str:
    if s[len(s) - 1] == '!':
        return s[:-1]
    else:
        return s
