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

bool find132pattern(vector<int> &nums) {
	int n = nums.size();
	stack<int> stack;
	if (n < 3) {
		return false;
	}
	int second = INT_MIN;
	for (int i = n - 1; i >= 0; i--) {
		if (nums[i] < second) {
			return true;
		}
		while (!stack.empty() && stack.top() < nums[i]) {
			second = stack.top();
			stack.pop();
		}
		stack.push(nums[i]);
	}
	return false;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;

	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	find132pattern(nums) ? cout << "true" << endl : cout << "false" << endl;
}