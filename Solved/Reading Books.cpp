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
 
 
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    // ifstream cin("file.inp");
    // ofstream cout("file.out");
    int n;
    cin >> n;   
    vector<ll> arr(n);
    f0(n) cin >> arr[i];
    sort(arr.begin, arr.end);
    ll sum_1 = 0, sum_2 = 0, max_length = 0;
    for(int i = n - 1; i >= 0; i--){
        if(sum_1 <= sum_2) sum_1 += arr[i];
        else sum_2 += arr[i];
        max_length = max(max_length, arr[i]);
    }
    cout << max(sum_1 + sum_2, max_length * 2);
    return 0;
}
