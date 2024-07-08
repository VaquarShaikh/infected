#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> findEulerPath(vector<vector<int>> &graph) {
  int n = graph.size();
  vector<int> deg(n);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      deg[i] += graph[i][j];
    }
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
    ++graph[v1][v2];
    ++graph[v2][v1];
  }

  stack<int> st;
  vector<int> res;
  st.push(first);

  while (!st.empty()) {
    int v = st.top();
    int i;
    for (i = 0; i < n; ++i) {
      if (graph[v][i]) {
        break;
      }
    }

    if (i == n) {
      res.push_back(v);
      st.pop();
    } else {
      --graph[v][i];
      --graph[i][v];
      st.push(i);
    }
  }

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

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (graph[i][j]) {
        bad = true;
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
  int n;
  cin >> n;

  // Initialize a matrix to store the graph
  vector<vector<int>> graph(n, vector<int>(n, 0));

  // Reading the graph from input
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> graph[i][j];
    }
  }

  vector<int> eulerPath = findEulerPath(graph);

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