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

int partition(vector<int> &A, int l, int r) {
	int pivotIndex = l + rand() % (r - l + 1);
	int pivot = A[pivotIndex];
	swap(A[pivotIndex], A[r]);
	int i = l, j = r;  // the initial range covers the pivot A[R]
	while (i < j) {
		while (i < j && A[i] < A[r])
			++i;  // we must start from the other side of the pivot. Since we
				  // use A[R] as pivot, we need to start from the left side.
		while (i < j && A[j] >= A[r]) --j;
		swap(A[i], A[j]);
	}
	swap(A[i], A[r]);
	return i;
}

// int partition(vector<int> &nums, int l, int r) {
// 	int i = l, pivotIndex = l + rand() % (r - l + 1);
// 	int pivot = nums[pivotIndex];
// 	swap(nums[pivotIndex], nums[r]);
// 	for (int j = l; j < r; j++) {
// 		if (nums[j] > pivot) swap(nums[i++], nums[j]);
// 	}
// 	swap(nums[i], nums[r]);
// 	return i;
// }

int findKthLargest(vector<int> &nums, int k) {
	int l = 0, r = nums.size() - 1;
	while (true) {
		int m = partition(nums, l, r);
		if (m + 1 == k) return nums[m];
		if (m + 1 > k)
			r = m - 1;
		else
			l = m + 1;
	}
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;

	int n, k;
	cin >> n;
	vector<int> nums;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	cin >> k;
	cout << findKthLargest(nums, k) << endl;
}