"""
Time: O(sqrt(1))
Space: O(1)
"""

from math import sqrt, floor


def is_prime(n):
    # Check is n is divisible by any possible factors of n
    # This is from 2 to n-1
    """Time: O(n) solution, Space: O(1)"""
    for factor in range(2, n):
        if n % factor == 0:
            print(factor)
            return False
    return True


def is_prime_OsqrtN(n):
    """Optimizing to reduce time complexity to O(sqrtN)
    Space: O(1)
    """
    # Handle edge cases
    if n <= 1:
        return False

    # We will check for factors till the sqrt of N (inclusive)
    for factor in range(2, floor(sqrt(n)) + 1):
        if n % factor == 0:
            print(factor)
            return False
    return True


print(is_prime_OsqrtN(4))
print(int(3.1))
