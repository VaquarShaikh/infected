#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
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

int largestRectangleArea(vector<int> &heights) {
    heights.push_back(0);
    int n = heights.size(), ans = 0;
    stack<int> stack;
    for (int i = 0; i < n; i++) {
        while (!stack.empty() && heights[i] <= heights[stack.top()]) {
            int height = heights[stack.top()];
            stack.pop();
            // do some work
            int left = stack.size() ? stack.top() : -1;
            ans = max(ans, (i - left - 1) * height);
        }
        stack.push(i);
    }
    return ans;
}

int main() {
    // Hello World
    // cout << "Hello world !" << endl;

    int n;
    cin >> n;

    vector<int> heights;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        heights.push_back(temp);
    }
    cout << largestRectangleArea(heights) << endl;
}