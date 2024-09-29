#include <bits/stdc++.h>
#define ll long long
#define cen cout << "\n";
#define space << " "
#define f0(n) for (ll i = 0; i < n; i++)
#define fo(a, b) for (ll i = a; i != b; i++)
#define pb push_back
#define se second
#define fi first
#define mp(x, y) make_pair(x, y)
#define vec vector
#define ins insert
#define begin begin()
#define end end()
using namespace std;
const ll MOD = 1e9 + 7;
const ll mxn = 1e6 + 7;
const ll inf = 1e9;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/******************************************MY VARIABLES******************************************/
int n, k;
/******************************************MY FUNCTIONS******************************************/

signed main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    // ifstream cin("file.inp");
    // ofstream cout("file.out");
    cin >> n >> k;
    vector<int> coin(n);
    f0(n) cin >> coin[i];
    vector<int> ans(k + 1, 0);
    ans[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coin[j] > 0 && ans[i - coin[j]] != 0)
                ans[i] = (ans[i] + ans[i - coin[j]]) % MOD;
            else if (i - coin[j] == 0)
                ans[i] = (ans[i] + 1) % MOD;
        }
    }
    cout << ans[k];
    return 0;
}