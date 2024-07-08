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

string removeKdigits(string num, int k) {
	int n = num.size();
	stack<char> stack;
	string res;

	//  basic template
	for (int i = 0; i < n; i++) {
		while (!stack.empty() && stack.top() > num[i] && k > 0) {
			stack.pop();
			k--;
		}
		stack.push(num[i]);
	}
	// handle the corner case
	while (!stack.empty() && k > 0) {
		stack.pop();
		k--;
	}

	// copy the generated result
	while (!stack.empty()) {
		res.push_back(stack.top());
		stack.pop();
	}
	// result generated in reverse
	reverse(res.begin(), res.end());

	//  remove leading 0
	int start = 0;
	while (start < res.size() && res[start] == '0') {
		start++;
	}

	res = res.substr(start);

	return res.empty() ? "0" : res;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	string num;
	int k;
	cin >> num >> k;

	cout << removeKdigits(num, k) << endl;
}

// Corner cases for this problem are :
// 1) num = 9 , k = 1
// 2) num = 12345 , k = 2