"""Learning Recursion"""


def countdown(n):
    if n == 0:  # Base case
        return
    print("Entering " + str(n))

    # Recursive step
    countdown(n - 1)
    print("Return from " + str(n))


countdown(5)
