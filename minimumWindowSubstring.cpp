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

string minWindow(string s, string t) {
	long i = 0, j = 0, n = s.size(), m = t.size(), ans = INT_MAX, cnt[128] = {},
		 left = 0, right = 0;
	for (; j < n; j++) {
		cnt[s[j]]++;
		// valid till all the elements are present in the window
		while (cnt[t[j]] >= 1) {
			if (ans > j - i + 1) {
				ans = j - i + 1;
				left = i;
				right = j;
			}
			cnt[s[i]]--;
			i++;
		}
	}
	string results = s.substr(left, right + 1);
	return results;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;

	string s, t;
	cin >> s >> t;

	cout << minWindow(s, t) << endl;
}