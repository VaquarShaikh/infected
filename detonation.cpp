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

int dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
  int count = 1;
  visited[node] = true;
  for (int neighbour : adj[node]) {
    if (!visited[neighbour]) {
      count += dfs(neighbour, adj, visited);
    }
  }
  return count;
}

int maximumDetonation(vector<vector<int>> &bombs) {
  int n = bombs.size();
  vector<vector<int>> adj(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      int x = abs(bombs[i][0] - bombs[j][0]);
      int y = abs(bombs[i][1] - bombs[j][1]);
      if (pow(x, 2) + pow(y, 2) <= pow(bombs[i][2], 2)) {
        adj[i].push_back(j);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    vector<bool> visited(n, false);
    ans = max(ans, dfs(i, adj, visited));
  }
  return ans;
}

int main() {
  // cout<<"Hello world !";
  int n;
  cin >> n;
  vector<vector<int>> bombs(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> bombs[i][j];
    }
  }
  cout << maximumDetonation(bombs);
}

// 5
// 1 2 3 2 3 1 3 4 2 4 5 3 5 6 4