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
      swap(inputArray[++i], inputArray[j]);
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

void merge(vector<int> &inputArray, int left, int mid, int right) {
  vector<int> leftSubArray(inputArray.begin() + left,
                           inputArray.begin() + mid + 1);
  vector<int> rightSubArray(inputArray.begin() + mid + 1,
                            inputArray.begin() + right + 1);

  int i = 0, j = 0, k = left;
  while (i < leftSubArray.size() && j < rightSubArray.size()) {
    if (leftSubArray[i] < rightSubArray[j]) {
      inputArray[k++] = leftSubArray[i++];
    } else {
      inputArray[k++] = rightSubArray[j++];
    }
  }

  while (j < rightSubArray.size()) {
    inputArray[k++] = rightSubArray[j++];
  }
  while (i < leftSubArray.size()) {
    inputArray[k++] = leftSubArray[i++];
  }
}

void mergeSort(vector<int> &inputArray, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(inputArray, left, mid);
    mergeSort(inputArray, mid + 1, right);
    merge(inputArray, left, mid, right);
  }
}

void mergeSort(vector<int> &inputArray) {
  mergeSort(inputArray, 0, inputArray.size() - 1);
}

void insertionSort(vector<int> &inputArray) {
  for (int i = 1; i < inputArray.size(); i++) {
    int key = inputArray[i];
    int j = i - 1;
    while (j >= 0 && inputArray[j] > key) {
      inputArray[j + 1] = inputArray[j];
      j--;
    }
    inputArray[j + 1] = key;
  }
}

void selectionSort(vector<int> &inputArray) {
  for (int i = 0; i < inputArray.size() - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < inputArray.size(); j++) {
      if (inputArray[j] < inputArray[min_idx]) {
        min_idx = j;
      }
      swap(inputArray[min_idx], inputArray[i]);
    }
  }
}

void bubbleSort(vector<int> &inputArray) {
  for (int i = 0; i < inputArray.size() - 1; i++) {
    for (int j = 0; j < inputArray.size() - i - 1; j++) {
      if (inputArray[j] > inputArray[j + 1]) {
        swap(inputArray[j], inputArray[j + 1]);
      }
    }
  }
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
  // quickSort(inputArray);
  // mergeSort(inputArray);
  // bubbleSort(inputArray);
  // selectionSort(inputArray);
  insertionSort(inputArray);
  for (int i = 0; i < inputArray.size(); i++) {
    cout << inputArray[i] << " ";
  }
  cout << endl;
}