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

bool dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int sx,
		 int sy, vector<pair<int, int>> &enclave) {
	vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	visited[sx][sy] = true;
	enclave.push_back({sx, sy});
	bool surroundedBy0 = true;

	if (sx == 0 || sy == 0 || sx == grid.size() - 1 ||
		sy == grid[0].size() - 1) {
		surroundedBy0 = false;
	}

	for (const pair<int, int> &direction : directions) {
		int x = sx + direction.first;
		int y = sy + direction.second;
		if (x >= 0 && y >= 0 && x < grid.size() && sy < grid[0].size() &&
			visited[x][y] != true && grid[x][y] == 1) {
			if (!dfs(grid, visited, x, y, enclave)) {
				surroundedBy0 = false;
			}
		}
	}
	return surroundedBy0;
}

int numEnclaves(vector<vector<int>> &grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<bool>> visited(m, vector<bool>(n, false));

	vector<pair<int, int>> enclave;
	vector<vector<pair<int, int>>> enclaves;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 1 && !visited[i][j]) {
				if (dfs(grid, visited, i, j, enclave)) {
					enclaves.push_back(enclave);
				}
				enclave.clear();
			}
		}
	}

	int count = 0;
	for (int i = 0; i < enclaves.size(); i++) {
		count += enclaves[i].size();
	}
	return count;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	int m, n;
	cin >> m >> n;
	vector<vector<int>> grid(m, vector<int>(n, 0));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	// numEnclaves(grid);

	cout << numEnclaves(grid) << endl;
}

// 4 4
// 0 0 0 0
// 1 0 1 0
// 0 1 1 0
// 0 0 0 0

// 4 4
// 0 1 1 0
// 0 0 1 0
// 0 0 1 0
// 0 0 0 0