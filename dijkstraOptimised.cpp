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

vector<vector<pair<int, int>>> graph;
vector<int> distances;
vector<int> predecessor;

void dijkstra_set(int startVertex) {
	int n = graph.size();
	distances.assign(n, INFF);
	predecessor.assign(n, -1);

	distances[startVertex] = 0;

	set<pair<int, int>> q;
	q.insert({0, startVertex});

	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());

		for (const pair<int, int> &edge : graph[v]) {
			int to = edge.first;
			int len = edge.second;
			if (distances[to] > distances[v] + len) {
				q.erase({distances[to], to});
				distances[to] = distances[v] + len;
				predecessor[to] = v;
				q.insert({distances[to], to});
			}
		}
	}
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;

	int n, m;
	cin >> n >> m;

	graph.assign(n, vector<pair<int, int>>());

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}

	int startVertex;
	cout << "startVertex : " << endl;
	cin >> startVertex;

	dijkstra_set(startVertex);

	for (int i = 0; i < n; i++) {
		cout << "Distance from " << startVertex << " to " << i << " : "
			 << distances[i] << endl;
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << "Distance from 0 to " << i << " : " << distances[i] << endl;
	// }
}

// 6 8
// 0 2 4
// 0 3 2
// 2 3 3
// 3 5 1
// 2 5 1
// 5 4 2
// 4 1 1
// 2 1 9