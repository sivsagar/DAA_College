/*Write the Recursive as well as iterative codes for bubble sort
-calculate the time complexity 
a)frequency count m/d
b)substituion m/d(find the recursive relation 1st)*/
#include <iostream>
using namespace std;

// Recursive Bubble Sort
void bubbleSortRecursive(int arr[], int n) {
    // Base case: If the size is 1, return
    if (n == 1)
        return;

    // One pass of bubble sort. After this pass, the largest element is moved to the end.
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Recursive call for the remaining elements
    bubbleSortRecursive(arr, n - 1);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSortRecursive(arr, n);

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}