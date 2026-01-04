"""Write a function, all_unique, that takes in a list. The function
should return a boolean indicating whether or not the list
contains unique items."""


def all_unique(items):
    unique_items = set(items)
    return len(unique_items) == len(items)


if __name__ == "__main__":
    print(all_unique(["q", "r", "s", "a"]))
