#include <iostream>
using namespace std; 

int main() { 

int arr[100], n, pos, element;     // 1 
 
cout << "Enter size of array: ";   // 1 
cin >> n;                          // 1 
 
cout << "Enter " << n << " elements:\n"; // 1 
for (int i = 0; i < n; i++) {      // (n + 1) 
   cin >> arr[i];                 // n 
} 
 
cout << "Enter position to insert (1 to " << n + 1 << "): "; // 1 
cin >> pos;                        // 1 
 
cout << "Enter element to insert: "; // 1 
cin >> element;                    // 1 
 
if (pos < 1 || pos > n + 1) {      // 1 
   cout << "Invalid position!\n"; // 1 
   return 0;                      // 1 
} 
 
/* Shift elements to the right */ 
for (int i = n - 1; i >= pos - 1; i--) { // (n − pos + 1) 
   arr[i + 1] = arr[i];            // (n − pos + 1) 
} 
 
/* Insert element */ 
arr[pos - 1] = element;             // 1 
n++;                                // 1 
 
cout << "Array after insertion:\n"; // 1 
for (int i = 0; i < n; i++) {        // (n + 1) 
   cout << arr[i] << " ";           // n 
} 
cout << "\n";                        // 1 
 
return 0;                            // 1 
 

} 5