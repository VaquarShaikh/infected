#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <set>
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

vector<int> findEulerianPath(vector<vector<int>> &graph) {
  int n = graph.size();
  vector<int> deg(n);
  for (int i = 0; i < graph.size(); ++i) {
    int val = graph[i].size();
    deg[i] = val;
  }

  int first = 0;
  while (first < n && !deg[first]) {
    ++first;
  }
  if (first == n) {
    return vector<int>();
  }

  int v1 = -1, v2 = -1;
  bool bad = false;
  for (int i = 0; i < n; ++i) {
    if (deg[i] & 1) {
      if (v1 == -1) {
        v1 = i;
      } else if (v2 == -1) {
        v2 = i;
      } else {
        bad = true;
      }
    }
  }

  if (v1 != -1) {
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
  }

  // cout << "v1 v2 first" << endl;
  // cout << v1 << " " << v2 << " " << first << endl;

  stack<int> st;
  vector<int> res;
  st.push(first);

  while (!st.empty()) {
    int v = st.top();
    int i = 0;

    while (i < graph[v].size()) {
      if (graph[v][i] != -1) {
        break;
      }
      i++;
    }

    // for (i = 0; i < graph[v].size(); ++i) {
    //   if (graph[v][i] != -1) {
    //     break;
    //   }
    // }

    if (i == graph[v].size()) {
      res.push_back(v);
      st.pop();
    } else {
      int neighbour = graph[v][i];
      graph[v][i] = -1;
      for (int j = 0; j < graph[neighbour].size(); ++j) {
        if (graph[neighbour][j] == v) {
          graph[neighbour][j] = -1;
          break;
        }
      }
      st.push(neighbour);
    }
  }
  // cout << "res array at this point :" << endl;
  // for (int i = 0; i < res.size(); i++) {
  //   cout << res[i] << " ";
  // }
  // cout << endl;
  // reordering
  if (v1 != -1) {
    for (size_t i = 0; i + 1 < res.size(); ++i) {
      if ((res[i] == v1 && res[i + 1] == v2) ||
          (res[i] == v2 && res[i + 1] == v1)) {
        vector<int> res2;
        for (size_t j = i + 1; j < res.size(); ++j) {
          res2.push_back(res[j]);
        }
        for (size_t j = 1; j <= i; ++j) {
          res2.push_back(res[j]);
        }
        res = res2;
        break;
      }
    }
  }

  // check for isolated vertices
  for (int i = 0; i < n; ++i) {
    for (int neighbour : graph[i]) {
      if (neighbour != -1) {
        bad = true;
        break;
      }
    }
  }

  if (bad) {
    return vector<int>();
  } else {
    return res;
  }
}

int main() {
  // cout<<"Hello world !";
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  vector<int> eulerPath = findEulerianPath(graph);

  for (size_t i = 0; i < eulerPath.size(); ++i) {
    cout << eulerPath[i] << " ";
  }
  cout << endl;
}