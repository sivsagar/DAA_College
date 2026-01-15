#include <iostream>
using namespace std; 

int main() { 

int n, reversedNumber = 0, remainder;   // 1 
 
cout << "Enter the number of digits: "; // 1 
cin >> n;                               // 1 
 
int number;                             // 1 
cout << "Enter a " << n << "-digit number: "; // 1 
cin >> number;                          // 1 
 
while (number != 0) {                   // (n + 1) 
   remainder = number % 10;            // n 
   reversedNumber = reversedNumber * 10 + remainder; // n 
   number /= 10;                       // n 
} 
 
cout << "Reversed number: " << reversedNumber << endl; // 1 
 
return 0;                               // 1 
 
}  