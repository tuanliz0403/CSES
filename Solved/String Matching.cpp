#include <bits/stdc++.h>
#define ll long long
#define cen cout << "\n";
#define space << " "
#define f0(n) for(ll i = 0; i < n; i++)
#define fo(a,b) for(ll i = a; i != b; i++)
#define pb push_back
#define se second
#define fi first
#define mp(x,y) make_pair(x,y)
#define vec vector
#define ins insert
// #define begin begin()
// #define end end()
using namespace std;
const ll MOD = 1e9 + 7;
const ll mxn = 1e6 + 7;
const ll inf = LLONG_MAX;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string st, target;
int ans;

void solve(){
    int n = st.size();
    vec<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; i++){
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && st[z[i]] == st[i + z[i]]) z[i]++;
        if(i + z[i] - 1 > r){   
            r = i + z[i] - 1;
            l = i;
        }
        if(z[i] == target.size()) ans++;
    }
    // for(auto i:z) cout << i space; cen;
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    // ifstream cin("file.inp");
    // ofstream cout("file.out");
    cin >> st >> target;
    st = target + "#" + st;
    solve();
}