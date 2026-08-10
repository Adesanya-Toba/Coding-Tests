class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


a = Node('A')
b = Node('B')
c = Node('C')
d = Node('D')

a.next = b
b.next = c
c.next = d

def print_list(head):
    current = head
    while current is not None:
        print(current.val)
        current = current.next

print_list(a)