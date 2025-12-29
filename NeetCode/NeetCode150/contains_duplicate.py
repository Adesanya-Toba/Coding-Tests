"""Given an integer array nums, return true if any
value appears more than once in the array, otherwise
return false."""


class Solution:
    def hasDuplicate(self, nums: list[int]) -> bool:
        # Load nums into a dictionary
        loaded: dict = {}

        for num in nums:
            if num in loaded:
                return True
            loaded[num] = 0
        return False


if __name__ == "__main__":
    sol = Solution()
    print(sol.hasDuplicate(nums=[1, 2, 3, 4, 4]))
