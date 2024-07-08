import java.io.*;
import java.util.*;

class Solution {

    // void sort(ArrayList<)
    void merge(ArrayList<Integer> inputArray, int left, int mid, int right) {
        ArrayList<Integer> leftSubArray = new ArrayList<>(inputArray.subList(left, mid + 1));
        ArrayList<Integer> rightSubArray = new ArrayList<>(inputArray.subList(mid + 1, right + 1));

        int i = 0, j = 0, k = left;

        while (i < leftSubArray.size() && j < rightSubArray.size()) {
            if (leftSubArray.get(i) <= rightSubArray.get(j)) {
                inputArray.set(k++, leftSubArray.get(i++));
            } else {
                inputArray.set(k++, rightSubArray.get(j++));
            }
        }

        while (i < leftSubArray.size()) {
            inputArray.set(k++, leftSubArray.get(i++));
        }

        while (j < rightSubArray.size()) {
            inputArray.set(k++, rightSubArray.get(j++));
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
}

public class MergeSort {
    public static void main(String[] args) {
        // System.out.println("GHejifhs");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        ArrayList<Integer> inputArray = new ArrayList<Integer>();

        for (int i = 0; i < n; i++) {
            inputArray.add(sc.nextInt());
        }

        Solution obj = new Solution();

        obj.mergeSort(inputArray);
        for (int i = 0; i < inputArray.size(); i++) {
            System.out.print(inputArray.get(i) + " ");
        }
    }
}
