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

int longestIncreasingPath(vector<vector<int>> &matrix) {
	vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int n = matrix.size(), m = matrix[0].size(), ans = 0;
	if (matrix.empty() || matrix[0].empty()) { return 0; }
	vector<vector<int>> dp(n, vector<int>(m, 0));
	function<int(int, int)> dfs = [&](int x, int y) {
		if (dp[x][y]) return dp[x][y];

		dp[x][y] = 1;
		for (auto &dir : directions) {
			int a = x + dir.first, b = y + dir.second;
			if (a >= 0 && b >= 0 && a < n && b < m &&
				matrix[a][b] > matrix[x][y])
				dp[x][y] = max(dp[x][y], dfs(a, b) + 1);
		}

		return dp[x][y];
	};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { ans = max(ans, dfs(i, j)); }
	}
	return ans;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}