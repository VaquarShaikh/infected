// Correct recursive code , Interview 1 codeguru aws persistent systems
// The interviewer Anushi gupta wanted the print statement before recursive call

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

void fun(int n) {
	if (n == 0) {
		return;
	}

	fun(n - 1);
	cout << "Vaq" << endl;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	fun(3);
}