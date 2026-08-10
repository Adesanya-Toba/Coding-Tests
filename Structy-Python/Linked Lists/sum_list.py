"""
Write a function, sum_list, that takes in the head of a linked list containing numbers as an argument.
The function should return the total sum of all values in the linked list.

"""


class Node:
    def __init__(self, val):
        self.val = val
        self.next: Node | None = None


def sum_list(head: Node):
    list_sum = 0
    current = head
    while current is not None:
        list_sum += current.val
        current = current.next

    return list_sum


def sum_list_recursive(head):
    if head is None:
        return 0

    return head.val + sum_list_recursive(
        head.next
    )  # summation is held in the second argument
    # For a linked list A, B, C, D
    # A + B + C + D + return (0)
    # the summation is held here `sum_list_recursive(head.next)`


a = Node(2)
b = Node(8)
c = Node(3)
d = Node(-1)
e = Node(7)

a.next = b
b.next = c
c.next = d
d.next = e

# 2 -> 8 -> 3 -> -1 -> 7

print(sum_list_recursive(a))  # 19
