/*Insertion sort and find time comeplexity using substituion and frequency method*/

#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {                   // O(1)
	for (int i = 1; i < n; ++i) {                        // O(n) - runs n-1 times
		int key = arr[i];                                // O(1) per iteration
		int j = i - 1;                                   // O(1) per iteration
		while (j >= 0 && arr[j] > key) {                 // O(i) worst case - runs up to i times
			arr[j + 1] = arr[j];                         // O(1) per inner iteration
			--j;                                         // O(1) per inner iteration
		}
		arr[j + 1] = key;                                // O(1) per iteration
	}
}                                                        // Total: O(n^2) worst case, O(n) best case

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

	insertionSort(arr, n);                               // O(n^2) worst case

	cout << "Sorted array: ";                            // O(1)
	for (int i = 0; i < n; ++i) {                        // O(n) - runs n times
		cout << arr[i] << (i + 1 == n ? '\n' : ' ');    // O(1) per iteration
	}

	delete[] arr;                                        // O(n) - memory deallocation
	return 0;                                            // O(1)
}

/*
Time Complexity using Substitution Method:
Let T(n) be the time for insertion sort with input size n.
In worst case, the inner while loop runs i times for each i.
T(n) = T(n-1) + (n-1) + c
	 = T(n-2) + (n-2) + (n-1) + 2c
	 = ...
	 = T(1) + (2 + 3 + ... + (n-1)) + (n-1)c
	 = T(1) + (n-1)(n-2)/2 + (n-1)c
	 = O(n^2)

Time Complexity using Frequency Method:
Outer loop runs (n-1) times.
Inner loop shifts (worst case):
	1 + 2 + ... + (n-1) = n(n-1)/2
Assignments and comparisons proportional to n(n-1)/2 + (n-1) = O(n^2).
Best case (already sorted): O(n).
Average and Worst case: O(n^2).
*/