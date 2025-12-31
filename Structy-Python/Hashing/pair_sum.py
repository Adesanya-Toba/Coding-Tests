"""
Time:O(n)
Space: O(n)

Write a function, pair_sum, that takes in a list and a
target sum as arguments. The function should return a
tuple containing a pair of indices whose elements sum
to the given target. The indices returned must be unique
"""


def pair_sum(numbers, target_sum):
    # Remove any element in the list that might be
    # greater or equal to the target. Technically, we could have
    # 0 or negative numbers, so no.

    # This looks like an o(n^2) time problem

    # Let's start with the most un-optimal solution
    # Looping through the array twice. Returning the first
    # pair it finds

    for val in range(len(numbers)):
        for val2 in range(1, len(numbers)):
            if numbers[val] + numbers[val2] == target_sum:
                print(val, val2)
                return (val, val2)


def pair_sum_opt(numbers, target_sum):
    # The key is load the list into a dict and use
    # the complement i.e. target - current number
    # to arrive at the required indices.

    loaded = {}

    for cnt, val in enumerate(numbers):
        if (target_sum - val) in loaded:
            return (loaded[target_sum - val], cnt)

        loaded[val] = cnt


print(pair_sum_opt([3, 2, 5, 4, 1], 8))
print(pair_sum_opt([9, 9], 18))
