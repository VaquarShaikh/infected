#include <iostream>
#include <vector>

using namespace std;

void printSubsets(const vector<int> &set, int mask) {
	vector<int> subset;
	for (int i = 0; i < set.size(); ++i) {
		if (mask & (1 << i)) {
			subset.push_back(set[i]);
		}
	}
	// Print the subset
	cout << "{";
	for (size_t i = 0; i < subset.size(); ++i) {
		cout << subset[i];
		if (i < subset.size() - 1) {
			cout << ", ";
		}
	}
	cout << "}";
}

int main() {
	vector<int> set = {1, 2, 3};
	int N = set.size();

	// Loop over all possible subsets
	for (int mask = 0; mask < (1 << N); ++mask) {
		// Print the current subset (mask)
		cout << "Subset: ";
		printSubsets(set, mask);
		cout << endl;

		// Loop over all non-empty subsets of the current subset (mask)
		for (int sub = mask; sub; sub = (sub - 1) & mask) {
			cout << "  Non-empty subset: ";
			printSubsets(set, sub);
			cout << endl;
		}
	}

	return 0;
}