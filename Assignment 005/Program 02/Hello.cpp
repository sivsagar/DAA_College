/*Insertion sort and find time comeplexity using substituion and frequency method*/

#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
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

	insertionSort(arr, n);

	cout << "Sorted array: ";
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << (i + 1 == n ? '\n' : ' ');
	}

	delete[] arr;
	return 0;
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