/*Insert an element at nth position in an array*/
#include <iostream>
using namespace std;

int main() {
    int arr[100], n, pos, element;
    
    cout << "Enter size of array: ";
    cin >> n;
    
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter position to insert (1 to " << n + 1 << "): ";
    cin >> pos;
    
    cout << "Enter element to insert: ";
    cin >> element;
    
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position!\n";
        return 0;
    }
    
    // Shift elements to the right
    for (int i = n; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }
    
    // Insert element at position
    arr[pos - 1] = element;
    n++;
    
    cout << "Array after insertion:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}