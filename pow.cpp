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

double myPow(double x, int n) {
  if (n == 0) {
    return 1.0;
  }

  // Handle negative exponent
  long long exponent = n; // Use long long to handle INT_MIN
  if (exponent < 0) {
    x = 1.0 / x;
    exponent = -exponent;
  }

  // Recursive case: split the exponent in half
  double halfPower = myPow(x, exponent / 2);

  // Multiply the result with itself for even exponent
  // Multiply the result with itself and x for odd exponent
  return (exponent % 2 == 0) ? (halfPower * halfPower)
                             : (halfPower * halfPower * x);
}

int main() {
  // cout<<"Hello world !";
  double x;
  int n;
  cin >> x >> n;
  cout << myPow(x, n) << endl;
}