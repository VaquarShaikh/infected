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

int atMost(vector<int> &nums, int k) {
	int i = 0, j = 0, n = nums.size(), ans = 0;
	for (; j < n; j++) {
		k -= nums[j] % 2;
		while (k < 0) k += nums[i++] % 2;
		ans += (j - i + 1);
	}
	return ans;
}

int numberOfSubarrays(vector<int> &nums, int k) {
	return atMost(nums, k) - atMost(nums, k - 1);
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}