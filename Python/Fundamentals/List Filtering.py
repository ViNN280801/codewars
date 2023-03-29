def filter_list(l):
    return [el for el in l if isinstance(el, int)]


print(filter_list([1, 2, 'a', 'b']))
