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
        for(auto j = i + 1; j < n; j++){
            int third = sum - arr[i].fi - arr[j].fi;    
            if(third <= 0) continue;
            pii target = {third,0};
            auto itr = lower_bound(arr.begin + j + 1, arr.end, target);
            if(itr != arr.end && (*itr).first == target.first){
                cout << arr[i].se space << arr[j].se space << (*itr).se;
                return 0;
            }
        }

    cout << "IMPOSSIBLE";
    return 0;
}