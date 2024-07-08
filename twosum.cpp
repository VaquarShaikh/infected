#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
#define ln "\n"
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 2e18

vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> mapp;
  vector<int> res;
  for (int i = 0; i < nums.size(); i++) {
    int diff = target - nums[i];
    auto found = mapp.find(diff);
    if (found != mapp.end()) {
      res.push_back(found->second);
      res.push_back(i);
      return res;
    }
    mapp[nums[i]] = i;
  }
  return res;
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
  int target;
  cin >> target;
  vector<int> output = twoSum(nums, target);
  for (int i = 0; i < output.size(); i++) {
    cout << output[i] << " ";
  }
  cout << endl;
}