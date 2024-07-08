#include <algorithm>
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
#define ln "\n"
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 2e18
#define INFF 1000000000

vector<int> distances;

class Compare {
  public:
	bool operator()(int a, int b) const {
		return distances[a] == distances[b] ? a < b
											: distances[a] < distances[b];
	}
};

int networkDelayTime(vector<vector<int>> &times, int n, int k) {
	// int n = graph.size();
	distances.assign(n + 1, INFF);

	distances[k] = 0;
	set<int, Compare> set;

	set.insert(k);

	while (!set.empty()) {
		int v = *set.begin();
		set.erase(set.begin());

		for (int i = 0; i < times.size(); i++) {
			int from = times[i][0];
			int to = times[i][1];
			int len = times[i][2];

			if (from == v && distances[to] > distances[v] + len) {
				set.erase(to);
				distances[to] = distances[v] + len;
				set.insert(to);
			}
		}
	}
	int minVal = -1;
	for (int i = 1; i < n + 1; i++) {
		minVal = max(minVal, distances[i]);
	}

	return minVal == INFF ? -1 : minVal;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	int s;
	cin >> s;
	vector<vector<int>> times(s);

	for (int i = 0; i < s; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		times[i].push_back(u);
		times[i].push_back(v);
		times[i].push_back(w);
	}

	int n, k;
	cin >> n >> k;

	cout << networkDelayTime(times, n, k) << endl;

	for (int i = 1; i < n + 1; i++) {
		cout << "distance from " << k << " upto " << i << " " << distances[i]
			 << endl;
	}
}