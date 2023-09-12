def get_count(sentence: str) -> int:
    return len([ch for ch in sentence if ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u'])
