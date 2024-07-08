#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <set>
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

bool dfs(vector<vector<int>> &graph, vector<bool> &visited, int startNode,
         bool color, unordered_map<int, bool> &mapp) {
  // hello world
  visited[startNode] = true;
  mapp[startNode] = color;
  for (int neighbour : graph[startNode]) {
    // if it is visited or not visited.
    if (!visited[neighbour]) {
      if (!dfs(graph, visited, neighbour, !color, mapp)) {
        return false;
      }
    } else {
      if (mapp[neighbour] == mapp[startNode]) {
        return false;
      }
    }
  }
  return true;
}

bool isBipartite(vector<vector<int>> &graph) {
  int n = graph.size();
  if (graph.size() == 1) {
    return true;
  }
  unordered_map<int, bool> mapp;
  vector<bool> visited(n, false);
  int color = true;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      if (!dfs(graph, visited, i, color, mapp)) {
        return false;
      }
    }
  }
  return true;
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
  isBipartite(graph) ? cout << "is bipartite" << endl
                     : cout << "not bipartite" << endl;
}

// 4 4
// 0 1
// 0 2
// 2 1
// 2 3

// 4 5
// 0 1
// 0 2
// 0 3
// 2 1
// 2 3