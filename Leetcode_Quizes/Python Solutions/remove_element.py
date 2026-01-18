"""Given an integer array nums and an integer val, remove all
occurrences of val in nums in-place. The order of the elements may be changed.
Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k,
to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain
the elements which are not equal to val. The remaining elements of
nums are not important as well as the size of nums.
Return k.
"""

from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i: int = 0
        j: int = len(nums) - 1

        while i <= j:
            if nums[i] != val:
                i += 1
            else:
                if nums[j] != val:
                    temp = nums[i]
                    nums[i] = nums[j]
                    nums[j] = temp
                else:
                    j -= 1

        print(nums)
        print(j + 1)
        return j + 1

    def altRemoveElement(self, nums: List, val: int) -> int:
        k = 0

        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1
        return k


if __name__ == "__main__":
    sol = Solution()
    sol.removeElement([3, 2, 2, 3], 3)  # 2
    sol.removeElement(
        [0, 1, 2, 2, 3, 0, 4, 2], 2
    )  # Output: 5, nums = [0,1,4,0,3,_,_,_]
    sol.removeElement([2], 3)  # [2]
    #                  i = 0 k = 0
    #                [0, 1, 2, 2, 3, 0, 4, 2]
    #                                k     i
    #                [0, 1, 3, 0, 4,]
    #                 [0,1,4,0,3,2,2,2]

    # i = 0, j = 7
    # [2,2,3,3]
