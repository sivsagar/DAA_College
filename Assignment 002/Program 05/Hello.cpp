/*Find the no. off words in a given sentence*/
#include <iostream>
using namespace std;

int countWords(const string& sentence) {
    int count = 0;
    bool inWord = false;

    for (char ch : sentence) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            inWord = false;
        } else {
            if (!inWord) {
                count++;
                inWord = true;
            }
        }
    }
    return count;
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    int wordCount = countWords(sentence);
    cout << "Number of words: " << wordCount << endl;
    return 0;
}