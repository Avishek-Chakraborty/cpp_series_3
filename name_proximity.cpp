#include <bits/stdc++.h>
using namespace std;

int nameProximity(string a, string b){
    string s1 = a;
    string s2 = b;

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

    int ans = 0;
    for(int i = 0; i< s1.length(); i++){
        for(int j = 0; j < s2.length(); j++){
            if(s1[i] == s2[j] && i==j){
                ++(++ans);
                s2[j] = '#';
                continue;
            }
        }
    }

    return ans;
    // cout << s1 << endl << s2 << endl;
}

int main(){
    // string a = "Amitkkk";
    // string b = "Annik";

    string a = "Amitabh";
    string b = "Ajitabh";

    int ans = nameProximity(a, b);

    cout << ans << endl;

    return 0;

}

