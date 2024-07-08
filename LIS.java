import java.util.*;
import java.io.*;

class Solution {
    public int lengthOfLIS(int[] nums) {
       ArrayList<Integer>;  
        return 0;
    }
}

public class LIS {
    public static void main(String[] args) {
        // System.out.println("Hello World!");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        Solution obj = new Solution();
        System.out.println(obj.lengthOfLIS(nums));
    }
}