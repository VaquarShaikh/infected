def merge(self , inputArray , left , mid , right):
	leftSubArray = inputArray[left:mid+1]
	rightSubArray = inputArray[mid+1 , right]

	i , j , k = 0 , 0 , left
	while i < len(leftSubArray) and j < len(rightSubArray):
		if leftSubArray[i] <= rightSubArray[j]:
			inputArray[k] = leftSubArray[i]
			i += 1
		else:
			inputArray[k] = rightSubArray[j] 
			j += 1
		k += 1

	while i < len(leftSubArray):
		inputArray[k] = leftSubArray[i]
		i+=1
		k+=1

	while j < len(rightSubArray):
		inputArray[k] = rightSubArray[j]
		j+=1
		k+=1



def mergeSort(self , inputArray ,  left ,  right):
	if left < right:
		mid = left + (right - left)//2
		self.mergeSort(inputArray , left , mid)
		self.mergeSort(inputArray , mid+1 , right)
		self.merge(inputArray , left , mid , right)


def _mergeSort(self , inputArray):
	mergeSort(inputArray , 0 , len(inputArray) - 1)

if __name__ == "__main__":
    inputArray = list(map(int , input().split()))
    _mergeSort(inputArray)
    
    for num in inputArray:
        print(num , end = " ")
    print()