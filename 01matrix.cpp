#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>
#include <cmath>
#include <complex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
  int m = mat.size();
  int n = mat[0].size();
  vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

  queue<pair<int, int>> q;

  // count 0s and push the coordinates in the queue.

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] == 0) {
        ans[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  // plain bfs .
  while (!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    for (pair<int, int> &dir : directions) {
      int x = curr.first + dir.first;
      int y = curr.second + dir.second;
      if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == INT_MAX) {
        ans[x][y] = ans[curr.first][curr.second] + 1;
        q.push({x, y});
      }
    }
  }
  return ans;
}

int main() {
  fast_cin();
  int m, n;
  cin >> m >> n;
  vector<vector<int>> mat(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }

  vector<vector<int>> ans = updateMatrix(mat);

  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}