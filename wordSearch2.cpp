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

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieNode root;
    vector<string> ans;
    string path;
    int n = board.size(), m = board[0].size();

    if (board.empty() || board[0].empty()) return {};

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    auto addWord = [&](TrieNode* node, string& word) {
        for (char c : word) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->end = true;
    };

    function<void(vector<vector<char>>&, TrieNode*, int, int)> dfs =
        [&](vector<vector<char>>& board, TrieNode* node, int x, int y) {
            char c = board[x][y];
            node = node->next[c - 'a'];
            if (!node) return;
            path.push_back(c);
            board[x][y] = 0;

            if (node->end) {
                ans.push_back(path);
                node->end = false;
            }

            for (auto& [dx, dy] : directions) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= n || b < 0 || b >= m || board[a][b] == 0) continue;
                dfs(board, node, a, b);
            }
            board[x][y] = c;
            path.pop_back();
        };

    for (auto& w : words) addWord(&root, w);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) dfs(board, &root, i, j);

    return ans;
}

int main() {
    // Hello World
    // cout << "Hello world !" << endl;
}