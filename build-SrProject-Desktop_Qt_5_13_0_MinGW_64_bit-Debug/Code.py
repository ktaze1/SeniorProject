class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
    
    def reverse(self, root, k):
        current = root
        next = prev = None
        count = 0


        while(current is not None and count <k):
            next = current.next
            current.next = prev
            prev = current
            current = next
            count += 1


        if next is not None:
            root.next = self.reverse(next, k)


        return prev


    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node


    def printList(self):
        temp = self.head
        while(temp):
            print (temp.data)
            temp = temp.next


Llist = LinkedList()
Llist.push(9)
Llist.push(8)
Llist.push(7)
Llist.push(6)
Llist.push(5)
Llist.push(4)
Llist.push(3)
Llist.push(2)
Llist.push(1)


Llist.printList()
Llist.head = Llist.reverse(Llist.head, 3)

print("\n\n\n\n\n\n")
Llist.printList()

