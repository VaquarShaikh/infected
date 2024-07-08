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

int subarraySum(vector<int> &nums, int k) {
	int sum = 0, ans = 0;
	unordered_map<int, int> mapp{{0, 1}};
	for (int num : nums) {
		sum += num;
		auto it = mapp.find(sum - k);
		if (it != mapp.end())
			ans += it->second;
		mapp[sum]++;
	}
	return ans;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}