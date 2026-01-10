"""Write a function, has_subarray_sum, that takes in an list
of numbers and a target_sum. The function should return a boolean
indicating whether or not there exists a subarray of numbers
that sums to the given target.

A subarray is a consecutive series of one or more elements of the list.
"""


def has_subarray_sum(numbers: list, target_sum):

    # Create a prefix sum to start
    prefix_sum = [0]
    sum = 0
    seen: set = set()

    for num in numbers:
        sum += num
        prefix_sum.append(sum)
    # print(prefix_sum)

    for num in prefix_sum:
        if (num - target_sum) not in seen:
            seen.add(num)
        else:
            # print(seen)
            return True
    # print(seen)
    return False


if __name__ == "__main__":
    print(has_subarray_sum([1, 3, 1, 4, 3], 8))  # -> True
    has_subarray_sum([1, 3, 1, 1, 3], 2)  # -> True
    has_subarray_sum([1, 3, 1, 4, 3], 2)  # -> False
    has_subarray_sum([1, 1, 1, 1, 1, 1, 1, 1, 1], 10)  # -> False
