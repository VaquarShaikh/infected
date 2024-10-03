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

int minimumTotal(vector<vector<int>>& triangle) {
	int sum = triangle[0][0];
	function<void(int)> dfs = [&](int i) {
		if (i == triangle.size()) return;
		sum += min(sum + triangle[i][i], sum + triangle[i][i - 1]);
		dfs(i + 1);
	};
	dfs(1);
	return sum;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}