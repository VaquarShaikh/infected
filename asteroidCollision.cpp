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

vector<int> asteroidCollision(vector<int> &asteroids) {
	int n = asteroids.size();
	stack<int> stack;
	vector<int> results;

	for (int i = 0; i < n; i++) {
		if (asteroids[i] < 0) {
			while (!stack.empty() && stack.top() > 0 &&
				   stack.top() < abs(asteroids[i])) {
				stack.pop();
			}
			if (!stack.empty() && stack.top() > 0) {
				if (stack.top() == abs(asteroids[i])) {
					stack.pop();
				}
			} else {
				stack.push(asteroids[i]);
			}
		} else {
			stack.push(asteroids[i]);
		}
	}

	while (!stack.empty()) {
		results.push_back(stack.top());
		stack.pop();
	}

	reverse(results.begin(), results.end());

	return results;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	int n;
	cin >> n;
	vector<int> asteroids;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		asteroids.push_back(temp);
	}

	vector<int> res = asteroidCollision(asteroids);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}