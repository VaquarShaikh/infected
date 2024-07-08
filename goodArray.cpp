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

bool isGoodArray(vector<int> &nums) {
  int gcd = 0;
  for (int i = 1; i < nums.size(); i++) {
    gcd = __gcd(gcd, nums[i]);
    if (gcd == 1) {
      return true;
    }
  }
  return false;
}

int main() {
  // cout<<"Hello world !";
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    nums.push_back(temp);
  }
  isGoodArray(nums) ? cout << "true" << endl : cout << "false" << endl;
}