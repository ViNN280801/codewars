def sort_by_length(arr: list) -> list:
    return sorted(arr, key=len)


print(sort_by_length(["Telescopes", "Glasses", "Eyes", "Monocles"]))
