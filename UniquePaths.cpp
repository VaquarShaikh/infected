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

int uniquePaths(int m, int n) {
  //   main code
  vector<vector<int>> inputArray(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      inputArray[i][j] = 0;
    }
  }
  // making last row with 1
  for (int i = m - 2; i >= 0; i--) {
    inputArray[i][n - 1] = 1;
  }

  for (int i = n - 2; i >= 0; i--) {
    inputArray[m - 1][i] = 1;
  }
  //   calculate the rest

  for (int i = m - 2; i >= 0; i--) {
    for (int j = n - 2; j >= 0; j--) {
      inputArray[i][j] = inputArray[i + 1][j] + inputArray[i][j + 1];
    }
  }

  return inputArray[0][0];
}

int main() {
  // cout<<"Hello world !";
  int n, m;
  cin >> m >> n;
  cout << uniquePaths(m, n) << endl;
}