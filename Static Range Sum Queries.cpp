#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define en << endl
const ll mxN = 1e6 + 7;
 
 
ll dp[mxN];
 
void add(ll idx, ll x, vector<ll> &F){
 
    while(idx < F.size()){
        F[idx] += x;
        idx += idx&(-idx);
    }
}
 
ll sum(ll idx, vector<ll>& F){
    ll res = 0;
    while(idx > 0){
        res += F[idx];
        idx -= idx & -idx;
    }
    return res;
}
int main(){
    ll n, m;
    cin >> n >> m;
    ll arr[n + 1];
    vector<ll> F(n + 1, 0);
    for(ll i = 1; i <= n; i++)
         cin >> arr[i];
    for(ll i = 1; i <= n; i++)
        add(i, arr[i], F);
//    for(auto i : F) cout << i << " ";
    ll x, y;
    for(ll i = 0; i < m; i++){
        cin >> y >> x;
        cout << sum(x, F) - sum(y - 1,F) << endl;;
 
    }
    return 0;
}