#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
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
#define INFF 1000000009

vector<vector<int>> heights;
vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int minimumEffortPath(vector<vector<int>> &heights) {
	int rows = heights.size();
	int cols = heights[0].size();

	auto cmp = [](const auto &a, const auto &b) {
		return a[0] > b[0]; // Compare efforts
	};

	priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
	pq.push({0, 0, 0}); // {effort, row, col}

	vector<vector<int>> efforts(rows, vector<int>(cols, INF));
	efforts[0][0] = 0;

	while (!pq.empty()) {
		auto current = pq.top();
		pq.pop();

		int effort = current[0];
		int row = current[1];
		int col = current[2];

		if (row == rows - 1 && col == cols - 1) {
			return effort;
		}

		for (const auto &dir : directions) {
			int newRow = row + dir[0];
			int newCol = col + dir[1];

			if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
				int newEffort = max(
					effort, abs(heights[row][col] - heights[newRow][newCol]));
				if (newEffort < efforts[newRow][newCol]) {
					efforts[newRow][newCol] = newEffort;
					pq.push({newEffort, newRow, newCol});
				}
			}
		}
	}

	return -1; // Unreachable
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	int n;
	cin >> n;

	heights.assign(n, vector<int>());

	for (int i = 0; i < n; i++) {
		int u, v, w;
		heights[i].push_back(u);
		heights[i].push_back(v);
		heights[i].push_back(w);
	}

	cout << minimumEffortPath(heights) << endl;
}