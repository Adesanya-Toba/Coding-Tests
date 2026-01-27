"""Write a function, subarray_sum_count, that takes in an
list of numbers and a targetSum. The function should
return the number of subarrays that sum to the given target.

A subarray is a consecutive series of one or more elements
of the list.
"""

from collections import Counter


def subarray_sum_count(numbers, target_sum):
    # Create the prefix sum
    prefix_sum = [0]
    sum = 0

    for num in numbers:
        sum += num
        prefix_sum.append(sum)

    seen = Counter()
    count = 0
    for current in prefix_sum:
        complement = current - target_sum
        count += seen[complement]
        seen[current] += 1

    return count


# Time: O(n), Space: O(n)


if __name__ == "__main__":
    print(subarray_sum_count([1, 3, 1, 4, -2, 3], 5))  # -> 3
    print(subarray_sum_count([1, 3, 1, 4, 3], 5))  # -> 2
