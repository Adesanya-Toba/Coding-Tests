"""
Write a function, linked_list_values, that takes in the head of a linked list as an argument.
The function should return a list containing all values of the nodes in the linked list.
"""


class Node:
    def __init__(self, val):
        self.val = val
        self.next: Node | None = None


def linked_list_values(head: Node):
    current = head
    result = []
    while current is not None:
        result.append(current.val)
        current = current.next
    return result


a = Node("a")
b = Node("b")
c = Node("c")
d = Node("d")

a.next = b
b.next = c
c.next = d

# a -> b -> c -> d

print(linked_list_values(a))  # -> [ 'a', 'b', 'c', 'd' ]
