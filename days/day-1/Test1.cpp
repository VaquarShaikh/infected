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

vector<int> nums;

void merge(vector<int> &nums, int left, int mid, int right) {
	vector<int> leftSubArray(nums.begin() + left, nums.begin() + mid + 1);
	vector<int> rightSubArray(nums.begin() + mid + 1, nums.begin() + right + 1);

	int i = 0, j = 0, k = left;
	while (i < leftSubArray.size() && j < rightSubArray.size()) {
		if (leftSubArray[i] <= rightSubArray[j]) {
			nums[k++] = leftSubArray[i++];
		} else {
			nums[k++] = rightSubArray[j++];
		}
	}

	while (i < leftSubArray.size()) {
		nums[k++] = leftSubArray[i++];
	}

	while (j < rightSubArray.size()) {
		nums[k++] = rightSubArray[j++];
	}
}

void mergeSort(vector<int> &nums, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(nums, left, mid);
		mergeSort(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
}

vector<int> sortArray(vector<int> &nums) {
	mergeSort(nums, 0, nums.size() - 1);
	return nums;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	vector<int> outputArray = sortArray(nums);

	for (int i = 0; i < outputArray.size(); i++)
		cout << outputArray[i] << " ";
	cout << endl;
}