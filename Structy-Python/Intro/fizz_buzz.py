"""15/03/2025
Time: O(n)
Space: O(n)

Write a function, fizz_buzz, that takes in a number n as an argument.
The function should return a list containing numbers from 1 to n,
replacing certain numbers according to the following rules:

if the number is divisible by 3, make the element "fizz"
if the number is divisible by 5, make the element "buzz"
if the number is divisible by 3 and 5, make the element "fizzbuzz"

"""


def fizz_buzz(n):

    fizz_list = []

    for i in range(1, n + 1):
        if i % 3 == 0 and i % 5 == 0:
            fizz_list.append("fizzbuzz")
        elif i % 3 == 0:
            fizz_list.append("fizz")
        elif i % 5 == 0:
            fizz_list.append("buzz")
        else:
            fizz_list.append(i)
    print(fizz_list)
    return fizz_list


fizz_buzz(16)
