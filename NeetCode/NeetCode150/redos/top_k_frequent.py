"""Given an integer array nums and an integer k,
return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order."""


from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int] | None:
        # Approach: I can use an array, where I use the index of the array 
        # as the count and the value as a list of nums with that frequency.

        # Then I can iterate through the array in reverse and pull out numbers
        # from the lists at the indices until I reach k.

        loaded = [[] for i in range(len(nums) + 1)] # The maximum index number is the length of the array + 1
        # In the case where the array is filled with the same value

        # Count number frequencies using hash map
        count = {}
        for i in nums:
            if i not in count:
                count[i] = 1
            else:
                count[i] += 1
        # print(count)

        # Now, match the frequency of the number with the index of the array and the number with the value
        for num, freq in count.items():
            loaded[freq].append(num)
        # print (loaded)

        # Now iterate through loaded backwards and extract numbers with the until k
        result = []
        for lst in range(len(nums) - 1, 0, -1):
            for num in loaded[lst]:
                result.append(num)
                if len(result) == k:
                    return result
    
    
if __name__ == "__main__":
    sol = Solution()
    print(sol.topKFrequent([1, 1, 2, 3, 3, 4], 3)) # Expected output: [1, 3]
    print(sol.topKFrequent([7, 7, 8, 7, 9], 2)) # Expected output: [7, 8]
    print(
        sol.topKFrequent(
            [
                1,
                1,
                1,
                1,
                2,
                2,
                3,
                3,
                3,
                4,
                4,
                4,
                4,
                5,
                5,
                5,
                5,
                5,
            ],
            3,
        )
    ) # Expected output: [1, 5, 4]