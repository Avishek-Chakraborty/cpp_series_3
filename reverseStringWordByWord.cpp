#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

string reverseStringWordByWord(const string &input) {
    stringstream ss(input);
    vector<string> words;

    string word;
    while (ss >> word) {
        reverse(word.begin(), word.end());
        words.push_back(word);
    }

    // reverse(words.begin(), words.end());

    string reversedString;
    for (const string &w : words) {
        reversedString += w + " ";
    }

    reversedString.pop_back();  // Remove the trailing space

    return reversedString;
}

int main() {
    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString);

    string reversedString = reverseStringWordByWord(inputString);

    cout << "Reversed string: " << reversedString << endl;

    return 0;
}
