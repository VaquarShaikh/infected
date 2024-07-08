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

void dfs(vector<vector<int>> &edges, vector<bool> &visited, int startNode) {
  visited[startNode] = true;
  cout << startNode << " ";
  for (int neighbor : edges[startNode]) {
    if (!visited[neighbor]) {
      dfs(edges, visited, neighbor);
    }
  }
  cout << endl;
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
  vector<bool> visited(n, false);
  int startNode = 0;
  dfs(edges, visited, startNode);
}

// 5 6
// 0 1
// 0 2
// 1 3
// 1 2
// 4 3
// 4 2