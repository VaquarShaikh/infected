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

class Queue {
  private:
	int *data;
	int capacity;
	int size;
	int frontIndex;
	int rearIndex;

  public:
	Queue(int initialSize) {
		if (initialSize < 1) {
			cerr << "Size should be atleast 1" << endl;
		}
		capacity = initialSize;
		data = new int[capacity];
		frontIndex = rearIndex = -1;
		size = 0;
	}

	~Queue() { delete[] data; }

	int getSize() { return size; }

	bool isFull() { return size == capacity; }

	bool isEmpty() { return size == 0; }

	void enqueue(int val) {
		if (isFull()) {
			cout << "Queue is full resizing" << endl;
			resize(capacity * 2);
		}
		rearIndex = (rearIndex + 1) % capacity;
		data[rearIndex] = val;
		size++;
	}

	int dequeue() {
		if (isEmpty()) {
			cerr << "Queue is empty" << endl;
			return INT_MIN;
		}
		int frontElement = data[(frontIndex + 1) % capacity];
		frontIndex = (frontIndex + 1) % capacity;
		--size;
		if (size == 0) {
			frontIndex = rearIndex = -1;
		}
		return frontElement;
	}

	int top() {
		if (isEmpty()) {
			cerr << "Stack is empty" << endl;
			return INT_MIN;
		}
		return data[(frontIndex + 1) % capacity];
	}

  private:
	void resize(int newCapacity) {
		int *newData = new int[newCapacity];
		int currentIndex = (frontIndex + 1) % capacity;
		for (int i = 0; i < size; i++) {
			newData[i] = data[currentIndex];
			currentIndex = (currentIndex + 1) % capacity;
		}
		delete[] data;
		data = newData;
		capacity = newCapacity;
		frontIndex = capacity - 1;
		rearIndex = size - 1;
	}
};

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	Queue q(3);
	q.enqueue(101);
	q.enqueue(222);
	q.enqueue(390);

	while (!q.isEmpty()) {
		int top = q.top();
		cout << "Current element popped : " << q.dequeue() << endl;
	}
}