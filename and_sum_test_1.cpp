#include <bits/stdc++.h>
using namespace std;

int f(int a, int b){
    if(b < a && 4 > b){
        b = 2 + a;
        a = 3 + b;
        return f(a, b);
    }

    b = (b+2)+b;
    return a+b;
}

int main(){
    int ans = f(8, 2);
    cout << ans << endl;
}