import java.util.*;
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;

class Interval {
    int start;
    int end;

    Interval(int start, int end) {
        this.start = start;
        this.end = end;
    }
}

class SortByStart implements Comparator<Interval> {
    public int compare(Interval a, Interval b) {
        return a.start - b.start;
    }
}

class Solution {
    public ArrayList<Interval> mergeIntervals(ArrayList<Interval> inputArray) {
        Collections.sort(inputArray, new SortByStart());

        Stack<Interval> storeIntervals = new Stack<Interval>();
        storeIntervals.push(inputArray.get(0));

        for (int i = 1; i < inputArray.size(); i++) {
            Interval top = storeIntervals.peek();
            // push
            if (inputArray.get(i).start > top.end) {
                storeIntervals.push(inputArray.get(i));
            }
            // merge
            else if (inputArray.get(i).end > top.end) {
                top.end = inputArray.get(i).end;
                storeIntervals.push(storeIntervals.pop());
            }
        }
        ArrayList<Interval> result = new ArrayList<Interval>();
        while (!storeIntervals.empty()) {
            result.add(storeIntervals.pop());
        }
        Collections.sort(result, new SortByStart());
        return result;
    }
}

class MergeOverlap {
    public static void main(String[] args) {
        // System.out.println();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Interval> inputArray = new ArrayList<Interval>();
        for (int i = 0; i < n; i++) {
            inputArray.add(new Interval(sc.nextInt(), sc.nextInt()));
        }

        Solution obj = new Solution();
        ArrayList<Interval> outputArray = obj.mergeIntervals(inputArray);

        for (int i = 0; i < outputArray.size(); i++) {
            System.out.println(outputArray.get(i).start + " " + outputArray.get(i).end);
        }
    }
}