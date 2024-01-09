#include <iostream>
#include <algorithm>
#include<sstream>
#include<vector>

using namespace std;

string revStr(string &str){
    stringstream ss(str);
    vector<string> words;

    string word;

    while(ss>>word){
        reverse(word.begin(), word.end());

        words.push_back(word);
    }

    string ans;

    for(auto it : words){
        ans += it + " ";
    }

    ans.pop_back();

    return ans;

}

int main(){
    string input;
    getline(cin, input);

    string rev = revStr(input);

    cout << rev << endl;

    return 0;

    cout << "Done line 42 \n" << endl;
}