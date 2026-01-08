"""Given an integer array nums, return an array output where
output[i] is the product of all the elements of nums except nums[i].

Each product is guaranteed to fit in a 32-bit integer.
You are not allowed to use the division operator
"""

from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        result = [1] * len(nums)

        prefix = 1
        for i in range(len(nums)):
            result[i] = prefix
            prefix *= nums[i]
        print(result)

        postfix = 1
        for i in range(len(nums) - 1, -1, -1):
            result[i] *= postfix
            postfix *= nums[i]

        print(result)
        return result

    # Time: O(n), Space: O(1)


if __name__ == "__main__":
    sol = Solution()
    sol.productExceptSelf([1, 2, 3, 4])  # [24,12, 8, 6]
