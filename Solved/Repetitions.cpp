#include <bits/stdc++.h>
using namespace std;
#define INT long long
 
int main(){
    string str;
    cin >> str;
    INT res = 1;
    INT l = 0, r = 0;
    while(r < str.length()){
        if(str[l] != str[r]){
            res = (r - l) > res? (r - l) : res;
            l = r;
        }
        r++;
    }
    res = (r - l) > res? (r - l) : res;
    cout << res;
}