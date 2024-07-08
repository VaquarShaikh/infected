#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
#define ln "\n"
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 2e18

int binarySearch(vector<int> &inputArray, int left, int right, int element) {
  if (right >= left) {
    int mid = left + (right - left) / 2;
    if (inputArray[mid] == element) {
      return mid;
    }
    if (inputArray[mid] > element) {
      return binarySearch(inputArray, left, mid - 1, element);
    }
    return binarySearch(inputArray, mid + 1, right, element);
  }
  return -1;
}

int binarySearch(vector<int> &inputArray, int element) {
  return binarySearch(inputArray, 0, inputArray.size() - 1, element);
}

int main() {
  // cout<<"Hello world !";
  int n;
  cin >> n;
  vector<int> inputArray;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    inputArray.push_back(temp);
  }
  int element;
  cin >> element;
  cout << "Element is at index : " << binarySearch(inputArray, element) << endl;
}