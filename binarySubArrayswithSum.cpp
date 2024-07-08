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

int atMost(vector<int> &nums, int goal) {
	int i = 0, j = 0, ans = 0, sum = 0, n = nums.size();
	for (; j < n; j++) {
		sum += nums[j];
		while (i <= j && sum > goal) sum -= nums[i++];
		ans += (j - i);
	}
	return ans;
}

int numSubarraysWithSum(vector<int> &nums, int goal) {
	return atMost(nums, goal) - atMost(nums, goal - 1);
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}