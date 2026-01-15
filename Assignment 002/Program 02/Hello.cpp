#include <iostream>
using namespace std;

int reverseNumber(int num) { 

int reversed = 0;                 // 1 
 
while (num > 0) {                 // (n + 1) 
   reversed = reversed * 10 + (num % 10); // n 
   num /= 10;                    // n 
} 
 
return reversed;                  // 1 
 

} 

int main() { 

int n;                            // 1 
 
cout << "Enter a number: ";       // 1 
cin >> n;                         // 1 
 
cout << "Reversed number: " 
    << reverseNumber(n) << endl; // 1 
 
return 0;                         // 1 
 

} 