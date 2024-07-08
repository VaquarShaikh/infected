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

int print2largest(int arr[], int n) {
  // code here
  int maximum = max(arr[1], arr[0]);
  int second_max = min(arr[1], arr[0]);
  for (int i = 2; i < n; i++) {
    if (arr[i] > maximum) {
      second_max = maximum;
      maximum = arr[i];
    } else if (arr[i] < maximum && arr[i] > second_max) {
      second_max = arr[i];
    } else if (maximum == second_max && arr[i] < second_max) {
      second_max = arr[i];
    }
  }
  if (maximum != second_max) {
    return second_max;
  } else {
    return -1;
  }
}

int main() {
  // cout<<"Hello world !";
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  //   for (int i = 0; i < n; i++) {
  //     cout << arr[i] << " ";
  //   }
  //   cout << endl;
  cout << print2largest(arr, n) << endl;
}