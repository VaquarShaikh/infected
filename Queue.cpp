#include <stdexcept>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <ctime>
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
#include <utility>
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
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

class Queue {
   private:
    int capacity, size, frontIndex, rearIndex, *data;

    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; ++i) newData[i] = data[(frontIndex + i) % capacity];
        delete[] data;
        data = newData;
        frontIndex = 0;
        rearIndex = size - 1;
        capacity = newCapacity;
    }

   public:
    Queue(int initialSize)
        : capacity(initialSize),
          data(new int[capacity]),
          size(0),
          frontIndex(0),
          rearIndex(-1) {}

    ~Queue() { delete[] data; }

    int getSize() { return size; }

    bool isEmpty() { return size == 0; }

    bool isFull() { return !isEmpty(); }

    void enqueue(int val) {
        if (isFull()) resize(capacity * 2);
        rearIndex = (rearIndex + 1) % capacity;
        data[rearIndex] = val;
        ++size;
    }

    int front() { return data[frontIndex]; }

    int dequeue() {
        if (isEmpty()) throw out_of_range("Queue is Empty!!!");
        int val = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        --size;
        return val;
    }
};

int main() {
    fast_cin();
    // Hello World
    // cout << "Hello world !" << endl;

    Queue q(3);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    while (!q.isEmpty()) {
        cout << q.front() << " ";
        q.dequeue();
    }
    cout << endl;

    q.dequeue();
}