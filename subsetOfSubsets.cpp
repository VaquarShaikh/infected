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

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	vector<int> inputArray = {1, 2, 3};

	int n = inputArray.size();

	for (int mask = 0; mask < (1 << n); mask++) {
		cout << "Subset : ";
		for (int i = 0; i < n; i++) {
			if (mask >> i & 1)
				cout << inputArray[i] << " ";
		}
		cout << endl;
		for (int sub = mask; sub; sub = (sub - 1) & mask) {
			for (int i = 0; i < n; i++) {
				if (sub >> i & 1)
					cout << inputArray[i] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}