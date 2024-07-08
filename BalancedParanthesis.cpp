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
#define ln '\n'
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 2e18
#define INFF 1000000009

bool isValid(string s) {
	stack<char> stack;
	stringstream ss(s);
	char word;
	while (ss >> word) {
		if (word == '{' || word == '[' || word == '(') {
			stack.push(word);
		} else {
			if (stack.empty()) {
				return false;
			}
			char top = stack.top();
			stack.pop();
			if ((word == '}' && top != '{') || (word == ']' && top != '[') ||
				(word == ')' && top != '(')) {
				return false;
			}
		}
	}
	if (!stack.empty()) {
		return false;
	}
	return true;
}

int main() {
	// Hello World
	// cout << 'Hello world !' << endl;

	string s;
	cin >> s;

	isValid(s) ? cout << "Balanced" << endl : cout << "Not Balanced" << endl;
}