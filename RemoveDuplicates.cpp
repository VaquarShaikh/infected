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

int removeDuplicates(vector<int> &nums) {
  if (nums.size() == 0) {
    return 0;
  }
  int i = 0, j = 1, count = 1;
  int len = nums.size();
  while (i < len && j < len) {
    if (nums[i] == nums[j]) {
      j++;
    } else {
      nums[i + 1] = nums[j];
      i++;
      j++;
      count++;
    }
  }
  cout << "Final Array : " << endl;
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
  return count;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    nums.push_back(temp);
  }
  cout << removeDuplicates(nums) << endl;
}