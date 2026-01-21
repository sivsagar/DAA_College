/*Write the Recursive as well as iterative codes for binary search
-calculate the time complexity 
a)frequency count m/d
b)substituion m/d(find the recursive relation 1st)*/
#include <iostream>
using namespace std;

// Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; // Element not found
    }
    
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == target) {
        return mid; // Element found
    }
    else if (arr[mid] > target) {
        return binarySearchRecursive(arr, low, mid - 1, target); // Search in left half
    }
    else {
        return binarySearchRecursive(arr, mid + 1, high, target); // Search in right half
    }
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;
    
    int result = binarySearchRecursive(arr, 0, n - 1, target);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}

/* TIME COMPLEXITY ANALYSIS:
   
   a) Frequency Count Method:
      - Each recursive call: 1 comparison + 1 division
      - Maximum comparisons: log₂(n)
      - T(n) = O(log n)
   
   b) Substitution Method:
      Recurrence Relation:
      T(n) = T(n/2) + 1, where T(1) = 1
      
      T(n) = T(n/2) + 1
           = T(n/4) + 1 + 1
           = T(n/8) + 1 + 1 + 1
           = ...
           = T(1) + log₂(n)
           = 1 + log₂(n)
      
      Therefore: T(n) = O(log n)
*/