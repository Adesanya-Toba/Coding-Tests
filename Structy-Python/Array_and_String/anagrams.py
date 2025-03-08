"""
Time: O(n + m)
Space: O(n + m)
"""


def anagrams(s1, s2):
    # I think I'll create a dict of the first string
    # Then iterate through the second or not, to see if the keys
    # exist in the string.

    # An edge case to consider is strings with duplicate letters
    # e.g. hello vs helo -> False

    # Maybe I can use the index as the key as it is enumerated
    # and will always be unique. Then I check against the
    # value instead of the key.

    # The solution was to use 2 dicts and store the count of each letter
    # encountered.

    str_dict1: dict = {}
    str_dict2: dict = {}

    for letter in s1:
        if letter not in str_dict1:
            str_dict1[letter] = 0

        str_dict1[letter] += 1

    for letter in s2:
        if letter not in str_dict2:
            str_dict2[letter] = 1
        else:
            str_dict2[letter] += 1

    print(str_dict1)
    print(str_dict2)

    if str_dict1 == str_dict2:
        return True

    return False


print(anagrams("hello", "elloh"))


def anagrams_alternate(s1, s2):
    return char_count(s1) == char_count(s2)


def char_count(s):
    count = {}

    for char in s:
        if char not in count:
            count[char] = 0
        count[char] += 1

    return count


print(anagrams_alternate("hello", "elloh"))
