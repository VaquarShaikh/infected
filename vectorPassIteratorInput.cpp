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

void fun(vector<int> &inputArray, vector<int>::iterator it1,
         vector<int>::iterator it2) {
  //   for (int i = 0; i < inputArray.size(); i++) {
  //     cout << inputArray[i] << " ";
  //   }
  while (it1 != it2) {
    cout << *it1 << " ";
    it1++;
  }
  cout << endl;
  cout << inputArray.size() << endl;
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
  int k;
  cin >> k;
  fun(inputArray, inputArray.begin(), inputArray.begin() + k);
}