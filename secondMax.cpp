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

int findSecondLargest(int n, vector<int> &arr) {
	// Write your code here.
	int Max = INT_MIN, sMax = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (arr[i] > Max) {
			sMax = Max;
			Max = arr[i];
		} else if (arr[i] < Max && arr[i] > sMax) {
			sMax = arr[i];
		}
	}
	return sMax == INT_MIN ? -1 : sMax;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	int n;
	cin >> n;

	vector<int> arr;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	cout << findSecondLargest(n, arr) << endl;
}