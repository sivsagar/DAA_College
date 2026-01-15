#include <stdio.h> 

int main() { 

int m, n, i;                          // 1 
 
printf("Enter the size of array: ");  // 1 
scanf("%d", &m);                      // 1 
 
int arr[m];                           // 1 
 
printf("Enter %d elements: ", m);     // 1 
for (i = 0; i < m; i++) {             // (m + 1) 
   scanf("%d", &arr[i]);             // m 
} 
 
printf("Enter position to delete (1 to %d): ", m); // 1 
scanf("%d", &n);                      // 1 
 
if (n < 1 || n > m) {                 // 1 
   printf("Invalid position\n");     // 1 
   return 1;                         // 1 
} 
 
/* Shift elements to the left */ 
for (i = n - 1; i < m - 1; i++) {     // (m − n) 
   arr[i] = arr[i + 1];              // (m − n) 
} 
 
printf("Array after deletion: ");     // 1 
for (i = 0; i < m - 1; i++) {          // m 
   printf("%d ", arr[i]);             // m 
} 
printf("\n");                          // 1 
 
return 0;                              // 1 
 

} 

