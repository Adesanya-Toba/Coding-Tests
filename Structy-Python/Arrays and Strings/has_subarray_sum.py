"""Write a function, has_subarray_sum, that takes in an list
of numbers and a target_sum. The function should return a boolean
indicating whether or not there exists a subarray of numbers
that sums to the given target.

A subarray is a consecutive series of one or more elements of the list.
"""


def has_subarray_sum(numbers, target_sum):
    sum = 0

    for i in numbers:
        sum += i
        if sum == target_sum:
            return True
        elif sum > target_sum:
            return False


if __name__ == "__main__":
    has_subarray_sum([1, 3, 1, 4, 3], 8)  # -> True
    has_subarray_sum([1, 3, 1, 1, 3], 2)  # -> True
    has_subarray_sum([1, 3, 1, 4, 3], 2)  # -> False
    has_subarray_sum([1, 1, 1, 1, 1, 1, 1, 1, 1], 10)  # -> False
