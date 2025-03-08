"""
Time:O(n)
Space: O(n)

Write a function, most_frequent_char, that takes in
a string as an argument. The function should return
the most frequent character of the string. If there
are ties, return the character that appears earlier
in the string.

You can assume that the input string is non-empty.
"""


def most_frequent_char(s):

    str_dict: dict = {}

    # Count chars in the string
    for char in s:
        if char not in str_dict:
            str_dict[char] = 1
        else:
            str_dict[char] += 1

    # I want to return the char with the largest value
    print(str_dict)

    max_char = None
    for char in s:
        if max_char is None or str_dict[char] > str_dict[max_char]:
            max_char = char

    print(max_char)
    return max_char


most_frequent_char("helloo")
