/*
Write the code for-
1. Quick Sort 
Complexity
Find the recurrence relation first followed by substituition method
*/

// Quick Sort implementation in C++
// Recursive Lomuto-partition quicksort (single `main`)

#include <iostream>
#include <vector>

int partition(std::vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (a[j] <= pivot) {
            ++i;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(std::vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    int n;
    if (!(std::cin >> n)) return 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        if (i) std::cout << ' ';
        std::cout << a[i];
    }
    std::cout << '\n';
    return 0;
}

/*
=== COMPLEXITY ANALYSIS ===

1. RECURRENCE RELATION:
   T(n) = T(k) + T(n-k-1) + O(n)
   where k is the partition point (0 to n-1)
   O(n) is for partitioning operation
   
2. SUBSTITUTION METHOD:

   Case 1: BEST CASE (Balanced Partition)
   When partition splits array in half:
   T(n) = T(n/2) + T(n/2) + O(n)
   T(n) = 2*T(n/2) + O(n)
   
   Guess: T(n) = O(n log n)
   
   Proof:
   T(n) = 2*T(n/2) + cn
   Assume T(k) = ck log k for k < n
   T(n) = 2*c(n/2)*log(n/2) + cn
        = cn*log(n/2) + cn
        = cn*(log n - log 2) + cn
        = cn*log n - cn + cn
        = cn*log n
    Verified: T(n) = O(n log n)
*/