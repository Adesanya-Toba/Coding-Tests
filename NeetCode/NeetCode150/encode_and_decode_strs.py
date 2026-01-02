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
        count: int = 0

        for idx, char in enumerate(s):
            if char.isnumeric():
                count = int(char)
            if char == "#":
                word = s[idx + 1 : count + idx + 1]
                result.append(word)

        print(result)
        return result


if __name__ == "__main__":
    sol = Solution()
    new_word = sol.encode(["hello", "world"])
    sol.decode(new_word)
    # s = "5#hello5#world"
    # print(s[2::])
    # print(s[9::2])
