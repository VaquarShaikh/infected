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
#include <iterator>
#include <list>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
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

class UnionFind {
    vector<int> id, rank;
    int cnt;

   public:
    UnionFind(int n) : id(n), rank(n, 0), cnt(n) { iota(begin(id), end(id), 0); }

    int find(int a) { return id[a] == a ? a : id[a] = find(id[a]); }
    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        if (rank[p] > rank[q]) id[q] = p;
        else {
            id[p] = q;
            if (rank[p] == rank[q]) rank[q]++;
        }
        cnt--;
    }
    bool connected(int a, int b) { return find(a) == find(b); }
    int getCount() { return cnt; }
};

int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;
    UnionFind uf(n);
    for (auto& connection : connections) uf.connect(connection[0], connection[1]);
    return uf.getCount() - 1;
}

int main() {
    fast_cin();
    // Hello World
    cout << "Hello world !" << endl;
}