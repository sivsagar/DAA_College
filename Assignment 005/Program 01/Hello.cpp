/*Selection sort and find time comeplexity using substituion and frequency method*/

#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {                   // O(1)
	for (int i = 0; i < n - 1; ++i) {                    // O(n) - runs n-1 times
		int minIndex = i;                                // O(1) per iteration
		for (int j = i + 1; j < n; ++j) {                // O(n-i) - runs n-i-1 times for each i
			if (arr[j] < arr[minIndex]) {                // O(1) per inner iteration
				minIndex = j;                            // O(1) per inner iteration
			}
		}
		if (minIndex != i) {                             // O(1) per iteration
			int temp = arr[i];                           // O(1) per iteration
			arr[i] = arr[minIndex];                      // O(1) per iteration
			arr[minIndex] = temp;                        // O(1) per iteration
		}
	}
}                                                        // Total: O(n^2)

int main() {
	int n;                                               // O(1)
	cout << "Enter number of elements: ";               // O(1)
	if (!(cin >> n) || n < 0) {                         // O(1)
		return 0;                                        // O(1)
	}

	int *arr = new int[n];                               // O(n) - memory allocation
	cout << "Enter elements: ";                          // O(1)
	for (int i = 0; i < n; ++i) {                        // O(n) - runs n times
		cin >> arr[i];                                   // O(1) per iteration
	}

	selectionSort(arr, n);                               // O(n^2)

	cout << "Sorted array: ";                            // O(1)
	for (int i = 0; i < n; ++i) {                        // O(n) - runs n times
		cout << arr[i] << (i + 1 == n ? '\n' : ' ');    // O(1) per iteration
	}

	delete[] arr;                                        // O(n) - memory deallocation
	return 0;                                            // O(1)
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
