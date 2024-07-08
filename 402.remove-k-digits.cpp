/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution {
  public:
	string removeKdigits(string num, int k) {
		int n = num.size();
		stack<char> stack;
		string res;

		//  basic template
		for (int i = 0; i < n; i++) {
			while (!stack.empty() && stack.top() > num[i] && k > 0) {
				stack.pop();
				k--;
			}
			stack.push(num[i]);
		}
		// handle the corner case
		while (!stack.empty() && k > 0) {
			stack.pop();
			k--;
		}

		// copy the generated result
		while (!stack.empty()) {
			res.push_back(stack.top());
			stack.pop();
		}
		// result generated in reverse
		reverse(res.begin(), res.end());

		//  remove leading 0
		int start = 0;
		while (start < res.size() && res[start] == '0') {
			start++;
		}

		res = res.substr(start);

		return res.empty() ? "0" : res;
	}
};
// @lc code=end
