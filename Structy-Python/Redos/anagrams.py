def anagrams(s1, s2) -> bool:
    """Check if two words are anagrams of each other.

    Anagrams are words that contain the same letters in a different order.

    Args:
        s1 (str): The first word.
        s2 (str): The second word.
    Returns:
        bool: True if the words are anagrams, False otherwise.
    """
    if char_counter(s1) == char_counter(s2):
        return True
    return False


def char_counter(s1: str) -> dict:
    char_count: dict = {}

    for char in s1:
        if char not in char_count:
            char_count[char] = 1
        else:
            char_count[char] += 1

    print(char_count)
    return char_count


if __name__ == "__main__":
    print(anagrams("hello", "elloh"))
