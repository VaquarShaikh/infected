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

vector<vector<string>> partition(string s) {
	vector<vector<string>> res;
	vector<string> temp;

	function<bool(int, int)> isPalindrome = [&](int i, int j) {
		while (i < j && s[i] == s[j]) i++, j--;
		return i >= j;
	};

	function<void(int)> dfs = [&](int start) {
		if (start == s.size()) {
			res.push_back(temp);
			return;
		}

		for (int i = start; i < s.size(); i++) {
			if (!isPalindrome(start, i)) continue;
			temp.push_back(s.substr(start, i - start + 1));
			dfs(i + 1);
			temp.pop_back();
		}
	};
	dfs(0);
	return res;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}