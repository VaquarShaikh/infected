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
  for (int i = 0; i < n; i++) {
    cout << i << " → ";
    for (int j = 0; j < edges[i].size(); j++) {
      cout << edges[i][j];
      if (j < edges[i].size() - 1) {
        cout << " → ";
      }
    }
    cout << endl;
  }
}