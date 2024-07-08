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

vector<vector<int>> subsets(vector<int> &nums, int index) {
  // base case (if it is an empty array)
  if (index == nums.size()) {
    return {{}};
  }
  // recursive call
  vector<vector<int>> smallAns = subsets(nums, index + 1);
  // sample calculation (merging smallAns with current element which is not in
  // the small answer)
  vector<vector<int>> subsetsWithCurrent = smallAns;
  for (vector<int> &subset : subsetsWithCurrent) {
    subset.push_back(nums[index]);
  }
  // merge smallAns and subsetsWithCurrent and return smallAns.
  smallAns.insert(smallAns.end(), subsetsWithCurrent.begin(),
                  subsetsWithCurrent.end());
  return smallAns;
}

vector<vector<int>> subsets(vector<int> &nums) {
  // Start the recursion with index 0.
  return subsets(nums, 0);
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
  vector<vector<int>> components = subsets(nums);
  for (vector<int> &component : components) {
    for (int temp : component) {
      cout << temp << " ";
    }
    cout << endl;
  }
  cout << endl;
}