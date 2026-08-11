"""
Write a function, linked_list_find, that takes in the head of a linked list and a target value.
The function should return a boolean indicating whether or not the linked list contains the target.
"""


class Node:
    def __init__(self, val):
        self.val = val
        self.next: Node | None = None


def linked_list_find(head: Node, target: str):
    # Simple solution would be O(n), where I simply loop through the linked list

    # Check if ll is empty, return False
    if head is None:
        return False

    # Check if head is target, return True
    if head.val == target:
        return True

    # Loop through and early return when found
    current = head
    while current is not None:
        if current.val == target:  # target is 'd'
            return True
        current = current.next

    # Else, return False
    return False


a = Node("a")
b = Node("b")
c = Node("c")
d = Node("d")

a.next = b
b.next = c
c.next = d

# a -> b -> c -> d

print(linked_list_find(a, "c"))  # True
