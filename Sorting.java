import java.io.*;
import java.util.*;

class Solution {
    void bubbleSort(ArrayList<Integer> inputArray) {
        for (int i = 0; i < inputArray.size(); i++) {
            for (int j = 0; j < inputArray.size() - i - 1; j++) {
                if (inputArray.get(j) > inputArray.get(j + 1)) {
                    Collections.swap(inputArray, j, j + 1);
                }
            }

        }
    }

    void selectionSort(ArrayList<Integer> inputArray) {
        for (int i = 0; i < inputArray.size() - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < inputArray.size(); j++) {
                if (inputArray.get(j) < inputArray.get(min_idx)) {
                    min_idx = j;
                }
                Collections.swap(inputArray, min_idx, i);
            }
        }
    }

    void insertionSort(ArrayList<Integer> inputArray) {
        for (int i = 1; i < inputArray.size(); i++) {
            int key = inputArray.get(i);
            int j = i - 1;
            while (j >= 0 && inputArray.get(j) > key) {
                inputArray.set(j + 1, inputArray.get(j));
                j = j - 1;
            }
            inputArray.set(j + 1, key);
        }
    }

    void merge(ArrayList<Integer> inputArray, int left, int mid, int right) {
        ArrayList<Integer> leftSubArray = new ArrayList<Integer>(inputArray.subList(left, mid + 1));
        ArrayList<Integer> rightSubArray = new ArrayList<Integer>(inputArray.subList(mid + 1, right + 1));

        int i = 0, j = 0, k = left;
        while (i < leftSubArray.size() && j < rightSubArray.size()) {
            if (leftSubArray.get(i) < rightSubArray.get(j)) {
                inputArray.set(k++, leftSubArray.get(i++));
            } else {
                inputArray.set(k++, rightSubArray.get(j++));
            }
        }

        while (j < rightSubArray.size()) {
            inputArray.set(k++, rightSubArray.get(j++));
        }
        while (i < leftSubArray.size()) {
            inputArray.set(k++, leftSubArray.get(i++));
        }

    }

    void mergeSort(ArrayList<Integer> inputArray, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(inputArray, left, mid);
            mergeSort(inputArray, mid + 1, right);
            merge(inputArray, left, mid, right);
        }
    }

    void mergeSort(ArrayList<Integer> inputArray) {
        mergeSort(inputArray, 0, inputArray.size() - 1);
    }

    int partition(ArrayList<Integer> inputArray, int left, int right) {
        int pivot = inputArray.get(right);
        int i = left - 1;
        for (int j = left; j <= right - 1; j++) {
            if (inputArray.get(j) < pivot) {
                i++;
                Collections.swap(inputArray, i, j);
            }
        }
        Collections.swap(inputArray, i + 1, right);
        return (i + 1);
    }

    void quickSort(ArrayList<Integer> inputArray, int left, int right) {
        if (left < right) {
            int pivot = partition(inputArray, left, right);
            quickSort(inputArray, left, pivot - 1);
            quickSort(inputArray, pivot + 1, right);
        }
    }

    void quickSort(ArrayList<Integer> inputArray) {
        quickSort(inputArray, 0, inputArray.size() - 1);
    }

}

class Sorting {
    public static void main(String[] args) {
        Solution obj = new Solution();

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> inputArray = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            inputArray.add(sc.nextInt());
        }

        // obj.bubbleSort(inputArray);
        // obj.insertionSort(inputArray);
        // obj.selectionSort(inputArray);
        // obj.mergeSort(inputArray);
        obj.quickSort(inputArray);

        for (int i = 0; i < inputArray.size(); i++) {
            System.out.print(inputArray.get(i) + " ");
        }
        System.out.println();
        // System.out.println("Hello");
    }
}