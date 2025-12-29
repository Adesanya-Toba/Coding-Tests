"""Given two strings s and t, return true if the two strings
are anagrams of each other, otherwise return false.

An anagram is a string that contains the exact same character
as another string, but the order of the characters can be different.
"""


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Return immediately if strings are different lengths
        if len(s) != len(t):
            return False
        return self.check_chars(s) == self.check_chars(t)

    def check_chars(self, word: str) -> dict:
        char_store: dict = {}

        for idx, c in enumerate(word):
            if c in char_store:
                char_store[c.lower()] += 1
            else:
                char_store[c.lower()] = 1

        return char_store


if __name__ == "__main__":
    sol = Solution()
    print(sol.isAnagram("racecar", "caRrace"))
