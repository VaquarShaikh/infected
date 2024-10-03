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

bool canPartitionKSubsets(vector<int> &nums, int k) {
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % k) return false;
	int n = nums.size();
	sum /= k;
	vector<int> dp(1 << n, -1);
	dp[(1 << n) - 1] = 1;

	sort(nums.begin(), nums.end(), greater<int>());

	function<bool(int, int)> dfs = [&](int mask, int target) {
		// memo
		if (dp[mask] != -1) return dp[mask];
		dp[mask] = 0;
		if (target == 0) target = sum;	// find new subset

		for (int i = 0; i < n && !dp[mask]; i++) {
			if ((mask >> i & 1) || nums[i] > target) continue;
			dp[mask] = dfs(mask | (1 << i), target - nums[i]);
		}

		return dp[mask];
	};
	return dfs(0, sum);
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}