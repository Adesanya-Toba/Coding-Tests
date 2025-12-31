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

    # Time: O(n + m), Space: O(n); where n and m are the lengths of s and t.

    def isAnagramNoDict(self, s: str, t: str) -> bool:

        if len(s) != len(t):
            return False
        # Solving with just arrays instead
        char_freq = [0] * 26  # array of 26 zeros to represent the alphabet

        # Iterate through both strings, incrementing seen chars for one while
        # decrementing for the other

        for i in range(len(s)):
            # ******** ord() assumes all words are in lowercase *********
            char_freq[ord(s[i]) - ord("a")] += 1  # Increment alphabet index when seen
            char_freq[ord(t[i]) - ord("a")] -= 1  # Decrement alphabet index when seen

        # char_freq should be all zeros if the words are anagrams
        return (
            len(set(char_freq)) == 1
        )  # This is because converting to a set will remove duplicates
        # We can also use a simple for loop.

    # Time: O(n), Space: O(1) because we use at most 26 characters.


if __name__ == "__main__":
    sol = Solution()
    print(sol.isAnagram("racecar", "carrace"))
    print(sol.isAnagramNoDict("racecar", "carrace"))
