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
#define MAX 5000000

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
#define MAX 5000000

vector<string> inputArray;

vector<string> fizzBuzz(int n) {
	for (int i = 0; i <= MAX; i++)
		inputArray.push_back(to_string(i));
	for (int i = 3; i * i <= MAX; i += 3)
		inputArray[i] = "Fizz";
	for (int i = 5; i * i <= MAX; i += 5) {
		if (inputArray[i] == "Fizz")
			inputArray[i] = "FizzBuzz";
		else {
			inputArray[i] = "Buzz";
		}
	}

	vector<string> outputArray;

	for (int i = 1; i <= n; i++) {
		outputArray.push_back(inputArray[i]);
	}

	for (int i = 0; i < n; i++)
		cout << outputArray[i] << endl;

	return outputArray;
}

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	int n;
	cin >> n;

	vector<string> outputArray = fizzBuzz(n);

	for (int i = 0; i < outputArray.size(); i++)
		cout << outputArray[i] << endl;

	// for (int i = 0; i < 101; i++)
	// 	cout << inputArray[i] << endl;
}