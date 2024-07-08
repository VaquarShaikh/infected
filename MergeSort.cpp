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

void merge(vector<int> &inputArray, int left, int mid, int right) {
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

void mergeSort(vector<int> &inputArray, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(inputArray, left, mid);
		mergeSort(inputArray, mid + 1, right);
		merge(inputArray, left, mid, right);
	}
}

void mergeSort(vector<int> &inputArray) {
	mergeSort(inputArray, 0, inputArray.size() - 1);
}

int main() {
	// cout << "Hello world !";
	int n;
	cin >> n;
	vector<int> inputArray;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		inputArray.push_back(temp);
	}
	mergeSort(inputArray);

	for (int i = 0; i < inputArray.size(); i++) {
		cout << inputArray[i] << " ";
	}
	cout << endl;
}