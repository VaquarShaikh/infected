#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <stack>
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

bool compareInterval(pair<int, int> a, pair<int, int> b) {
  return a.first < b.first;
}

void mergeIntervals(vector<pair<int, int>> &intervals) {
  sort(intervals.begin(), intervals.end(), compareInterval);

  int index = 0;
  for (int i = 1; i < intervals.size(); i++) {
    // overlapping codition
    if (intervals[index].second >= intervals[i].first) {
      intervals[index].second =
          max(intervals[index].second, intervals[i].second);
    } else {
      index++;
      intervals[index].first = intervals[i].first;
      intervals[index].second = intervals[i].second;
    }
  }
  cout << "Merged Intervals :" << endl;
  for (int i = 0; i <= index; i++) {
    cout << intervals[i].first << " " << intervals[i].second << endl;
  }
}

int main() {
  // Hello World
  // cout << "Hello world !" << endl;

  int n;
  cin >> n;

  vector<pair<int, int>> intervals;
  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;
    intervals.push_back({start, end});
  }

  mergeIntervals(intervals);
}