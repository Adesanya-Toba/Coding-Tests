def pair_product(number: list, target_product: int):
    loaded: dict = {}

    for idx, val in enumerate(number):
        if target_product / val in loaded:
            return (idx, loaded[target_product / val])
        loaded[val] = idx


print(pair_product([3, 2, 5, 4, 1], 8))
