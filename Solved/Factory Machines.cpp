
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
const ll inf = LLONG_MAX;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/******************************************MY VARIABLES******************************************/

/******************************************MY FUNCTIONS******************************************/
ll binsearch(ll low, ll high, ll target, vector<ll> *machine)
{
    while (low != high)
    {
        ll mid = low + (high - low) / 2;
        ll sum = 0;
        for (ll i : (*machine))
            sum += (mid / i);
        if (sum < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

signed main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    // ifstream cin("file.inp");
    // ofstream cout("file.out");
    ll n, t;
    cin >> n >> t;
    vector<ll> machine(n, 0);
    f0(n) cin >> machine[i];
    sort(machine.begin, machine.end);
    ll INF = t * machine[0];
    cout << binsearch(1, INF, t, &machine);
    return 0;
}
