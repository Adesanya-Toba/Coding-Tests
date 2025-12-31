"""Given an integer array nums and an integer k,
return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order."""

from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        result: list = []
        load: dict[int, int] = {}
        for num in nums:
            if num not in load:
                load[num] = 1
            else:
                load[num] += 1

        print(load)

        for val in load.values():
            result.append(val)

        result.sort(reverse=True)
        print(result[:-1])
        return []


if __name__ == "__main__":
    sol = Solution()
    sol.topKFrequent([1, 2, 2, 3, 3, 3], 2)
    sol.topKFrequent([7, 7], 1)
