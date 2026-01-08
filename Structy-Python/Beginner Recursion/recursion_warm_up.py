"""Learning Recursion"""


def countdown(n):
    if n == 0:
        return
    print("Entering " + str(n))
    countdown(n - 1)
    print("Return from " + str(n))


countdown(5)
