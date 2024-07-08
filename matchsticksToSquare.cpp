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

bool makesquare(vector<int> &matchsticks) {
	int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
	int n = matchsticks.size();
	if (sum % 4 ||
		*max_element(matchsticks.begin(), matchsticks.end()) > sum / 4)
		return false;
	sum /= 4;

	vector<int> dp(1 << n, -1);

	dp[(1 << n) - 1] = 1;

	function<bool(int, int)> dfs = [&](int mask, int target) {
		// memo
		if (dp[mask] != -1)
			return dp[mask];
		dp[mask] = 0;
		if (target == 0)
			target = sum;

		for (int i = 0; i < n && !dp[mask]; i++) {
			if (mask >> i & 1 || matchsticks[i] > target)
				continue;
			dp[mask] = dfs(mask | 1 << i, target - matchsticks[i]);
		}

		return dp[mask];
	};
	return dfs(0, sum);
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}