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

string s, t;

bool isIsomorphic(string s, string t) {
    int sfreq[256] = {}, tfreq[256] = {}, ssum = 0, tsum = 0;
    for (int i = 0; i < s.size(); i++) sfreq[i] += s[i];
    for (int i = 0; i < t.size(); i++) tfreq[i] += t[i];
    for (int i = 0; i < 256; i++) ssum += sfreq[i];
    for (int i = 0; i < 256; i++) tsum += tfreq[i];
    return ssum == tsum;
}

int main() {
    fast_cin();
    // Hello World
    cout << "Hello world !" << endl;
}