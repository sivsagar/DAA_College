/*Selection sort and find time comeplexity using substituion and frequency method*/

#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
}

int main() {
	int n;
	cout << "Enter number of elements: ";
	if (!(cin >> n) || n < 0) {
		return 0;
	}

	int *arr = new int[n];
	cout << "Enter elements: ";
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	selectionSort(arr, n);

	cout << "Sorted array: ";
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << (i + 1 == n ? '\n' : ' ');
	}

	delete[] arr;
	return 0;
}

/*
Time Complexity using Substitution Method:
Let T(n) be the time for selection sort with input size n.
T(n) = T(n-1) + (n-1) + c
	 = T(n-2) + (n-2) + (n-1) + 2c
	 = ...
	 = T(1) + (2 + 3 + ... + (n-1)) + (n-1)c
	 = T(1) + (n-1)(n-2)/2 + (n-1)c
	 = O(n^2)

Time Complexity using Frequency Method:
Outer loop runs (n-1) times.
Inner loop comparisons count:
	(n-1) + (n-2) + ... + 1 = n(n-1)/2
Swaps: at most (n-1).
Total operations proportional to n(n-1)/2 + (n-1) = O(n^2).
Best, Average, Worst case: O(n^2).
*/
