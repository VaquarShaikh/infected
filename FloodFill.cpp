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

void dfs(vector<vector<int>> &image, int sr, int sc, int color,
         vector<vector<bool>> &visited, int originalColour) {
  image[sr][sc] = color;
  visited[sr][sc] = true;
  vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  for (const pair<int, int> &dir : directions) {
    int x = sr + dir.first;
    int y = sc + dir.second;
    if (x >= 0 && x < image.size() && y >= 0 && y < image[0].size() &&
        visited[x][y] != true && image[x][y] == originalColour) {
      dfs(image, x, y, color, visited, originalColour);
    }
  }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                              int color) {
  int n = image.size();
  int m = image[0].size();
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  int originalColour = image[sr][sc];
  dfs(image, sr, sc, color, visited, originalColour);
  return image;
}

int main() {
  // cout<<"Hello world !";
  int n;
  cin >> n;
  vector<vector<int>> image(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> image[i][j];
    }
  }
  int sr, sc, color;
  cin >> sr >> sc >> color;
  vector<vector<int>> res = floodFill(image, sr, sc, color);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[0].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}