#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define ln "\n"
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 2e18
#define INFF 1000000009
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    int index = 0;
    for (int i = 0; i < intervals.size(); i++) {
        // overlapping interval
        if (intervals[i][1] >= newInterval[0]) {
            // overlapping condition 2
            if (intervals[i][1] >= ans[index][0]) {
                ans[index][1] = max(ans[index][1], intervals[i][1]);
            }
            ans.push_back({intervals[i][0], max(intervals[i][1], newInterval[1])});
        }
        ans.push_back(intervals[i]);
    }
    return ans;
}

int main() {
    fast_cin();
    // Hello World
    cout << "Hello world !" << endl;
}