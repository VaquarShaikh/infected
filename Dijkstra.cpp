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
vector<bool> visited;

void dijkstra(int startVertex) {
	int n = graph.size();
	distances.assign(n, INFF);
	predecessor.assign(n, -1);
	visited.assign(n, false);

	distances[startVertex] = 0;
	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if (!visited[j] && (v == -1 || distances[j] < distances[v]))
				v = j;
		}

		if (distances[v] == INFF)
			break;

		visited[v] = true;
		for (const pair<int, int> &edge : graph[v]) {
			int to = edge.first;
			int len = edge.second;
			if (distances[to] > distances[v] + len) {
				distances[to] = distances[v] + len;
				predecessor[to] = v;
			}
		}
	}
}

vector<int> restorePath(int startVertex, int endVertex) {
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

	dijkstra(0);

	for (int i = 0; i < n; i++) {
		cout << "distances from 0 to : " << i << " " << distances[i] << endl;
	}

	int endVertex;
	cout << "endVertex" << endl;
	cin >> endVertex;

	vector<int> restoredPath = restorePath(0, endVertex);
	for (int i = 0; i < restoredPath.size(); i++) {
		cout << restoredPath[i] << " ";
	}
	cout << endl;
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