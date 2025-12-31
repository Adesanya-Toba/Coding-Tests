"""Write a function, intersection, that takes in two lists, a,b, as arguments.
The function should return a new list containing elements that are in
both of the two lists.

You may assume that each input list does not contain duplicate elements."""


def intersection(a: list, b: list):
    result: list = []
    # Convert one of the lists into set to benefit from O(1) lookup
    set_a = set(a)  # Takes O(n) time

    # Iterate through the second and check
    for i in b:
        if i in set_a:
            result.append(i)

    # Collect values common to both
    return result


# Time: O(n+m), Space: O(n)


if __name__ == "__main__":
    print(intersection([4, 2, 1, 6], [3, 6, 9, 2, 10]))
    print(intersection([0, 1, 2], [10, 11]))
    print(intersection([4, 2, 1], [1, 2, 4, 6]))

    l1 = [4, 2, 1, 6]
    l2 = set(l1)
    print(l2)
    print(3 in l1)
