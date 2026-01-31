"""
A phrase is a palindrome if, after converting all uppercase
letters into lowercase letters and removing all non-alphanumeric
characters, it reads the same forward and backward.

Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
"""


class Solution:
    def isPalindrome(self, s: str) -> bool:
        # Using 2-pointer solution

        if len(s) == 0:
            return True

        i: int = 0
        j: int = len(s) - 1

        while i <= j:
            if not s[i].isalnum():
                i += 1
            elif not s[j].isalnum():
                j -= 1
            elif s[i].lower() != s[j].lower():
                return False
            else:
                i += 1
                j -= 1

        return True


if __name__ == "__main__":
    sol = Solution()
    # print(sol.isPalindrome(s="A man, a plan, a canal: Panama"))  # true

    s = "Hello world"
    print(s[1:-1])
