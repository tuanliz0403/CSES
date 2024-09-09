#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define en << endl
const ll mxN = 1e6 + 7;
 
ll n;
ll dp[mxN];
int main(){
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= min(6,i); j++)
            dp[i] = (dp[i] + dp[i - j])%MOD;
    }
    cout << dp[n];
}