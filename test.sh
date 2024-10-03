A=()

bubbleSort() {
    n=${#A[@]} # No spaces around = in assignments
    for ((i = 0; i < n; i++)); do
        for ((j = 0; j < n - i - 1; j++)); do
            if [[ ${A[j]} -gt ${A[$((j + 1))]} ]]; then
                # Swap elements
                tempi=${A[j]}
                A[j]=${A[$((j + 1))]}
                A[$((j + 1))]=$tempi
            fi
        done
    done
}

# Example usage
A=(5 2 9 1 5 6)
echo "Before sorting: ${A[@]}"
bubbleSort
echo "After sorting: ${A[@]}"
