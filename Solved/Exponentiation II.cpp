#include <bits/stdc++.h>
#define ll long long
#define cen cout << "\n";

using namespace std;

const int MOD = 1e9 + 7;

ll expo(int a, int b,int MOD){
    ll temp = a, ans = 1;
        while(b){
            if(b&1) ans = (ans * temp) % MOD;
            temp = (temp * temp) % MOD;
            b>>=1;
        }
    return ans;
}

int main(){
    int n;
    cin >> n;

    while(n--){
        int a, b, c;
        cin >> a >> b >> c;
        b = expo(b,c, MOD-1);
        a = expo(a,b, MOD);
        cout << a; cen
    }
}