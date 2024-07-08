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

class Compare {
  public:
	bool operator()(int a, int b) const {
		return distances[a] == distances[b] ? a < b
											: distances[a] < distances[b];
	}
};

void dijkstra(int startVertex) {
	int n = graph.size();
	distances.assign(n, INFF);
	predecessor.assign(n, -1);

	distances[startVertex] = 0;
	set<int, Compare> set;

	set.insert(startVertex);

	while (!set.empty()) {
		int v = *set.begin();
		set.erase(set.begin());

		for (const pair<int, int> &edge : graph[v]) {
			int to = edge.first;
			int len = edge.second;

			if (distances[to] > distances[v] + len) {
				set.erase(to);
				distances[to] = distances[v] + len;
				predecessor[to] = v;
				set.insert(to);
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
		// graph[v].push_back({u, w});
	}

	int startVertex;
	cout << "startVertex" << endl;
	cin >> startVertex;

	dijkstra(startVertex);

	for (int i = 0; i < n; i++) {
		cout << "Distance from " << startVertex << " to " << i << " : "
			 << distances[i] << endl;
	}

	// int endVertex;
	// cout << "endVertex" << endl;
	// cin >> endVertex;
	// restorePath(0, endVertex);
}