#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int maximalRectangle(vector<vector<char>> &matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	vector<vector<pii>> dp(n, vector<pii>(m, make_pair(0, 0)));

	// Initialize dp based on the input matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == '1') {
				dp[i][j] = make_pair(1, 1);
			} else {
				dp[i][j] = make_pair(0, 0);
			}
		}
	}

	// Precomputation
	for (int i = 0; i < m; i++) {
		if (matrix[n - 1][i] == '1') {
			dp[n - 1][i] = make_pair(1, 1);
		}
	}

	// Populate dp based on the precomputation
	for (int i = n - 2; i >= 0; i--) {
		for (int j = m - 2; j >= 0; j--) {
			if (matrix[i][j] == '1') {
				int x = dp[i + 1][j].first;
				int y = dp[i][j + 1].second;
				int z = dp[i + 1][j + 1].first;
				if (x != 0 && y != 0 && z != 0) {
					dp[i][j] = make_pair(dp[i + 1][j].first + 1,
										 dp[i][j + 1].second + 1);
				}
			}
		}
	}

	cout << "dp array : " << endl;

	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[0].size(); j++) {
			cout << dp[i][j].first << " " << dp[i][j].second << "   ";
		}
		cout << endl;
	}

	// Calculate the maximal rectangle area
	int maxArea = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dp[i][j].first > 0 && dp[i][j].second > 0) {
				int height = dp[i][j].first;
				int width = dp[i][j].second;
				maxArea = max(maxArea, height * width);
			}
		}
	}

	return maxArea;
}

int main() {
	int row, col;
	cin >> row >> col;

	vector<vector<char>> matrix(row, vector<char>(col));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			char x;
			cin >> x;
			matrix[i][j] = x;
		}
	}

	cout << maximalRectangle(matrix) << endl;

	return 0;
}