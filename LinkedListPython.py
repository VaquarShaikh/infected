class Node:
	def __init__(self , data):
		self.data = data
		self.next = None

class LinkedList:
	def takeInput(self):
		head = None
		tail = None

		input_values = list(map(int , input().split()))

		for val in input_values:
			newNode = Node(val)
			if not head:
				head = newNode
				tail = newNode
			else:
				tail.next = newNode
				tail = newNode
		return head
	
	def printList(self , head):
		temp = head
		while temp:
			print(temp.data , end = " ")
			temp = temp.next
		print()

	def reverseList(self , head):
		if head is None or head.next is None:
			return head
		smallAns = self.reverseList(head.next)
		tail = head.next 
		tail.next = head
		head.next = None
		return smallAns

if __name__ == "__main__":
	ll = LinkedList()
	head = ll.takeInput()
	ll.printList(head)

	head = ll.reverseList(head)  # Update head with the reversed list
	ll.printList(head)