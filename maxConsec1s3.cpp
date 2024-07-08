#include <algorithm>
#include <climits>
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
typedef pair<int, int> pii;
#define ln "\n"
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 2e18
#define INFF 1000000009

int longestOnes(vector<int> &nums, int k) {
	long i = 0, j = 0, n = nums.size(), cnt = 0, ans = 0;
	for (; j < n; j++) {
		cnt += nums[j] == 0;
		while (cnt > k) {
			cnt -= nums[i++] == 0;
		}
		ans = max(ans, j - i + 1);
	}
	return ans;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	int n, k;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	cout << longestOnes(nums, k) << endl;
}