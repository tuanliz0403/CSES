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
 
priority_queue<pii, vector<pii>, greater<pii>> adj[mxn];
priority_queue<pii, vector<pii>, greater<pii>> q;
bool visited[mxn];
vector<ll> min_cos(mxn, LONG_LONG_MAX);

 
signed main(){
    // ifstream cin("file.inp");
    // ofstream cout("file.out");
    ll n, m;
    cin >> n >> m;
    while(m--){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push(make_pair(c,b));
    }
    memset(visited, false, sizeof visited);
    q.push({0, 1});
    min_cos[1] = 0;
    while(!q.empty()){
        pii curr = q.top(); q.pop();
        if(visited[curr.second]) continue;
        visited[curr.second] = true;
        while(!adj[curr.second].empty()){
            pii child = adj[curr.second].top(); adj[curr.second].pop();
            min_cos[child.second] = min(min_cos[child.second], min_cos[curr.second] + child.first);
            q.push({min_cos[child.second],child.second});
        }
    }
fo(1, n) cout << min_cos[i] space;
}