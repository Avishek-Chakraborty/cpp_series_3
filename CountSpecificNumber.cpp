#include <bits/stdc++.h>
using namespace std;

bool check(int i) {
    while(i != 0) {
        if(i % 10 != 1 && i % 10 != 4 && i % 10 != 9) {
            return false;
        }
        i /= 10;
    }
    return true;
}

int Count (int m, int n){
    if(m > n){
        return -1;
    }
    int ans = 0;
    for(int i = m; i <= n; i++){
        if (check(i)) {
            ans ++;
            cout << i << endl;
        }
        else continue;
    }

    return ans;
}

int main(){
    int m = 100;
    // cout << m ;
    int n = 200;

    int ans = Count(m, n);

    cout << "The answer is :: " << ans << endl;

}