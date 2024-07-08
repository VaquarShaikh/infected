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

vector<string> wordBreak(string s, vector<string>& wordDict) {
	vector<string> res, temp;
	int n = s.size();
	TrieNode root;

	function<void(TrieNode*, string&)> addWord = [&](TrieNode* node,
													 string& word) {
		for (char c : word) {
			if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
			node = node->next[c - 'a'];
		}
		node->end = true;
	};

	function<void(int)> dfs = [&](int i) {
		auto node = &root;
		for (auto& w : wordDict) addWord(&root, w);

		if (i == n) {
			string line;
			for (auto& w : temp) {
				if (line.size()) line += ' ';
				line += w;
			}
			res.push_back(line);
			return;
		}

		for (int j = i; j < n && node->next[s[j] - 'a']; j++) {
			node = node->next[s[j] - 'a'];
			// do something
			if (node->end) {
				temp.push_back(s.substr(i, j - i + 1));
				dfs(j + 1);
				temp.pop_back();
			}
		}
	};
	dfs(0);
	return res;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}