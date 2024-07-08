#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define ln "\n"
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 2e18
#define INFF 1000000009

vector<string> letterCombinations(string digits) {
	vector<string> ans;
	string temp,
		dialPad[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	function<void(int)> dfs = [&](int i) {
		if (i == digits.size()) {
			ans.push_back(temp);
			return;
		}

		for (char c : dialPad[digits[i] - '2']) {
			temp.push_back(c);
			dfs(i + 1);
			temp.pop_back();
		}
	};
	dfs(0);
	return ans;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}