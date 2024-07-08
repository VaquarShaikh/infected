import java.util.*;
import java.io.*;

class Solution {
	public boolean isAnagram(String s, String t) {
		int n = s.length();
		int m = t.length();
		if (n != m) {
			return false;
		}
		ArrayList<Integer> frequencyMap = new ArrayList<>(27);
		for (int i = 0; i < frequencyMap.size(); i++) {
			frequencyMap.set(i, 0);
		}
		for (int i = 0; i < n; i++) {

		}

		return false;
	}
}

public class Anagram {
	public static void main(String[] args) {
		// System.out.println("Hello World");
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		String t = sc.nextLine();
		Solution obj = new Solution();
		System.out.println(obj.isAnagram(s, t) ? "Anagram" : "Not an anagram");
	}
}