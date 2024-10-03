#!/bin/bash

# Define an array to store the input numbers
A=()

# Function for bubble sort
bubbleSort() {
    n=${#A[@]}
    for ((i = 0; i < n; i++)); do
        for ((j = 0; j < n - i - 1; j++)); do
            if [ ${A[j]} -gt ${A[$((j + 1))]} ]; then
                # Swap elements
                temp=${A[j]}
                A[$j]=${A[$((j + 1))]}
                A[$((j + 1))]=$temp
            fi
        done
    done
}

# Function for merge sort
merge() {
    local start=$1
    local mid=$2
    local end=$3
    local i=$start
    local j=$mid
    local k=0
    local temp=()

    while [ $i -lt $mid ] && [ $j -lt $end ]; do
        if [ ${A[i]} -le ${A[j]} ]; then
            temp[$k]=${A[i]}
            ((i++))
        else
            temp[$k]=${A[j]}
            ((j++))
        fi
        ((k++))
    done

    while [ $i -lt $mid ]; do
        temp[$k]=${A[i]}
        ((i++))
        ((k++))
    done

    while [ $j -lt $end ]; do
        temp[$k]=${A[j]}
        ((j++))
        ((k++))
    done

    for ((i = 0; i < k; i++)); do
        A[$((start + i))]=${temp[$i]}
    done
}

mergeSortHelper() {
    local start=$1
    local end=$2

    if [ $((end - start)) -le 1 ]; then
        return
    fi

    local mid=$((start + (end - start) / 2))
    mergeSortHelper $start $mid
    mergeSortHelper $mid $end
    merge $start $mid $end
}

mergeSort() {
    mergeSortHelper 0 ${#A[@]}
}

# Function for quick sort
quickSortHelper() {
    local left=$1
    local right=$2

    if [ $left -ge $right ]; then
        return
    fi

    local pivotIndex=$((left + RANDOM % (right - left + 1)))
    local pivotValue=${A[pivotIndex]}

    # Move pivot to the end
    local temp=${A[pivotIndex]}
    A[$pivotIndex]=${A[$right]}
    A[$right]=$temp

    local storeIndex=$left

    for ((i = $left; i < $right; i++)); do
        if [ ${A[i]} -lt $pivotValue ]; then
            # Swap A[i] and A[storeIndex]
            temp=${A[i]}
            A[$i]=${A[$storeIndex]}
            A[$storeIndex]=$temp
            ((storeIndex++))
        fi
    done

    # Move pivot to its final place
    temp=${A[$storeIndex]}
    A[$storeIndex]=${A[$right]}
    A[$right]=$temp

    quickSortHelper $left $((storeIndex - 1))
    quickSortHelper $((storeIndex + 1)) $right
}

quickSort() {
    quickSortHelper 0 $((${#A[@]} - 1))
}

# Main script logic
echo "Enter 5 integers:"
for ((i = 0; i < 5; i++)); do
    read -p "Enter number $((i + 1)): " temp
    A+=($temp)
done

# Choose the sorting algorithm
# Uncomment the one you want to use
# bubbleSort
# mergeSort
quickSort

# Print sorted array
echo "Sorted array:"
echo "${A[@]}"
