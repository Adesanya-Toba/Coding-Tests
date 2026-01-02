"""Design an algorithm to encode a list of strings to a string.
The encoded string is then sent over the network and is decoded
back to the original list of strings.
"""

from typing import List


class Solution:

    def encode(self, strs: List[str]) -> str:
        new_string = ""

        for word in strs:
            new_string += str(len(word)) + "#" + word

        print(new_string)
        return new_string

    def decode(self, s: str) -> List[str]:
        # Read sting to identify word lengths and special characters
        result = []
        word = ""
        idx: int = 0

        while idx < len(s):
            j = idx  # Second pointer to find the length of the word
            while s[j] != "#":
                j += 1  # Increment until the # symbol
            length = int(s[idx:j])
            word = s[j + 1 : j + 1 + length]
            result.append(word)
            idx = j + 1 + length  # remember to increment the index

        print(result)
        return result


if __name__ == "__main__":
    sol = Solution()
    new_word = sol.encode(["hello", "world"])
    sol.decode(new_word)
    new_word = sol.encode(["!@#$%^&*()"])
    sol.decode(new_word)
    # s = "5#hello5#world"
    # print(s[2::])
    # print(s[9::2])
