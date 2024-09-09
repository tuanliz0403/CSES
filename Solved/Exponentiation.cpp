#include <bits/stdc++.h>
#define ll long long
#define cen cout << "\n";

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;

    while(n--){
        int a, b;
        cin >> a >> b;
        ll temp = a, ans = 1;

        while(b){
            if(b&1) ans = (ans * temp) % MOD;
            temp = (temp * temp) % MOD;
            b>>=1;
        }
        cout << ans; cen
    }
}