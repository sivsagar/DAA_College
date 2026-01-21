#include <iostream>
#include <string>
using namespace std; 

int countWords(string sentence) { 

int count = 0;                 // 1 
int i = 0;               d      // 1 
bool inWord = false;           // 1 
 
while (sentence[i] != '\0') {  // (n + 1) 
 
   if (sentence[i] == ' ' ||  // n 
       sentence[i] == '\n' || // n 
       sentence[i] == '\t') { // n 
       inWord = false;        // n 
   } 
   else { 
       if (inWord == false) { // n 
           count++;           // n 
           inWord = true;     // n 
       } 
   } 
   i++;                        // n 
} 
 
return count;                  // 1 
 

} 

int main() { 

string sentence;               // 1 
 
cout << "Enter a sentence: ";  // 1 
getline(cin, sentence);        // 1 (input only) 
 
cout << "Number of words: " 
    << countWords(sentence) << endl; // 1 
 
return 0;                      // 1 
 

} 