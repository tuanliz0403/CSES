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
const ll mxn = 1e5 + 7;
const ll inf = LLONG_MAX;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct check{
    int check = 0;
};

map<ll, check> Map;

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    // ifstream cin("file.inp");
    // ofstream cout("file.out");
    ll n, sum, ans = 0;
    cin >> n >> sum;
    vector<ll> arr(n), fenwick(n + 1);
    Map[0].check = true;
    f0(n) cin >> arr[i];
    ll current = 0;
    for(auto ind:arr){
        current+=ind;
        ll target = current - sum;
        ans += Map[target].check;
        Map[current].check++;
    }
    // fo(0, n) cout << fenwick[i] space;
    cout << ans;
}