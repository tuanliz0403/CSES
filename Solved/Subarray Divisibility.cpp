#include <bits/stdc++.h>
#define ll long long
#define cen cout << "\n";
#define space << " "
#define f0(n) for(ll i = 0; i < n; i++)
#define fo(a,b) for(ll i = a; i <= b; i++)
#define pb push_back
#define se second
#define fi first
#define mp(x,y) make_pair(x,y)
#define vec vector
#define ins insert
#define begin begin()
#define end end()
using namespace std;
const ll MOD = 1e9 + 7;
const ll mxn = 1e5 + 7;
const ll inf = LLONG_MAX;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<ll, ll> M;
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    // ifstream cin("file.inp");
    // ofstream cout("file.out");
    int n;
    cin >> n;
    // vector<int> arr;
    ll sum = 0, ans = 0;
    M[0] = 1;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        sum += a;
        int remain = sum % n;
        if(remain < 0) remain += n;
        ans += M[remain];
        M[remain]++;
    } 
    cout << ans;
    return 0;
}