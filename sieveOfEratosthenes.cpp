#include <algorithm>
#include <climits>
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
#define MAX 5000000

int main() {
  // cout<<"Hello world !";
  //   precomputation
  vector<bool> myPrimes(MAX + 1, true);
  for (int i = 2; i * i <= MAX; i++) {
    if (myPrimes[i]) {
      for (int j = i * i; j <= MAX; j += i) {
        myPrimes[j] = false;
      }
    }
  }
  for (int i = 2; i < 100; i++) {
    if (myPrimes[i]) {
      cout << i << " ";
    }
  }
  cout << endl;
}