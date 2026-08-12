"""
Write a function, get_node_value, that takes in the head of a linked list and an index.
The function should return the value of the linked list at the specified index.

If there is no node at the given index, then return None.
"""


class Node:
    def __init__(self, val):
        self.val = val
        self.next: Node | None = None


def get_node_value(head: Node, index):
    count = 0
    current: Node | None = head

    while current is not None:
        if index == count:
            return current.val
        count += 1
        current = current.next
    return None


a = Node("a")
b = Node("b")
c = Node("c")
d = Node("d")

a.next = b
b.next = c
c.next = d

# a -> b -> c -> d

print(get_node_value(a, 2))  # 'c'
