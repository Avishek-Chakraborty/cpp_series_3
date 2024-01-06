#include <bits/stdc++.h>
using namespace std;

bool check (string x, string y){
    if(x.length() != y.length()){
        return false;
    }
    string s1 = x;
    string s2 = y;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    return s1 == s2;
}

int main(){
    string x = "abcd";
    string y = "cbdd";

    bool ans = check(x, y);

    cout << ans << endl;

}