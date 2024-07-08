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

class StockSpanner {
  private:
	stack<pair<int, int>> stack;

  public:
	StockSpanner() {}

	int next(int price) {
		int count = 1;

		while (!stack.empty() && stack.top().first <= price) {
			count += stack.top().second;
			stack.pop();
		}

		stack.push({price, count});
		return stack.top().second;
	}
};

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}