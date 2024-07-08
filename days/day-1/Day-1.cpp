#include <algorithm>
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

vector<int> inputArray;

void bubbleSort() {
	int n = inputArray.size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (inputArray[j] > inputArray[j + 1])
				swap(inputArray[j], inputArray[j + 1]);
}

void merge(int left, int mid, int right) {
	vector<int> leftSubArray(inputArray.begin() + left,
							 inputArray.begin() + mid + 1);
	vector<int> rightSubArray(inputArray.begin() + mid + 1,
							  inputArray.begin() + right + 1);

	int i = 0, j = 0, k = left;
	while (i < leftSubArray.size() && j < rightSubArray.size()) {
		if (leftSubArray[i] <= rightSubArray[j]) {
			inputArray[k++] = leftSubArray[i++];
		} else {
			inputArray[k++] = rightSubArray[j++];
		}
	}
	while (i < leftSubArray.size()) {
		inputArray[k++] = leftSubArray[i++];
	}

	while (j < rightSubArray.size()) {
		inputArray[k++] = rightSubArray[j++];
	}
}

void mergeSort(int left = 0, int right = inputArray.size() - 1) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		inputArray.push_back(temp);
	}

	// bubbleSort();
	mergeSort();

	for (int i = 0; i < inputArray.size(); i++) {
		cout << inputArray[i] << " ";
	}
	cout << endl;
}