#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ll n; cin >> n;
    for(int i = 0; i < 1 << n; i++){
        string st = "", tmp;
        for(int j = n - 1; j >= 0; j--) {
                if(i >> j & 1) st += "1";
                else st += "0";
        }
        tmp = st;
        for(int j = 1; j < n; j++)
            if(st[j] == st[j - 1]) tmp[j] = '0';
            else tmp[j] = '1';
        cout << tmp << endl;
    }
    return 0;
}