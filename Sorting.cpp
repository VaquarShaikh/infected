#include <algorithm>
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

vector<int> inputArray;

void bubbleSort() {
	int n = inputArray.size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (inputArray[j] > inputArray[j + 1])
				swap(inputArray[j], inputArray[j + 1]);
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		inputArray.push_back(temp);
	}

	bubbleSort();

	for (int i = 0; i < n; i++)
		cout << inputArray[i] << " ";
	cout << endl;
}