/*Reverse a singly linked list */
#include <iostream>
using namespace std;
// Time Complexity: O(d) 
// Space Complexity: O(1)
int reverseNumber(int num) {
    int reversed = 0;
    // Loop runs once per digit: O(d)
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    cout << "Reversed number: " << reverseNumber(n) << endl;
    
    return 0;
}