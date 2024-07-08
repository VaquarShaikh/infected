class Solution {
  public:
	int orangesRotting(vector<vector<int>> &grid) {
		int m = grid.size();
		int n = grid[0].size();
		int freshCount = 0;
		int minutes = 0;
		queue<pair<int, int>> rottenQueue;
		vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		// calculate fresh oranges and rotten oranges but push them in the queue
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					freshCount++;
				} else if (grid[i][j] == 2) {
					rottenQueue.push(make_pair(i, j));
				}
			}
		}
		// iterate till queue is empty but greater than freshCount
		while (!rottenQueue.empty()) {
			int queueSize = rottenQueue.size();
			for (int k = 0; k < queueSize; k++) {
				int rOx = rottenQueue.front().first;
				int rOy = rottenQueue.front().second;
				rottenQueue.pop();
				for (const pair<int, int> &dir : directions) {
					int x = rOx + dir.first;
					int y = rOy + dir.second;
					if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
						//   freshCount--;
						grid[x][y] = 2;
						rottenQueue.push(make_pair(x, y));
					}
				}
			}
			minutes++;
		}
		cout << "freshCount : " << freshCount << endl;
		cout << "minutes : " << minutes << endl;
		return (freshCount == 0) ? minutes : -1;
	}
};