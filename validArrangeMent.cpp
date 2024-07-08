#include <algorithm>
#include <climits>
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

  for (int i = 0; i < n; ++i) {
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

  vector<int> res;

  if (v1 != -1) {
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
  }

  // cout << "v1 v2 first" << endl;
  // cout << v1 << " " << v2 << " " << first << endl;
  stack<int> st;
  st.push(first);

  while (!st.empty()) {
    int v = st.top();
    int i;
    for (i = 0; i < graph[v].size(); ++i) {
      if (graph[v][i] != -1) {
        break;
      }
    }

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

  // reordering
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

vector<vector<int>> validArrangement(vector<vector<int>> &pairs) {
  int maxValue = INT_MIN;
  for (const vector<int> &pair : pairs) {
    maxValue = max(maxValue, max(pair[0], pair[1]));
  }

  vector<vector<int>> graph(maxValue + 1);

  for (const vector<int> &pair : pairs) {
    int start = pair[0];
    int end = pair[1];
    graph[start].push_back(end);
    graph[end].push_back(start);
  }

  vector<int> eulerPath = findEulerianPath(graph);

  // Convert the Eulerian path to a sequence of pairs.
  vector<vector<int>> result;
  bool swapped = false;
  int i = 0;
  while (i < eulerPath.size()) {
    int start = eulerPath[i];
    int end = eulerPath[i + 1];
    if (swapped && graph[end].size() == 1) {
      swap(start, end);
    }
    if (graph[start].size() == 1) {
      swapped = true;
    } else {
      swapped = false;
    }
    result.push_back({start, end});
    i += 2;
  }

  // Reverse the result if necessary.
  if (result[0][0] != pairs[0][0]) {
    reverse(result.begin(), result.end());
  }

  // Correct the first and last pairs.
  if (result[0][1] != result[result.size() - 1][0]) {
    swap(result[0][1], result[result.size() - 1][0]);
  }

  return result;
}

int main() {
  // cout<<"Hello world !";
  int n;
  cin >> n;
  vector<vector<int>> pairs;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    pairs.push_back({u, v});
  }

  vector<vector<int>> validPairs = validArrangement(pairs);

  for (vector<int> &pairs : validPairs) {
    for (int values : pairs) {
      cout << values << " ";
    }
    cout << " ";
  }
  cout << endl;
}