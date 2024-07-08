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

// code but a bit optimised
vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
				   greater<>>
		pq;

	vector<vector<int>> resultsArray;

	for (auto const &datapoint : points) {
		int distSq = datapoint[0] * datapoint[0] + datapoint[1] * datapoint[1];
		pq.push({distSq, {datapoint[0], datapoint[1]}});
	}

	while (k-- > 0 && !pq.empty()) {
		auto [distSq, point] = pq.top();
		resultsArray.push_back({point.first, point.second});
		pq.pop();
	}
	return resultsArray;
}

// my code
// vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
// 	vector<vector<int>> resultsArray;
// 	auto cmp = [](auto const &a, auto const &b) -> bool {
// 		return a.first > b.first;
// 	};
// 	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
// 				   decltype(cmp)>
// 		pq(cmp);
// 	for (const auto &datapoint : points) {
// 		int distSq = datapoint[0] * datapoint[0] + datapoint[1] * datapoint[1];
// 		pq.push({distSq, {datapoint[0], datapoint[1]}});
// 	}
// 	int count = 0;
// 	while (!pq.empty() && count < k) {
// 		vector<int> temp;
// 		auto top = pq.top();
// 		pq.pop();
// 		temp.push_back(top.second.first);
// 		temp.push_back(top.second.second);
// 		resultsArray.push_back(temp);
// 		count++;
// 	}
// 	return resultsArray;
// }

int main() {
	// Hello World
	// cout << "Hello world !" << endl;

	int n, k;
	cin >> n;

	vector<vector<int>> points;

	for (int i = 0; i < n; i++) {
		vector<int> temp;
		int u, v;
		cin >> u >> v;
		temp.push_back(u);
		temp.push_back(v);
		points.push_back(temp);
	}
	cin >> k;
	vector<vector<int>> res = kClosest(points, k);
	for (auto const &x : res)
		cout << x[0] << " " << x[1] << endl;
	cout << endl;
}