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

class Stack {
  private:
	int *data;
	int capacity;
	int topIndex;

  public:
	Stack(int size) {
		capacity = size;
		data = new int[capacity];
		topIndex = -1;
	}

	~Stack() { delete[] data; }

	void push(int element) {
		if (topIndex == capacity - 1) {
			cout << "Stack Overflow" << endl;
		}
		data[++topIndex] = element;
	}

	bool isEmpty() { return topIndex == -1; }

	int pop(int element) {
		if (isEmpty()) {
			cerr << "Stack is empty !!!" << endl;
			return INT_MIN;
		}
		return data[--topIndex];
	}

	int top() {
		if (isEmpty()) {
			cerr << "Stack is empty" << endl;
			return INT_MIN;
		}
		return data[topIndex];
	}
};

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	Stack stack(3);
	stack.push(1);
	stack.push(2);
	stack.push(3);
	// stack.push(4);
	cout << stack.top() << endl;
}