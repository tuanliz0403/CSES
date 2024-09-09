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
        int a, ans = 0;
        cin >> a;
        for(int i = 1; i <= sqrt(a); i++) {
            if(a % i == 0 && a / i != i) ans+=2;
            else if(a % i == 0) ans++;
        }
        cout << ans; cen
    }
}