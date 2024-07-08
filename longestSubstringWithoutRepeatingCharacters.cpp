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

int lengthOfLongestSubstring(string s) {
  int dp[s.length()]; // sdfsdfs
  for (int i = 0; i < s.length(); i++) {
    dp[i] = 1;
  }
  for (int i = s.size() - 1; i >= 1; i--) {
    int count = 0;
    for (int j = i - 1; j >= 1; j--) {
      if (s[j] != s[i]) {
        count++;
      } else {
        break;
      }
    }
    dp[i] += count;
  }
  int max = INT_MIN;
  for (int i = 0; i < s.length(); i++) {
    cout << dp[i] << " ";
    if (dp[i] > max) {
      max = dp[i];
    }
  }
  cout << endl;
  return max;
}

int main() {
  // cout<<"Hello world !";
  string s;
  cin >> s;
  cout << lengthOfLongestSubstring(s) << endl;
}