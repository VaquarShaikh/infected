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

void dfs(vector<vector<int>> &isConnected, vector<bool> &visited,
		 int startNode) {
	visited[startNode] = true;
	for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
		if (isConnected[startNode][neighbor] == 1 && !visited[neighbor]) {
			dfs(isConnected, visited, neighbor);
		}
	}
}

int findCircleNum(vector<vector<int>> &isConnected) {
	int n = isConnected.size();
	int count = 0;
	vector<bool> visited(n, false);

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(isConnected, visited, i);
			count++;
		}
	}
	return count;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	int n;
	cin >> n;
	vector<vector<int>> isConnected(n, vector<int>(n, 0));
}