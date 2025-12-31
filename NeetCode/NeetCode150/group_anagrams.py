"""Given an array of strings strs, group all anagrams together
into sublists. You may return the output in any order.
"""

from collections import defaultdict
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # Using a default dict to prepopulate the dict with empty lists
        res = defaultdict(list)
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord("a")] += 1
            # The res dict is of the form: {(tuple): [list]}
            res[tuple(count)].append(s)  # Casting to tuple as list is not hashable

        return list(res.values())  # return just the values of the dict

    # Time: O(m * n), Space: O(m); m is the number of strings and n is the longest string


if __name__ == "__main__":
    strs = ["act", "pots", "tops", "cat", "stop", "hat"]
    sol = Solution()
    print(sol.groupAnagrams(strs))

    t1 = {"a1", 'c1, "t1'}
    t2 = {"c1", "a1", "t1"}

    print(t1 == t2)
