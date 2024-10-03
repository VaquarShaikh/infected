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

int partition(vector<int> &inputArray, int l, int r, int pivotIndex) {
	swap(inputArray[pivotIndex], inputArray[r]);
	for (int i = l; i < r; i++) {
		if (inputArray[i] < inputArray[r]) swap(inputArray[i], inputArray[l++]);
	}
	swap(inputArray[l], inputArray[r]);
	return l;
}

void quickSort(vector<int> &inputArray, int l, int r) {
	if (l >= r) return;
	int m = partition(inputArray, l, r, l + rand() % (r - l + 1));
	quickSort(inputArray, l, m - 1);
	quickSort(inputArray, m + 1, r);
}

void quickSort(vector<int> &inputArray) {
	quickSort(inputArray, 0, inputArray.size() - 1);
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	int n;
	cin >> n;

	vector<int> inputArray;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		inputArray.push_back(temp);
	}

	quickSort(inputArray);

	for (int i = 0; i < inputArray.size(); i++) cout << inputArray[i] << " ";
	cout << endl;
}