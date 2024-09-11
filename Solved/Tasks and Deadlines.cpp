#include <bits/stdc++.h>
#define ll long long
#define cen cout << "\n";
#define space << " "
#define f0(n) for(int i = 0; i < n; i++)
#define fo(a,b) for(int i = a; i <= b; i++)
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
 
 bool comparator(pii a, pii b){
    int days = a.fi + b.fi;
    int res1 = a.se - a.fi + b.se - days, res2 = b.se - b.fi + a.se - days;
    if(res1!=res2) return res1 > res2;
    return a.se < b.se;
 }
 
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    // ifstream cin("file.inp");
    // ofstream cout("file.out");
    int n;
    cin >> n;   
    vector<pll> arr(n);
    f0(n) cin >> arr[i].fi >> arr[i].se;
    sort(arr.begin, arr.end, comparator);
    ll days = 0, count = 0;
    for(int i = 0; i < n; i++){
        days += arr[i].fi;
        count += (arr[i].se - days);
    }
    cout << count;
    return 0;
}
