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

int reverse(int x) {
	int reverseNumber = 0;
	while (x != 0) {
		int lastDigit = x % 10;
		if (reverseNumber > (numeric_limits<int>::max() / 10) ||
			reverseNumber < (numeric_limits<int>::min() / 10))
			return 0;
		reverseNumber = reverseNumber * 10 + lastDigit;
		x /= 10;
	}
	return reverseNumber;
}

int main() {
	// Hello World
	cout << "Hello world !" << endl;
}