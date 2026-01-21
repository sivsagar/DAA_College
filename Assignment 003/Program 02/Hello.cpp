/*Write the Recursive as well as iterative codes for binary search
-calculate the time complexity 
a)frequency count m/d
b)substituion m/d(find the recursive relation 1st)*/

#include <iostream>
using namespace std;

// Iterative Binary Search
int binarySearchIterative(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int comparisons = 0;
    
    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            cout << "Comparisons: " << comparisons << endl;
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    cout << "Comparisons: " << comparisons << endl;
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;
    
    int result = binarySearchIterative(arr, n, target);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}

// TIME COMPLEXITY ANALYSIS (Iterative):
// Best Case: O(1) - element found at first comparison
// Average Case: O(log n) - frequency count method
// Worst Case: O(log n) - element not found or at end
// Space Complexity: O(1) - no extra space used