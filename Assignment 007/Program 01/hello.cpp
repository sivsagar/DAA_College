#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cout << "Enter number of items: ";
	cin >> n;

	vector<int> weight(n + 1), value(n + 1);

	cout << "Enter weight and value of each item:\n";
	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}

	int capacity;
	cout << "Enter knapsack capacity: ";
	cin >> capacity;

	// dp[i][w] = maximum value using first i items with capacity w.
	vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int w = 0; w <= capacity; w++) {
			dp[i][w] = dp[i - 1][w];
			if (weight[i] <= w) {
				dp[i][w] = max(dp[i][w], value[i] + dp[i - 1][w - weight[i]]);
			}
		}
	}

	cout << "Maximum value = " << dp[n][capacity] << "\n";

	vector<int> selectedItems;
	int w = capacity;
	for (int i = n; i >= 1; i--) {
		if (dp[i][w] != dp[i - 1][w]) {
			selectedItems.push_back(i);
			w -= weight[i];
		}
	}

	reverse(selectedItems.begin(), selectedItems.end());

	cout << "Selected item indices (1-based): ";
	if (selectedItems.empty()) {
		cout << "None";
	} else {
		for (int idx : selectedItems) {
			cout << idx << " ";
		}
	}
	cout << "\n";

	return 0;
}

/*
Sample Input:
4
1 1
3 4
4 5
5 7
7

Sample Output:
Enter number of items: Enter weight and value of each item:
Enter knapsack capacity: Maximum value = 9
Selected item indices (1-based): 2 3
*/
