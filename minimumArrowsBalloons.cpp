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

int findMinArrowShots(vector<vector<int>> &points) {
	sort(points.begin(), points.end(),
		 [](auto const &a, auto const &b) -> bool { return a[1] < b[1]; });
	int n = points.size(), end = points[0][1], ans = 1;
	for (auto &x : points) {
		if (x[0] > end) {
			end = x[1];
			ans++;
		}
	}
	return ans;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}