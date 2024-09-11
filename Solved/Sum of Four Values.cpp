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

struct val{
    bool check = false;
    int i = 0;
    int j = 0;
};
map<int, val> m;

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    // ifstream cin("file.inp");
    // ofstream cout("file.out");
    int n, sum;
    cin >> n >> sum;
    vector<pii> arr;
    int temp;
    f0(n) cin >> temp, arr.pb({temp, i + 1});
    sort(arr.begin, arr.end);
    for(auto i = 0; i < n; i++)
        for(auto j = i + 1; j < n; j++)
            {
                m[arr[i].fi + arr[j].fi].check = true;
                m[arr[i].fi + arr[j].fi].i = arr[i].se;
                m[arr[i].fi + arr[j].fi].j = arr[j].se;
            }
    for(auto i = 0; i < n; i++)
        for(auto j = i + 1; j < n; j++)
        {
            int third = sum - arr[i].fi - arr[j].fi;    
            if(third <= 0) break;
            pii target = {third,0};
            if(m[third].check && arr[i].se != m[third].i && arr[i].se != m[third].j && arr[j].se != m[third].i && arr[j].se != m[third].j){
                cout << arr[i].se space << arr[j].se space << m[third].i space << m[third].j;
                return 0;
            }
        }
    cout << "IMPOSSIBLE";
    return 0;
}