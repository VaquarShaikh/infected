#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
#define ln "\n"
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 2e18

bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int sx,
		 int sy, vector<pair<int, int>> &regions) {
	vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	visited[sx][sy] = true;
	regions.push_back({sx, sy});
	bool surroundedByX = true;

	for (const pair<int, int> &direction : directions) {
		int x = sx + direction.first;
		int y = sy + direction.second;
		if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() &&
			visited[x][y] != true && board[x][y] == '1') {
			if (!dfs(board, visited, x, y, regions))
				surroundedByX = false;
		}
	}
	return surroundedByX;
}

int numIslands(vector<vector<char>> &board) {
	int m = board.size();
	int n = board[0].size();
	vector<pair<int, int>> regions;
	vector<vector<bool>> visited(board.size(),
								 vector<bool>(board[0].size(), false));
	// Counting
	vector<vector<pair<int, int>>> regionss;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '1' && visited[i][j] != true) {
				bool ans = dfs(board, visited, i, j, regions);
				if (ans) {
					regionss.push_back(regions);
				}
				regions.clear();
			}
		}
	}

	for (const vector<pair<int, int>> &island : regionss) {
		for (const pair<int, int> &isle : island) {
			cout << isle.first << " " << isle.second << endl;
		}
	}

	return regionss.size();
}

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<char>> grid(m, vector<char>(n));

	char c;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			grid[i][j] = c;
		}
	}

	cout << numIslands(grid) << endl;

	return 0;
}

// 4 5
// 1 1 0 0 0
// 1 1 0 0 0
// 0 0 1 0 0
// 0 0 0 1 1

// 4 5
// 1 1 1 1 0
// 1 1 0 1 0
// 1 1 0 0 0
// 0 0 0 0 0