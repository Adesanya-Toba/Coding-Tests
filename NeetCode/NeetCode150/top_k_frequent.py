"""Given an integer array nums and an integer k,
return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order."""

from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int] | None:

        # Create an empty list of lists of length nums + 1.
        freq: list[list] = [[] for i in range(len(nums) + 1)]
        print(freq)
        # Can be a max of len(nums) + 1,
        # because that's the worst case if the same value was repeated in mums n times

        # Count frequencies/occurrences using a hash map
        count: dict[int, int] = {}
        for num in nums:
            if num not in count:
                count[num] = 1
            else:
                count[num] += 1

        for n, c in count.items():
            freq[c].append(n)
            # This will update the frequency list to have the 'index' as the 'count'
            # and the value as the list of numbers with that count.
            # idx.,  0  |    1   |    2   | 3  | 4  | 5  | 6  |; shows the count/frequency
            # nums,  [] | [2, 4] | [1, 3] | [] | [] | [] | [] |; shows the numbers with that count

        print(freq)

        result = []
        # Doing the below to extract the top k highest occurring numbers
        for i in range(len(freq) - 1, 0, -1):  # Iterate through frequency in reverse
            for n in freq[i]:
                result.append(
                    n
                )  # Don't worry about appending empty elements, they don't count
                if len(result) == k:
                    print(result)
                    return result

    # Time: O(n), Space: O(n)


if __name__ == "__main__":
    sol = Solution()
    sol.topKFrequent([1, 1, 2, 3, 3, 4], 4)
    sol.topKFrequent([7, 7, 8, 7, 9], 2)
    sol.topKFrequent(
        [
            1,
            1,
            1,
            1,
            1,
            1,
        ],
        1,
    )
