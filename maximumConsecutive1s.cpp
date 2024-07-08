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

int findMaxConsecutiveOnes(vector<int> &nums) {
	int max_len = 0, current_len = 0;
	for (int num : nums) {
		if (num == 1) {
			current_len++;
			max_len = max(max_len, current_len);
		} else {
			current_len = 0;
		}
	}
	return max_len;
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

	cout << findMaxConsecutiveOnes(nums) << endl;
}