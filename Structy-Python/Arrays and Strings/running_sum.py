"""Write a function, running_sum, that takes in a list of numbers.

The function should return a new list of the same length where each
element contains the running sum up to that index of the original list.
"""


def running_sum(numbers: list):
    result = []
    sum = 0

    for i in numbers:
        sum += i
        result.append(sum)

    print(result)
    return result


if __name__ == "__main__":
    running_sum([4, 2, 1, 6, 3, 6])  # -> [ 4, 6, 7, 13, 16, 22 ]
    running_sum([10, 5, -2, 1, 1])  # -> [ 10, 15, 13, 14, 15 ]
    running_sum([])  # -> [ ]
