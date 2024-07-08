import java.util.*;
import java.io.*;

class Solution {

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

public class QuickSort {
    public static void main(String[] args) {
        // System.out.println("Hello");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> inputArray = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            inputArray.add(sc.nextInt());
        }

        Solution obj = new Solution();
        obj.quickSort(inputArray);
        for (int i = 0; i < inputArray.size(); i++) {
            System.out.print(inputArray.get(i) + " ");
        }
        System.out.println();
    }
}