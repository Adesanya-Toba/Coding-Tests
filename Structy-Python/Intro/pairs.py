"""15/03/2025
Time: O(n^2)
Space: O(n^2)

Write a function, pairs, that takes in a list as an argument.
The function should return an list contain all unique pairs of elements.

You may return the pairs in any order and the order of elements within
a single pair does not matter.

You can assume that the input list contains unique elements.
"""


def pairs(elements: list):
    # This looks like an O(n^2) problem.
    # Hmm, hang-on that might be wrong, as you can't have (b,b) or (c,a)
    # when you've had (a,c)

    # The key is you only need to move forward in the inner loop

    result_list = []

    for i in range(len(elements)):
        for j in range(i + 1, len(elements)):
            result_list.append([elements[i], elements[j]])

    print(result_list)
    return result_list


pairs(["a", "b", "c"])


list1 = ["a", "b"]
list2 = ["b", "a"]
