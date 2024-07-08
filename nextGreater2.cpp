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

vector<int> nextGreaterElements(vector<int> &nums) {
	int n = nums.size();
	vector<int> results(n, -1); // Initialize the results vector with -1
	stack<int> stack;

	// Traverse the array twice to simulate the circular behavior
	for (int i = 2 * n - 1; i >= 0; --i) {
		int num = nums[i % n];
		while (!stack.empty() && stack.top() <= num) {
			stack.pop();
		}
		// Update results only for the first pass
		if (i < n) {
			if (!stack.empty()) {
				results[i] = stack.top();
			}
		}
		stack.push(num);
	}

	return results;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	int n, m;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	vector<int> res = nextGreaterElements(nums);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}
