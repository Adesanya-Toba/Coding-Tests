"""15/03/2025
Time: O(n)
Space: O(n)

Write a function, longest_word, that takes in a sentence
string as an argument. The function should return the longest
word in the sentence. If there is a tie, return the word
that occurs later in the sentence.

You can assume that the sentence is non-empty.
"""


def longest_word(sentence: str):
    # I would use the split method to split on whitespace to identify words
    # I might use a dict to keep records of longest words
    # I also need a variable to keep max length? Maybe

    sentence_dict: dict = {}
    max_length: int = 0

    for word in sentence.split():
        word_len = len(word)
        sentence_dict[word_len] = word
        if max_length < word_len:
            max_length = word_len

    print(sentence_dict)
    print(f"Max word length: {sentence_dict[max_length]}")
    return sentence_dict[max_length]


def longest_word_opt(sentence: str):
    longest = ""

    for word in sentence.split():
        if len(word) >= len(longest):
            longest = word
    print(longest)
    return longest


longest_word_opt("the quick brown fox jumped over the lazy dog")
