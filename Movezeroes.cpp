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

void moveZeroes(vector<int> &nums) {
  int k = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != 0) {
      nums[k++] = nums[i];
    }
  }
  while (k < nums.size()) {
    nums[k++] = 0;
  }
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
}