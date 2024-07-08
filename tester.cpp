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

void dijkstra(int startVertex) {}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	int n;
	cin >> n;

	graph.assign(n, vector<pair<int, int>>());

	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[i].push_back(u);
		graph[i].push_back(v);
		graph[i].push_back(w);
	}
}