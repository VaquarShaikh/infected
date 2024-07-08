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

int numSubarrayProductLessThanK(vector<int> &nums, int k) {
	long i = 0, j = 0, n = nums.size(), prod = 1, ans = 0;
	for (; j < n; j++) {
		prod *= nums[j];
		while (i <= j && prod >= k) {
			prod /= nums[i];
			i++;
		}
		ans += (j - i + 1);
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

	cin >> k;

	cout << numSubarrayProductLessThanK(nums, k) << endl;
}