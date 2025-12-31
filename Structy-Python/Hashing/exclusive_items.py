"""Write a function, exclusive_items, that takes in two lists, a,b, as
arguments. The function should return a new list containing elements
that are in either list but not both lists.

You may assume that each input list does not contain duplicate elements."""

from typing import List


def exclusive_items_mine(a: List, b: List):
    # Similar to intersection
    set_b = set(b)
    result = []

    # Iterate through second list
    for i in a:
        if i in set_b:
            set_b.remove(i)
        else:
            result.append(i)

    result.extend(set_b)

    return result


# Time: O(n), O(n+m); where n and m are lengths of a and b resp.


def exclusive_items_alvin(a: List, b: List):
    # convert both to sets and compare during iteration
    set_a = set(a)
    set_b = set(b)

    result = []
    # Loop through set_a
    for i in a:
        if i not in set_b:
            result.append(i)

    for j in b:
        if j not in set_a:
            result.append(j)

    return result


# Time: O(n+m), O(n+m); where n and m are lengths of a and b resp.


if __name__ == "__main__":
    print(exclusive_items_mine([4, 2, 1, 6], [3, 6, 9, 2, 10]))
    print(exclusive_items_alvin([4, 2, 1, 6], [3, 6, 9, 2, 10]))
