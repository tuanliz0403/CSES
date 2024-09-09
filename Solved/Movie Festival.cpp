#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define en << endl
typedef pair<ll,ll> pi;
 
int main(){
    ll n, x, y;
    priority_queue<pi,vector<pi>, greater<pi>> e;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> x >> y;
        e.push({y,x});
    }
    ll l = 0, res = 0;
    while(!e.empty()){
        pi i = e.top();
        if(i.second >= l) {
            res++;
            l = i.first;
        }
        e.pop();
    }
    cout << res;
}