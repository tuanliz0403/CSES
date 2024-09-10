#include <bits/stdc++.h>
#define ll long long
#define cen cout << "\n";
#define space << " "
#define f0(n) for(ll i = 0; i < n; i++)
#define fo(a,b) for(ll i = a; i <= b; i++)
using namespace std;
const ll MOD = 1e9 + 7;
const ll mxn = 1e5 + 7;
typedef pair<ll, ll> pii;

queue<int> q;
 
signed main(){
    // ifstream cin("file.inp");
    // ofstream cout("file.out");
    ll n;
    cin >> n;
    fo(1, n) q.push(i);
    bool kill = false;
    while(!q.empty()){
        int curr = q.front(); q.pop();
        if(kill) cout << curr space;
        else q.push(curr);
        kill = !kill;
    }
    return 0;
}