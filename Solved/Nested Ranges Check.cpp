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
#define be begin()
#define en end()
using namespace std;
const ll MOD = 1e9 + 7;
const ll mxn = 1e5 + 7;
const ll inf = LLONG_MAX;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct tri{
    int fi;
    int se;
    int pos;
    tri(int f, int s, int p){
        fi = f;
        se = s;
        pos = p;
    }
};

bool customcomparator1(tri a, tri b){
    if(a.fi != b.fi) return a.fi < b.fi;
    else return a.se > b.se;
}
bool customcomparator2(tri a, tri b){
    return a.pos < b.pos;
}
signed main(){
    // ifstream cin("file.inp");
    // ofstream cout("file.out");
    ll n;
    cin >> n;
    vector<tri> arr;
    int is_contained[n];
    fo(0,n-1){
        int x, y;
        cin >> x >> y;
        tri temp = tri(x,y,i);
        arr.pb(temp);
    }
    sort(arr.begin(), arr.end(), customcomparator1);
    int r = INT_MAX;
    for(auto i = arr.rbegin(); i != arr.rend(); ++i){
        is_contained[(*i).pos] += (*i).se >= r?1:0;
        r = min(r, (*i).se);
    }
    for(auto i:is_contained) {
         i = 0;
        cout << i space;
    }
    r = 0;cen
    for(auto i:arr){
        is_contained[i.pos] += (i.se <= r? 1:0);
        r = max(r, i.se);
    }
    for(auto i:is_contained) {
        cout << i space;
        i = 0;
    }
    return 0;
}