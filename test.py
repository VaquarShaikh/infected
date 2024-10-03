A = []

def bubbleSort():
	global A
	n = len(A)
	for i in range(n):
		for j in range(n - i - 1):
			if A[j] > A[j+1]:
				A[j] , A[j+1] = A[j+1] , A[j]

def mergeSort():
	temp = [0]*len(A)
	def merge_sort(left , right):
		if left + 1 >= right:
			return
		mid = left + (right - left)//2
		i , j , k = left , mid , left
		merge_sort(left , mid)
		merge_sort(mid , right)
		while i < mid or j < right:
			if j >= right or (i < mid and A[i] < A[j]):
				temp[k] = A[i]
				i+=1
			else:
				temp[k] = A[j]
				j+=1
			k+=1
		for i in range(left , right):
			A[i] = temp[i]

	merge_sort(0 , len(A))

if __name__ == "__main__":
	print("Hello world")