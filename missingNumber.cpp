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

int missingNumber(vector<int> &nums) {
  int n = nums.size();
  int sum = n * (n + 1) / 2;
  int ssum = 0;
  for (int i = 0; i < nums.size(); i++) {
    ssum += nums[i];
  }
  return sum - ssum;
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
  cout << missingNumber(nums) << endl;
}