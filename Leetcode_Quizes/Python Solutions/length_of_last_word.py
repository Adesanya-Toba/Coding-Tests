"""Given a string s consisting of words and spaces, return the length of the
last word in the string.

A word is a maximal substring consisting of non-space characters only.
"""


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        idx: int = len(s) - 1
        cnt: int = 0

        while idx >= 0:
            if s[idx] == " " and cnt > 0:
                break
            elif s[idx] == " ":
                idx -= 1
            else:
                cnt += 1
                idx -= 1
        return cnt
