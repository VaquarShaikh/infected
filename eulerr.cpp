#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> findEulerPath(vector<vector<int>> &adjList) {
  int n = adjList.size();
  vector<int> deg(n);

  for (int i = 0; i < n; ++i) {
    int val = adjList[i].size();
    deg[i] = val;
    // for (int neighbor : adjList[i]) {
    //   deg[i]++;
    // }
  }

  cout << "degree array :" << endl;

  for (int i = 0; i < deg.size(); i++) {
    cout << deg[i] << " ";
  }
  cout << endl;

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
    adjList[v1].push_back(v2);
    adjList[v2].push_back(v1);
  }

  cout << v1 << " " << v2 << " " << first << endl;

  stack<int> st;
  vector<int> res;
  st.push(first);

  while (!st.empty()) {
    int v = st.top();
    int i = 0;
    while (i < adjList[v].size()) {
      int neighbor = adjList[v][i];
      if (adjList[v][i] != -1) {
        break;
      }
      i++;
    }

    if (i == adjList[v].size()) {
      res.push_back(v);
      st.pop();
    } else {
      int neighbor = adjList[v][i];
      adjList[v][i] = -1;
      for (int j = 0; j < adjList[neighbor].size(); ++j) {
        if (adjList[neighbor][j] == v) {
          adjList[neighbor][j] = -1;
          break;
        }
      }
      st.push(neighbor);
    }
  }

  cout << "res at this point in euler" << endl;
  for (int vertex : res) {
    cout << vertex << " ";
  }
  cout << endl;

  if (v1 != -1) {
    for (size_t i = 0; i + 1 < res.size(); ++i) {
      if ((res[i] == v1 && res[i + 1] == v2) ||
          (res[i] == v2 && res[i + 1] == v1)) {
        vector<int> res2;
        for (size_t j = i + 1; j < res.size(); ++j) {
          if (res[j] != -1) {
            res2.push_back(res[j]);
          }
        }
        for (size_t j = 1; j <= i; ++j) {
          if (res[j] != -1) {
            res2.push_back(res[j]);
          }
        }
        res = res2;
        break;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int neighbor : adjList[i]) {
      if (neighbor != -1) {
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
  int n, m;
  cin >> n >> m;

  // Initialize an adjacency list
  vector<vector<int>> adjList(n);

  // Reading the graph from input
  // for (int i = 0; i < n; ++i) {
  for (int i = 0; i < m; ++i) {
    // int edge;
    // cin >> edge;
    int u, v;
    cin >> u >> v;
    // if (edge) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    // }
  }
  // }

  vector<int> eulerPath = findEulerPath(adjList);

  if (eulerPath.empty()) {
    cout << -1 << endl;
  } else {
    for (int vertex : eulerPath) {
      cout << vertex << " ";
    }
    cout << endl;
  }

  return 0;
}
