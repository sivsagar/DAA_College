// Quick Sort implementation in C++
// Methods and Complexity (in comments below)
// File: Hello.cpp

/*
Method (Quick Sort):
- Choose a pivot (here: last element).
- Partition the array so that elements <= pivot are on left, > pivot on right.
- Recursively sort left and right partitions.

Recurrence relations:
- Worst case (pivot is always max/min, partitions of size 0 and n-1):
    T(n) = T(n-1) + Theta(n)
    Expansion (substitution):
        T(n) = T(n-1) + c n
                 = T(n-2) + c(n-1) + c n
                 ...
                 = T(1) + c(2 + 3 + ... + n)
                 = Theta(n^2)
    So worst-case time: Theta(n^2).

- Best case (balanced partitions, pivot splits n into n/2 and n/2):
    T(n) = 2 T(n/2) + Theta(n)
    By substitution:
        Let T(n) = 2T(n/2) + c n
        Expand k times: T(n) = 2^k T(n/2^k) + k c n
        Set k = log_2 n => T(n) = n T(1) + c n log n = Theta(n log n)
    So best/average (balanced) time: Theta(n log n).

- Average case under random pivot assumptions tends to Theta(n log n).
- Space: O(log n) expected (recursion stack), worst-case O(n).

Notes:
- This implementation uses Lomuto partition (pivot = last element).
- No inline functions are used.
*/

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
// Iterative QuickSort without separate functions and without 'using namespace std'
#include <iostream>
#include <vector>
#include <utility>

int main() {
    int n;
    if (!(std::cin >> n)) return 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    // iterative quicksort using explicit stack of (low, high)
    std::vector<std::pair<int,int>> stack;
    stack.emplace_back(0, n - 1);
    while (!stack.empty()) {
        auto [low, high] = stack.back();
        stack.pop_back();
        if (low >= high) continue;

        int pivot = a[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (a[j] <= pivot) {
                ++i;
                std::swap(a[i], a[j]);
            }
        }
        std::swap(a[i + 1], a[high]);
        int p = i + 1;

        if (p + 1 < high) stack.emplace_back(p + 1, high);
        if (low < p - 1) stack.emplace_back(low, p - 1);
    }

    for (int i = 0; i < n; ++i) {
        if (i) std::cout << ' ';
        std::cout << a[i];
    }
    std::cout << '\n';
    return 0;
}