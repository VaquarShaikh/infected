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

class MyStack {
  private:
	queue<int> q;

  public:
	MyStack() {}

	void push(int x) {
		int size = q.size();
		q.push(x);
		for (int i = 0; i < size; i++) {
			q.push(q.front());
			q.pop();
		}
	}

	int pop() {
		if (!q.empty()) {
			int front = q.front();
			q.pop();
			return front;
		} else {
			cerr << "Queue is empty" << endl;
			return INT_MIN;
		}
	}

	int top() {
		if (!q.empty()) {
			return q.front();
		} else {
			cerr << "Queue is empty" << endl;
			return INT_MIN;
		}
	}

	bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
}