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
// #define begin begin()
// #define end end()
using namespace std;
const ll MOD = 1e9 + 7;
const ll mxn = 1e6 + 7;
const ll inf = LLONG_MAX;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool custom_comparator(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
ll get(vector<pair<ll, ll>> &preSum, ll n, ll val)
{
    ll l = 0;
    ll h = n - 1;
    ll mid;
    ll ans = -1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (preSum[mid].first <= val)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            h = mid - 1;
    }
    return ans;
}
ll sub(ll arr[], ll n, ll x)
{
    ll i;
    for (i = 0; i < n; i++)
        arr[i] -= x;
    ll maxlen = 0;
    vector<pair<ll, ll>> preSum;
    ll sum = 0;
    ll minInd[n];
    for (i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        preSum.push_back({sum, i});
    }
    sort(preSum.begin(), preSum.end(), custom_comparator);
    minInd[0] = preSum[0].second;
    for (i = 1; i < n; i++)
        minInd[i] = min(minInd[i - 1], preSum[i].second);
    sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if (sum >= 0)
            maxlen = i + 1;
        else
        {
            ll ind = get(preSum, n, sum);
            if (ind != -1 && minInd[ind] < i)
                maxlen = max(maxlen, i - minInd[ind]);
        }
    }
    return maxlen;
}
signed main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    ifstream cin("file.inp");
    ofstream cout("file.out");
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    f0(n) cin >> arr[i];
    cout << sub(arr, n, k);
    return 0;
}
