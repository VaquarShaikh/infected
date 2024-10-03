#include <iterator>
#include <unordered_set>
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
#include <stdexcept>
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

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> A(begin(nums1), end(nums1)), B(begin(nums2), end(nums2));
    vector<int> ans;
    for (const int& num : A)
        if (B.find(num) != B.end()) ans.push_back(num);
    return ans;
}

int main() {
    fast_cin();
    // Hello World
    cout << "Hello world !" << endl;
}