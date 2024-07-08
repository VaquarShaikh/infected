#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int trap(vector<int> &height) {
	int water = 0;
	stack<int> stack;

	for (int i = 0; i < height.size(); ++i) {
		while (!stack.empty() && height[i] > height[stack.top()]) {
			int top = stack.top();
			stack.pop();
			if (stack.empty()) break;
			int distance = i - stack.top() - 1;
			int bounded_height =
				min(height[i], height[stack.top()]) - height[top];
			water += distance * bounded_height;
		}
		stack.push(i);
	}
	return water;
}

int main() {
	vector<int> height;
	int n;
	cout << "Enter the number of bars: ";
	cin >> n;
	cout << "Enter the heights of the bars: ";
	for (int i = 0; i < n; ++i) {
		int h;
		cin >> h;
		height.push_back(h);
	}

	int result = trap(height);
	cout << "Amount of trapped water: " << result << endl;

	return 0;
}

// 4 2 0 3 2 5