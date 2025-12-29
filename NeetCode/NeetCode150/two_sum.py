"""Given an array of integers nums and an integer target,
return the indices i and j such that nums[i] + nums[j] == target and i != j.

You may assume that every input has exactly one pair of
indices i and j that satisfy the condition.

Return the answer with the smaller index first.
"""


class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        # Using the complement method to get the indices

        loaded: dict = {}

        for idx, num in enumerate(nums):
            if (target - num) not in loaded:
                loaded[num] = idx
            else:
                # This works because the hash map/dict can only store unique keys
                # and will hit the else block once the same key has been seen.
                return [loaded[target - num], idx]

        # Time= O(n), Space O(n)


if __name__ == "__main__":
    sol = Solution()
    print(sol.twoSum([4, 5, 6], 10))
    nums = [4, 5, 6, 2, 1]

    A = []
    for i, num in enumerate(nums):
        A.append([num, i])

    A.sort()
    print(A)
