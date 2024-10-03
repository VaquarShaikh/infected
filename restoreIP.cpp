#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <algorithm>
#include <climits>
#include <cmath>
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

vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    string current;

    function<void(int, int)> dfs = [&](int index, int segment) {
        if (segment == 4 && index == s.size()) {
            ans.push_back(current.substr(0, current.size() - 1));
            return;
        }
        if (segment == 4 || index == s.size()) {
            return;
        }

        for (char c : s.substr(index)) {
            int len = current.size() - current.rfind('.') - 1;
            if (len == 0 && c == '0' && index + 1 < s.size()) break;
            if (len == 3 || (len > 0 && stoi(current.substr(current.rfind('.') + 1)) > 255))
                break;

            current += c;
            if (len == 2 || index == s.size() - 1 || segment == 3) {
                current += '.';
                dfs(index + 1, segment + 1);
                current.pop_back();  // Remove the dot
            } else {
                dfs(index + 1, segment);
            }
            current.pop_back();  // Backtrack
        }
    };

    dfs(0, 0);
    return ans;
}

int main() {
    fast_cin();
    // Hello World
    // cout << "Hello world !" << endl;
}