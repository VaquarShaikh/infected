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

struct TrieNode {
	TrieNode* next[26] = {};
	bool end = false;
};

bool wordBreak(string s, vector<string>& wordDict) {
	function<void(TrieNode*, string&)> addWord = [&](TrieNode* node,
													 string& word) {
		for (char c : word) {
			if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
			node = node->next[c - 'a'];
		}
		node->end = true;
	};

	TrieNode root;
	int n = s.size();
	vector<int> dp(n + 1, -1);
	dp[n] = 1;	// used up all words .

	for (auto& w : wordDict) addWord(&root, w);

	function<bool(int)> dfs = [&](int i) {
		// check if the value is pre computated .
		if (dp[i] != -1) return dp[i];
		auto node = &root;
		dp[i] = 0;
		for (int j = i; j < n && node->next[s[j] - 'a']; j++) {
			node = node->next[s[j] - 'a'];
			if (node->end) dp[i] = dfs(j + 1);
			if (dp[i]) break;
		}
		return dp[i];
	};
	return dfs(0);
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}