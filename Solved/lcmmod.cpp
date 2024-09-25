#include <bits/stdc++.h>
#define ll unsigned long long
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
const ll mxn = 1000007;
const ll inf = LLONG_MAX;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;

ll prime[mxn];
unordered_map<int, int> max_map;

ll power(int a, int n, ll mod)
{
    ll temp = a;
    ll ans = 1;
    while (n != 0)
    {
        if (n & 1)
            ans *= temp;
        temp *= temp;
        n >>= 1;
    }
    return ans;
}
void sieve()
{
    prime[0] = 1;
    prime[1] = 1;
    for (ll i = 2; i < mxn; i++)
    {
        if (prime[i] == 0)
        {
            for (ll j = i * 2; j < mxn; j += i)
            {
                if (prime[j] == 0)
                    prime[j] = i;
            }
            prime[i] = i;
        }
    }
}
ll solve(const ll *ar, ll n, ll mod)
{
    for (ll i = 0; i < n; i++)
    {
        ll num = ar[i];
        unordered_map<int, int> temp;
        while (num > 1)
        {
            ll factor = prime[num];
            temp[factor]++;
            num /= factor;
        }
        for (auto it : temp)
            max_map[it.first] = max(max_map[it.first], it.second);
    }
    ll ans = 1;
    for (auto it : max_map)
        ans = (ans * power(it.first, it.second, mod)) % mod;
    return ans;
}

signed main()
{
    sieve();
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    ifstream cin("file.inp");
    ofstream cout("file.out");
    ll n = 1;
    vector<ll> a;
    while (cin >> n)
        if (n != 0)
            a.pb(n);
    ll mod_n = *(a.end - 1);
    a.pop_back();
    ll arr[a.size()];
    ll S = a.size();
    for (ll i = 0; i < a.size(); i++)
        arr[i] = a[i];
    cout << solve(arr, S, mod_n);
    return 0;
}
