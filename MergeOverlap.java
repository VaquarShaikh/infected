import java.util.*;
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
    void mergeIntervals(ArrayList<Interval> inputArray) {
        Collections.sort(inputArray, new SortByStart());
        int index = 0;
        for (int i = 1; i < inputArray.size(); i++) {
            // overlapping condition
            if (inputArray.get(index).end >= inputArray.get(i).start) {
                inputArray.set(index, new Interval(inputArray.get(index).start,
                        Math.max(inputArray.get(index).end, inputArray.get(i).end)));
            } else {
                inputArray.set(++index, new Interval(inputArray.get(i).start, inputArray.get(i).end));
            }
        }
        System.out.println("Merged Intervals : ");
        for (int i = 0; i <= index; i++) {
            System.out.println(inputArray.get(i).start + " " + inputArray.get(i).end);
        }
    }
}

public class MergeOverlap {
    public static void main(String[] args) {
        // System.out.println("Hello World!");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Interval> inputArray = new ArrayList<Interval>();
        for (int i = 0; i < n; i++) {
            inputArray.add(new Interval(sc.nextInt(), sc.nextInt()));
        }
        Solution obj = new Solution();
        obj.mergeIntervals(inputArray);

    }
}