import java.util.*;
import java.io.*;
import java.util.function.Consumer;

class Solution {
	public List<String> letterCombinations(String digits) {
		List<String> ans = new ArrayList<>();
		StringBuilder temp = new StringBuilder();

		String[] dialPad = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

		Consumer<Integer> dfs = new Consumer<Integer>() {
			public void accept(Integer i) {
				if (i == ans.size()) {
					ans.add(temp.toString());
					return;
				}
				for (char c : dialPad[digits.charAt(i) - '2'].toCharArray()) {
					temp.append(c);
					accept(i + 1);
					temp.deleteCharAt(temp.length() - 1);
				}
			}
		};
		dfs.accept(0);
		return ans;
	}
}

public class PhoneNumber {
	public static void main(String[] args) {
		System.out.println("Hello");
	}
}