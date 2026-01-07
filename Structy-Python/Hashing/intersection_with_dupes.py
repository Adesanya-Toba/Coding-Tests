"""Write a function, intersection_with_dupes, that takes in two
lists, a,b, as arguments. The function should return a new list
containing elements that are common to both input lists. The elements
in the result should appear as many times as they occur in both
input lists.

You can return the result in any order."""


def intersection_with_dupes(a, b):
    hash_a = convert_to_hash_map(a)
    hash_b = convert_to_hash_map(b)

    result = []

    for key in hash_a:
        if key in hash_b:
            for i in range(0, min(hash_a[key], hash_b[key])):
                result.append(key)

    return result


def convert_to_hash_map(lst: list):
    hash_map = {}
    for i in lst:
        if i not in hash_map:
            hash_map[i] = 1
        else:
            hash_map[i] += 1
    return hash_map


# Alternate solution with Counter
from collections import Counter


def alt_intersection_with_dupes(a, b):
    count_a = Counter(a)
    count_b = Counter(b)

    print(count_a)
    print(
        count_b["a"]
    )  # Counter doesn't raise a KeyError if the key doesn't exist. Nice!
    result = []

    for ele in count_a:
        for i in range(0, min(count_a[ele], count_b[ele])):
            result.append(ele)
    return result


print(
    intersection_with_dupes(["a", "b", "c", "b"], ["x", "y", "b", "b"])
)  # -> ["b", "b"]
print(
    alt_intersection_with_dupes(["a", "b", "c", "b"], ["x", "y", "b", "b"])
)  # -> ["b", "b"]
