def merge(inputArray, left, mid, right):
    leftSubArray = inputArray[left:mid + 1]
    rightSubArray = inputArray[mid + 1:right + 1]

    i, j, k = 0, 0, left
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
        i += 1
        k += 1

    while j < len(rightSubArray):
        inputArray[k] = rightSubArray[j]
        j += 1
        k += 1


def mergeSort(inputArray, left, right):
    if left < right:
        mid = left + (right - left) // 2
        mergeSort(inputArray, left, mid)
        mergeSort(inputArray, mid + 1, right)
        merge(inputArray, left, mid, right)


def sort(inputArray):
    mergeSort(inputArray, 0, len(inputArray) - 1)


if __name__ == "__main__":
    inputArray = list(map(int, input().split()))
    sort(inputArray)

    for num in inputArray:
        print(num, end=" ")
    print()
