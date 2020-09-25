Q. Given an integer K and a single linked list of N nodes where nodes can contain values from 1 to K only,
the task is to sort the linkedlist in-place.

Note : Consider node value to be immutable, i.e. node.value must not be changed, we are allow to change node.next only.

Solution : 

from random import randint


class Node:

    def __init__(self, value=None):
        self.data = value
        self.next = None


class LinkedList:

    def __init__(self):
        self.head = Node()

    def insert(self, value):
        temp = self.head
        while temp.next is not None:
            temp = temp.next
        temp.next = Node(value)

    def printLinked(self):
        temp = self.head.next
        while temp is not None:
            print(temp.data, end=" ")
            temp = temp.next

    def Sort(self):
        d = {}
        temp = self.head.next
        while temp is not None:
            if d.get(temp.data, None) is None:
                d[temp.data] = []
            d[temp.data].append(temp)
            temp = temp.next
        temp = self.head
        # print(d)
        for key in sorted(d.items()):
            for val in key[1]:
                temp.next = val
                temp = temp.next
        temp.next = None


l = LinkedList()
for i in range(100):
    l.insert(randint(100, 220))
l.printLinked()
l.Sort()
print()
print("Sorted:")
l.printLinked()
