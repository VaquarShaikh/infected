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

bool isAnagram(string s, string t) {
	int n = s.size();
	int m = t.size();

	if (n != m) {
		return false;
	}

	vector<int> frequencyMap(256, 0);

	for (int i = 0; i < n; i++) {
		frequencyMap[s[i]]++;
	}

	for (int i = 0; i < n; i++) {
		frequencyMap[t[i]]--;
	}

	for (int i = 0; i < frequencyMap.size(); i++)
		if (frequencyMap[i] != 0)
			return false;
	return true;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	string s, t;
	cin >> s >> t;

	isAnagram(s, t) ? cout << "Anagram" << endl
					: cout << "Not an anagram" << endl;
}