#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
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

vector<int> plusOne(vector<int>& digits) {
	int n = digits.size();
	vector<int> ans;
	int carry = 1;	// Start with the carry of one, since we're adding one

	for (int i = n - 1; i >= 0; i--) {
		int sum = digits[i] + carry;
		ans.push_back(sum % 10);
		carry = sum / 10;
	}

	if (carry)
		ans.push_back(carry);  // If there's still a carry, add it to the result

	reverse(ans.begin(), ans.end());  // Reverse to get the correct order
	return ans;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}