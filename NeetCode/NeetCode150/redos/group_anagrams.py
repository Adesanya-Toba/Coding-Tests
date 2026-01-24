"""Given an array of strings strs, group all anagrams together
into sublists. You may return the output in any order.
"""

from collections import defaultdict
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        return [[]]