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

int merge(vector<int> &inputArray, int left, int mid, int right) {
	vector<int> leftSubArray(inputArray.begin() + left,
							 inputArray.begin() + mid + 1);
	vector<int> rightSubArray(inputArray.begin() + mid + 1,
							  inputArray.begin() + right + 1);

	int i = 0, j = 0, k = left;
	int count = 0;

	while (i < leftSubArray.size() && j < rightSubArray.size()) {
		if (leftSubArray[i] <= rightSubArray[j]) {
			inputArray[k++] = leftSubArray[i++];
		} else {
			inputArray[k++] = rightSubArray[j++];
			count += (mid - i + 1);
		}
	}

	while (i < leftSubArray.size()) {
		inputArray[k++] = leftSubArray[i++];
	}

	while (j < rightSubArray.size()) {
		inputArray[k++] = rightSubArray[j++];
	}
	return count;
}

int mergeSort(vector<int> &inputArray, int left, int right) {
	if (left >= right) {
		return 0;
	}
	int mid = left + (right - left) / 2;
	return mergeSort(inputArray, left, mid) +
		   mergeSort(inputArray, mid + 1, right) +
		   merge(inputArray, left, mid, right);
}

int yodaness(string yodaInput, string correctInput) {
	vector<int> inputArray;
	vector<string> words; // Store words in the correct order

	stringstream ss(correctInput);
	string word;
	while (ss >> word) {
		words.push_back(word);
	}

	stringstream ss2(yodaInput);
	while (ss2 >> word) {
		auto it = find(words.begin(), words.end(), word);
		inputArray.push_back(
			distance(words.begin(),
					 it)); // Store the index of the word in the correct order
	}

	return mergeSort(inputArray, 0, inputArray.size() - 1);
}

// int yodaness(string yodaInput, string correctInput) {
// 	vector<int> inputArray;
// 	unordered_map<string, int> mapp;
// 	int index = 0;
// 	stringstream ss1(yodaInput);
// 	stringstream ss2(correctInput);

// 	string word;
// 	while (ss1 >> word) {
// 		if (mapp.find(word) == mapp.end()) {
// 			mapp.insert({word, index});
// 		}
// 		++index;
// 	}

// 	while (ss2 >> word) {
// 		inputArray.push_back(mapp[word]);
// 	}

// 	// cout << endl << "inputArray : " << endl;
// 	// for (int i = 0; i < inputArray.size(); i++)
// 	// 	cout << inputArray[i] << " ";
// 	// cout << endl;

// 	return mergeSort(inputArray, 0, inputArray.size() - 1);
// }

int main() {
	// Hello World
	// cout << "Hello world !" << endl;

	int t;
	cin >> t;
	cin.ignore();

	while (t--) {
		int n;
		cin >> n;
		cin.ignore();

		string yodaInput;
		string correctInput;

		getline(cin, yodaInput);
		getline(cin, correctInput);

		cout << yodaness(yodaInput, correctInput) << endl;
	}
}