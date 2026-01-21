/*Write the Recursive as well as iterative codes for bubble sort
-calculate the time complexity 
a)frequency count m/d
b)substituion m/d(find the recursive relation 1st)*/
#include <iostream>
using namespace std;

/* ITERATIVE BUBBLE SORT */
void bubbleSortIterative(int arr[], int n) {
    // Outer loop: n-1 passes
    for (int i = 0; i < n - 1; i++) {
        // Inner loop: compare adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    bubbleSortIterative(arr, n);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}