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

vector<int> inputArray;
vector<int> results;

vector<int> nextGreaterElement() {
	int n = inputArray.size();
	results.resize(n, -1);

	stack<int> stack;

	for (int i = n - 1; i >= 0; i--) {
		while (!stack.empty() && inputArray[i] >= stack.top()) {
			stack.pop();
		}
		if (!stack.empty()) {
			results[i] = stack.top();
		}
		stack.push(inputArray[i]);
	}
	return results;
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
	vector<int> res = nextGreaterElement();

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}

// 5 2 1 2 4 3