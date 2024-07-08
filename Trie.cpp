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
	int count = 0;
};

class Trie {
   private:
	TrieNode root;

	TrieNode* searchToNode(string& prefix) {
		auto node = &root;
		for (char c : prefix) {
			if (!node->next[c - 'a']) return NULL;
			node = node->next[c - 'a'];
		}
		return node;
	}

   public:
	void insert(string word) {
		auto node = &root;
		for (char c : word) {
			if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
			node = node->next[c - 'a'];
		}
		node->count++;
	}

	bool search(string word) {
		auto node = searchToNode(word);
		return node && node->count;
	}

	bool startsWith(string prefix) { return searchToNode(prefix); }
};

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}