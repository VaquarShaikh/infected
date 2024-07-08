class Queue:
	def __init__(self ,initialCapacity):
		if(initialCapacity < 1):
			print("Size should be atleast 1")
		self._capacity = initialCapacity
		self._data = [None] * self._capacity
		self._frontIndex , self._rearIndex , self._size = -1 , -1 , 0
		
		
	def getSize(self):
		return self._size

	def isEmpty(self):
		return self._size == 0

	def isFull(self):
		return self._size == self._capacity

	def enqueue(self , val):
		if self._isFull():
			print("Queue is full , resizing")
		resize(capacity * 2)
		self._rearIndex = (self._rearIndex + 1)%self._capacity
		