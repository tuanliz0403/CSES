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
// #define begin begin()
// #define end end()
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
    int n, temp;
    cin >> n;
    vector<int> ans(n);
    vector<int> arr(n);
    stack<int> s;
    f0(n) cin >> arr[i];
    f0(n) {
        if(s.empty()){
            s.push(i);
            continue;
        }
        while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
        if(s.empty()) ans[i] = 0;
        else ans[i] = s.top() + 1;
        s.push(i);
    }
    f0(n) cout << ans[i] space;
    return 0;
}