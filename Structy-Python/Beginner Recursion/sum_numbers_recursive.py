"""Watch the Approach video first!

Write a function sum_numbers_recursive that takes in an array
of numbers and returns the sum of all the numbers in the array.
All elements will be integers.

Solve this recursively.
"""


def sum_numbers_recursive(numbers: list):
    # Add my base case
    if len(numbers) == 0:  # Smallest sub problem, where the array is empty
        return 0

    # Add recursive step
    return numbers[0] + sum_numbers_recursive(numbers[1:])


if __name__ == "__main__":
    print(sum_numbers_recursive([5, 2, 9, 10]))  # -> 26
