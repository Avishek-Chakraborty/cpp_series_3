#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int fun(vector<int>& vec){
    int countn = 0;
    for(int it : vec){
        if(it < 0) continue;
        int root = static_cast<int>(sqrt(it));
        if((root * root) == it){
            countn ++;
        } 
    }
    return countn;
}

int main(){
    int n, num;
    cin >> n;
    vector<int> vec;
    for(int i =0; i< n; i++){
        cin >> num;
        vec.push_back(num);
    }
    int ans = fun(vec);

    cout << ans << endl;

    cout << "Line 31 " << endl;

    return 190;
}