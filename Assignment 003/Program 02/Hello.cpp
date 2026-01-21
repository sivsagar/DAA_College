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


// FREQUENCY COUNT METHOD (Iterative):
// Let f(n) = number of comparisons for n elements
// Each iteration eliminates half the search space
// f(n) = 1 + f(n/2)
// f(n) = 1 + 1 + f(n/4) = 2 + f(n/4)
// f(n) = 1 + 1 + ... + 1 (k times) where 2^k = n
// f(n) = k = log₂(n)
// Therefore: T(n) = O(log n)

// SUBSTITUTION METHOD (Iterative):
// Recurrence Relation: T(n) = T(n/2) + 1, with T(1) = 1
// Assume T(n) = O(log n)
// Proof by induction:
// Base case: T(1) = 1 = log₂(1) + 1 
// Inductive step: Assume T(n/2) = log₂(n/2) + 1
// T(n) = T(n/2) + 1 = log₂(n/2) + 1 + 1 = log₂(n) - log₂(2) + 2
//      = log₂(n) - 1 + 2 = log₂(n) + 1
// Therefore: T(n) = O(log n) 