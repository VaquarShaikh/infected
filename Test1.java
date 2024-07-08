import java.util.*;
import java.io.*;

class Solution {
	public boolean isPalindrome(String s) {
		String cleanData = s.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
		int n = cleanData.length();
		for (int i = 0; i < n / 2; i++) {
			if (cleanData.charAt(i) != cleanData.charAt(n - i - 1))
				return false;
		}
		return true;
	}
}

public class Test1 {
	public static void main(String[] args) {
		// System.out.println("Hello World!!!");

		Scanner sc = new Scanner(System.in);

		String s = sc.nextLine();

		Solution obj = new Solution();

		boolean var = obj.isPalindrome(s);

		System.out.println(var ? "Palindrome" : "Not a palindrome");

	}
}