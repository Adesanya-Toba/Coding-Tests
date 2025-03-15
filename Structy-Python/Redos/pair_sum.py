def pair_sum(numbers: list, target: int):
    # This is a pair problem, remember to use complements and dict
    # The dict will store the value as key and index as value
    # Indices must be unique

    # Strategy here is take the complement (8-3 = 5), and check if
    # 5 exists in my dict, if so return the indices of both
    # Otherwise, store the value and move to the next

    num_dict = {}

    for idx, num in enumerate(numbers):
        if (target - num) in num_dict:
            return num_dict[target - num], idx
        num_dict[num] = idx


print(pair_sum([3, 2, 5, 4, 1], 8))
print(pair_sum([9, 9], 18))
