package main

var A []int

func mergeSort() {
	temp := make([]int, len(A))

	var merge_sort func(left, right int)
	merge_sort = func(left, right int) {
		if left+1 >= right {
			return
		}
		mid := left + (right-left)/2
		i, j, k := left, mid, right

		merge_sort(left, mid)
		merge_sort(mid, right)

		for i < mid || j < right {
			if j >= right || (i < mid && A[i] < A[j]) {
				temp[k] = A[i]
				i++
			} else {
				temp[k] = A[j]
				j++
			}
		}

		for i := left; i < right; i++ {
			temp[i] = A[i]
		}

	}

	merge_sort(0, len(A))
}
