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

int minSubArrayLen(int target, vector<int> &nums) {
	long i = 0, j = 0, ans = INT_MAX, n = nums.size(), sum = 0;
	for (; j < n; j++) {
		sum += nums[j];
		while (sum >= target) {
			ans = min(ans, j - i + 1);
			sum -= nums[i];
			i++;
		}
	}
	return ans;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	int n, target;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	cin >> target;

	cout << minSubArrayLen(target, nums) << endl;
}