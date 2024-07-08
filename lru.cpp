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

class LRUCache {
  private:
	list<int> items;
	unordered_map<int, pair<int, list<int>::iterator>> keyValuesMap;
	int csize;

  public:
	LRUCache(int size) : csize(size) {
		if (csize < 1) {
			csize = 10;
		}
	}

	void set(int key, int val) {
		auto pos = keyValuesMap.find(key);
		// cache miss
		if (pos == keyValuesMap.end()) {
			items.push_front(key);
			keyValuesMap[key] = {val, items.begin()};
			if (keyValuesMap.size() > csize) {
				keyValuesMap.erase(items.back());
				items.pop_back();
			}
		}
		// cache hit
		else {
			items.erase(pos->second.second);
			items.push_front(key);
			keyValuesMap[key] = {val, items.begin()};
		}
	}

	int get(int key) {
		auto pos = keyValuesMap.find(key);
		// cache miss
		if (pos == keyValuesMap.end()) {
			throw out_of_range("Element does not exist");
		}
		// cache hit
		items.erase(pos->second.second);
		items.push_front(key);
		keyValuesMap[key] = {pos->second.first, items.begin()};
		return pos->second.first;
	}
};

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	LRUCache cache(2);

	cache.set(1, 1);
	cache.set(2, 2);

	cout << cache.get(1) << endl;

	cache.set(3, 3);

	try {
		cout << cache.get(2) << endl;
	} catch (const out_of_range &e) {
		cout << e.what() << endl;
	}
}