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

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int startNode) {
  visited[startNode] = true;
  cout << startNode << " ";
  for (int neighbour = 0; neighbour < graph.size(); neighbour++) {
    if (graph[startNode][neighbour] == 1 && !visited[neighbour]) {
      dfs(graph, visited, neighbour);
    }
  }
}

void bfs(vector<vector<int>> &graph, int startNode) {
  queue<int> q;
  vector<bool> visited(graph.size(), false);
  q.push(startNode);
  visited[startNode] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    cout << u << " ";
    for (int neighbour = 0; neighbour < graph.size(); neighbour++) {
      if (graph[u][neighbour] == 1 && !visited[neighbour]) {
        q.push(neighbour);
        visited[neighbour] = true;
      }
    }
  }
}

int main() {
  // cout<<"Hello world !";
  int n;
  cin >> n;
  vector<vector<int>> graph(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> graph[i][j];
    }
  }
  vector<bool> visited(n, false);
  int startNode = 0;
  //   dfs(graph, visited, startNode);
  bfs(graph, startNode);
}