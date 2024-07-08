#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
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

bool areSimilar(vector<vector<int>> &mat, int k) {
	auto checkShift = [&](vector<int> &row, int n, int flag) -> bool {
		if (flag % 2 == 0) {
			for (int i = 0; i < n; i++) {
				if (row[i] != row[(i + n - k % n) % n]) {
					return false;
				}
			}
		} else {
			for (int i = 0; i < n; i++) {
				if (row[i] != row[(i + k) % n]) {
					return false;
				}
			}
		}
		return true;
	};

	for (int i = 0; i < mat.size(); i++) {
		if (!checkShift(mat[i], mat[i].size(), i))
			return false;
	}
	return true;
}

int main() {
	// Hello World
	cout << "Hello world !" << endl;
}