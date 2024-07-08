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

int partition(vector<int> &inputArray, int left, int right) {
  int pivot = inputArray[right];
  int i = left - 1;
  for (int j = left; j <= right - 1; j++) {
    if (inputArray[j] < pivot) {
      i++;
      swap(inputArray[i], inputArray[j]);
    }
  }
  swap(inputArray[i + 1], inputArray[right]);
  return (i + 1);
}

void quickSort(vector<int> &inputArray, int left, int right) {
  if (left < right) {
    int pivot = partition(inputArray, left, right);
    quickSort(inputArray, left, pivot - 1);
    quickSort(inputArray, pivot + 1, right);
  }
}

void quickSort(vector<int> &inputArray) {
  quickSort(inputArray, 0, inputArray.size() - 1);
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
  quickSort(inputArray);
  for (int i = 0; i < inputArray.size(); i++) {
    cout << inputArray[i] << " ";
  }
  cout << endl;
}