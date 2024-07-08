#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
#define ln "\n"
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 2e18

void bfs(vector<vector<int>> &edges, int startNode) {
	vector<bool> visited(edges.size(), false);
	queue<int> q;
	q.push(startNode);
	visited[startNode] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cout << u << " ";
		for (int v : edges[u]) {
			if (!visited[v]) {
				q.push(v);
				visited[v] = true;
			}
		}
	}
}

int main() {
	// cout<<"Hello world !";
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int startNode = 0;
	bfs(edges, startNode);
}

// 5 4
// 0 1
// 1 2
// 1 3
// 0 4