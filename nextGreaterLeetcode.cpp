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

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
	// calculate nextGreater element first in unordered map .
	int n = nums2.size();
	unordered_map<int, int> mapp;
	stack<int> stack;
	vector<int> results;

	// Initialize mapp with -1 .

	for (int val : nums2) {
		if (mapp.find(val) == mapp.end()) {
			mapp.insert({val, -1});
		}
	}

	// Calculate next greater element with nums2 .

	for (int i = n - 1; i >= 0; i--) {
		while (!stack.empty() && nums2[i] >= stack.top()) {
			stack.pop();
		}

		if (!stack.empty()) {
			mapp[nums2[i]] = stack.top();
		}

		stack.push(nums2[i]);
	}

	for (int val : nums1) {
		results.push_back(mapp[val]);
	}

	return results;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	int n, m;
	cin >> n >> m;
	vector<int> nums1, nums2;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		nums1.push_back(temp);
	}

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		nums2.push_back(temp);
	}

	vector<int> res = nextGreaterElement(nums1, nums2);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}

// 3 4
// 4 1 2
// 1 3 4 2

// 2 4
// 2 4
// 1 2 3 4