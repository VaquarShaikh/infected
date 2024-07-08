class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def take_input(self):
        head = None
        tail = None

        input_list = list(map(int, input().split()))

        for val in input_list:
            new_node = Node(val)
            if not head:
                head = new_node
                tail = new_node
            else:
                tail.next = new_node
                tail = new_node

        return head

    def print_list(self, head):
        temp = head
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print()

if __name__ == "__main__":
    ll = LinkedList()
    head = ll.take_input()
    ll.print_list(head)
