#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define ln "\n"
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 2e18
#define INFF 1000000009

int coinChange(vector<int> &coins, int amount) {
	sort(coins.begin(), coins.end());
	int n = coins.size();
	int sum[n];
	sum[0] = coins[0];
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + coins[i];
	}

	for (int i = n - 1; i >= 0; i--) {
	}
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}