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

vector<int> A, temp;

void bubbleSort() {
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A.size() - i - 1; j++)
            if (A[j] > A[j + 1]) swap(A[j], A[j + 1]);
}

void mergeSort() {
    temp.assign(A.size(), 0);
    function<void(int, int)> mergeSort = [&](int start, int end) {
        if (start + 1 >= end) return;
        int mid = start + (end - start) / 2, i = start, j = mid, k = start;
        mergeSort(start, mid);
        mergeSort(mid, end);
        while (i < mid || j < end)
            if (j >= end || (i < mid && A[i] < A[j])) temp[k++] = A[i++];
            else temp[k++] = A[j++];
        for (int i = start; i < end; i++) A[i] = temp[i];
    };
    mergeSort(0, A.size());
}

void quickSort() {
    function<int(int, int, int)> partition = [&](int left, int right, int pivot) {
        swap(A[pivot], A[right]);
        for (int i = left; i < right; i++) {
            if (A[i] >= A[right]) continue;
            swap(A[i], A[left++]);
        }
        swap(A[left], A[right]);
        return left;
    };

    function<void(int, int)> quickSort = [&](int left, int right) {
        if (left >= right) return;
        int m = partition(left, right, rand() % (right - left + 1) + left);
        quickSort(left, m - 1);
        quickSort(m + 1, right);
    };

    srand(time(0));

    quickSort(0, A.size() - 1);
}

int main() {
    fast_cin();
    // Hello World
    // cout << "Hello world !" << endl;
    for (int i = 0; i < 5; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    // bubbleSort();
    // mergeSort();
    quickSort();

    for (int i = 0; i < A.size(); i++) cout << A[i] << " ";
    cout << endl;
}