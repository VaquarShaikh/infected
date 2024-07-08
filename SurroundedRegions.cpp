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

	if (sx == 0 || sy == 0 || sx == board.size() - 1 ||
		sy == board[0].size() - 1) {
		surroundedByX = false;
	}

	for (const pair<int, int> &direction : directions) {
		int x = sx + direction.first;
		int y = sy + direction.second;
		if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() &&
			visited[x][y] != true && board[x][y] == 'O') {
			if (!dfs(board, visited, x, y, regions)) surroundedByX = false;
		}
	}
	return surroundedByX;
}

void solve(vector<vector<char>> &board) {
	int m = board.size();
	int n = board[0].size();
	vector<pair<int, int>> regions;
	vector<vector<bool>> visited(board.size(),
								 vector<bool>(board[0].size(), false));
	// Counting
	vector<vector<pair<int, int>>> regionss;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'O' && visited[i][j] != true) {
				bool ans = dfs(board, visited, i, j, regions);
				if (ans) { regionss.push_back(regions); }
				regions.clear();
			}
		}
	}
	for (const vector<pair<int, int>> &region : regionss) {
		for (const pair<int, int> &keyVal : region) {
			board[keyVal.first][keyVal.second] = 'X';
		}
	}
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	int m, n;
	cin >> m >> n;

	vector<vector<char>> board(m, vector<char>(n, 0));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) { cin >> board[i][j]; }
	}

	solve(board);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) { cout << board[i][j] << " "; }
		cout << endl;
	}
}

// 4 4
// X X X X
// X O O X
// X X O X
// X O X X