#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
	int n = grid.size();
	if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
		return -1;

	vector<pair<int, int>> directions = {{1, 0}, {-1, 0},  {0, 1},	{0, -1},
										 {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

	queue<pair<pair<int, int>, int>> q; // ((row, col), distance)
	q.push({{0, 0}, 1});				// starting cell
	grid[0][0] = 1;						// mark as visited

	while (!q.empty()) {
		int row = q.front().first.first;
		int col = q.front().first.second;
		int distance = q.front().second;
		q.pop();

		if (row == n - 1 && col == n - 1)
			return distance;

		for (const auto &dir : directions) {
			int new_row = row + dir.first;
			int new_col = col + dir.second;
			if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < n &&
				grid[new_row][new_col] == 0) {
				q.push({{new_row, new_col}, distance + 1});
				grid[new_row][new_col] = 1; // mark as visited
			}
		}
	}

	return -1;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	cout << shortestPathBinaryMatrix(grid) << endl; // Output: 4

	return 0;
}

// 3
// 0 0 0
// 1 1 0
// 1 1 0