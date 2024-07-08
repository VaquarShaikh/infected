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

void dijkstra(int startVertex) {
	int n = graph.size();
	distances.assign(n, INFF);
	predecessor.assign(n, INFF);

	using pii = pair<int, int>;

	priority_queue<pii, vector<pii>, greater<pii>> pq;

	distances[startVertex] = 0;
	pq.push({0, startVertex});
	while (!pq.empty()) {
		int v = pq.top().second;
		int d_v = pq.top().first;
		pq.pop();

		if (d_v != distances[v])
			continue;

		for (const pair<int, int> &edge : graph[v]) {
			int to = edge.first;
			int len = edge.second;
			if (distances[to] > distances[v] + len) {
				distances[to] = distances[v] + len;
				predecessor[to] = v;
				pq.push({distances[to], to});
			}
		}
	}
}

vector<int> restorePaths(int startVertex, int endVertex) {
	vector<int> path;
	for (int v = endVertex; v != startVertex; v = predecessor[v]) {
		path.push_back(v);
	}
	path.push_back(startVertex);
	reverse(path.begin(), path.end());
	return path;
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
	cout << "startVertex" << endl;
	cin >> startVertex;

	dijkstra(startVertex);

	for (int i = 0; i < n; i++) {
		cout << "Distance from " << startVertex << "upto " << i << " : "
			 << distances[i] << endl;
	}

	int endVertex;
	cout << "endVertex" << endl;
	cin >> endVertex;

	vector<int> restoredPath = restorePaths(startVertex, endVertex);

	for (int i = 0; i < restoredPath.size(); i++) {
		cout << restoredPath[i] << " ";
	}
	cout << endl;
}