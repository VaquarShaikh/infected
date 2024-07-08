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

vector<vector<int>> subsets(vector<int> &nums) {
	int n = nums.size();
	vector<vector<int>> res;
	for (int mask = 0; mask < (1 << n); mask++) {
		vector<int> temp;
		for (int i = 0; i < n; i++) {
			if (mask >> i & 1)
				temp.push_back(nums[i]);
		}
		res.push_back(temp);
	}
	return res;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}