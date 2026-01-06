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

    # for i in hash_a:
    #     if i in b:
    #         min_val = min(hash_a[i], hash_b[i])

    #         result.append(i * min_val)

    for key in hash_a:
        if key in hash_b:
            for i in range(min(hash_a[key], hash_b[key])):
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


print(
    intersection_with_dupes(["a", "b", "c", "b"], ["x", "y", "b", "b"])
)  # -> ["b", "b"]
