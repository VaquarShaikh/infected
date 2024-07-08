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

void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited,
         vector<int> &component) {
  visited[node] = true;
  component.push_back(node);
  for (int neighbor : graph[node]) {
    if (!visited[neighbor]) {
      dfs(graph, neighbor, visited, component);
    }
  }
}

vector<vector<int>> findConnectedComponents(vector<vector<int>> &graph) {
  vector<bool> visited(graph.size(), false);
  vector<vector<int>> connectedComponents;
  for (int i = 0; i < graph.size(); i++) {
    if (!visited[i]) {
      vector<int> component;
      dfs(graph, i, visited, component);
      connectedComponents.push_back(component);
    }
  }
  return connectedComponents;
}

int main() {
  // cout<<"Hello world !";
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<vector<int>> connectedComponents = findConnectedComponents(graph);
  int count = 1;
  for (const vector<int> &component : connectedComponents) {
    cout << count++ << ": ";
    for (int node : component) {
      cout << node << " ";
    }
    cout << endl;
  }
}

// 10 6
// 0 1
// 1 2
// 3 4
// 4 5
// 6 7
// 8 9