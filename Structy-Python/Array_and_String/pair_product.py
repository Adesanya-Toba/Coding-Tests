"""
Time: O(n)
Space: O(n)

Write a function, pair_product, that takes in a list and
a target product as arguments. The function should return
a tuple containing a pair of indices whose elements multiply
to the given target. The indices returned must be unique.
"""


def pair_product(numbers, target_product):
    # This looks like it would similar to pair_sum
    # i.e., using a mix of dictionary and complements
    # to arrive at the indices

    loaded = {}

    for idx, val in enumerate(numbers):
        if (target_product / val) in loaded:
            return (loaded[target_product / val], idx)
        loaded[val] = idx


print(pair_product([3, 2, 5, 4, 1], 8))
