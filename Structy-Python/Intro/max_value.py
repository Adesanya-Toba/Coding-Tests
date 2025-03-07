"""
Time: O(n)
Space: O(1)
"""

import math


def max_value(nums: list):
    """
    Time complexity: O(n), as we iterate through the list
    Space: O(1), we only store one value.
    """
    # max: float = -math.inf  # negative infinity
    max = float("-inf")  # Another way to represent infinity in Python
    for num in nums:
        if num > max:
            max = num

    print(max)
    return max


max_value([-5, -2])
