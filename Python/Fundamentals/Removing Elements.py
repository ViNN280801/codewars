def remove_every_other(my_list: list) -> list:
    """ Removes elements with the odd indeces """
    return [x for i, x in enumerate(my_list) if i % 2 == 0]


def remove_every_other_clever(my_list: list) -> list:
    """ Removes elements with the odd indeces """
    return my_list[::2]


print(remove_every_other([1, 2, 3, 4, 5, 6, 7, 8, 9]))
print(remove_every_other(["Keep", "Remove", "Keep", "Remove", "Keep"]))

print(remove_every_other_clever([1, 2, 3, 4, 5, 6, 7, 8, 9]))
print(remove_every_other_clever(["Keep", "Remove", "Keep", "Remove", "Keep"]))
