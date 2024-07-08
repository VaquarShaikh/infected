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

int eraseOverlapIntervals(vector<vector<int>> &intervals) {
	int n = intervals.size(), end = INT_MIN, ans = 0;
	sort(intervals.begin(), intervals.end(),
		 [](auto const &a, auto const &b) -> bool { return a[1] < b[1]; });
	for (auto &x : intervals) {
		if (x[0] <= end)
			end = x[1];
		else
			ans++;
	}
	return ans;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;

	int n;
	cin >> n;

	vector<vector<int>> intervals;

	for (int i = 0; i < n; i++) {
		vector<int> temp;
		int u, v;
		cin >> u >> v;
		temp.push_back(u);
		temp.push_back(v);
		intervals.push_back(temp);
	}

	cout << eraseOverlapIntervals(intervals) << endl;
}