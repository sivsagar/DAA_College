/*Delete the nth element from an array of 'm' no.s n<=m */
#include <stdio.h>

int main() {
    int m, n, i;
    
    printf("Enter the size of array: ");
    scanf("%d", &m);
    
    int arr[m];
    printf("Enter %d elements: ", m);
    for (i = 0; i < m; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter position to delete (1 to %d): ", m);
    scanf("%d", &n);
    
    if (n < 1 || n > m) {
        printf("Invalid position\n");
        return 1;
    }
    
    // Shift elements left by one position from index n-1
    for (i = n - 1; i < m - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    printf("Array after deletion: ");
    for (i = 0; i < m - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}