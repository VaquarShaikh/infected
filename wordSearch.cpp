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

bool exist(vector<vector<char>>& board, string word) {
    int n = board.size(), m = board[0].size();
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    function<bool(int, int, int)> dfs = [&](int x, int y, int i) {
        // base case
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != word[i]) return false;
        if (i == word.size() - 1) return true;
        char c = board[x][y];
        board[x][y] = 0;
        for (auto& [dx, dy] : directions)
            if (dfs(x + dx, y + dy, i + 1)) return true;
        board[x][y] = c;
        return false;
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (dfs(i, j, 0)) return true;
    return false;
}

int main() {
    // Hello World
    // cout << "Hello world !" << endl;
}