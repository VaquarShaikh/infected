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

int lengthOfLIS(vector<int> &nums) {
  vector<int> res(nums.begin(), nums.end());
  res.assign(nums.size(), 1);
  for (int i = 1; i < nums.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (nums[j] < nums[i]) {
        res[i] = max(res[j] + 1, res[i]);
      }
    }
  }
  return *max_element(res.begin(), res.end());
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
  cout << lengthOfLIS(nums) << endl;
}
