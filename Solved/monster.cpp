#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define cen cout << "\n";
#define space << " "
#define f0(n) for (ll i = 0; i < n; i++)
#define fo(a, b) for (ll i = a; i <= b; i++)
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
const ll mxn = 1e3 + 7;
const ll inf = LONG_LONG_MAX - 1;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int g[mxn][mxn], m, n;
bool vis[mxn][mxn];
vector<pii> parent;
queue<pair<pii, int>> q, mon;
const pii moves[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const char letter[4] = {'D', 'R', 'U', 'L'};
string res = "";
int ans = 0;
bool escaped = 0;

bool valid(int x, int y, int time)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return 0;
    if (time >= g[x][y])
        return 0;
    return 1;
}

bool escape(int x, int y, int time)
{
    if (!valid(x, y, time))
        return 0;
    if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
        return 1;
    return 0;
}

void pre()
{
    memset(vis, 0, sizeof(vis));
    while (!mon.empty())
    {
        int x = mon.front().fi.fi;
        int y = mon.front().fi.se;
        int time = mon.front().se + 1;
        mon.pop();
        vis[x][y] = true;
        f0(4)
        {
            int xi = x + moves[i].fi, yi = y + moves[i].se;
            if (valid(xi, yi, time) && !vis[xi][yi])
            {
                g[xi][yi] = time;
                mon.push({{xi, yi}, time});
                vis[xi][yi] = true;
            }
        }
    }
}

void solve()
{
    memset(vis, 0, sizeof(vis));
    int cur = -1;
    while (!q.empty())
    {
        int x = q.front().fi.fi;
        int y = q.front().fi.se;
        int time = q.front().se + 1;
        q.pop();
        if (escape(x, y, time - 1))
        {
            escaped = 1;
            ans = time - 1;
            cout << "YES \n" << ans << "\n"; 
            while (cur >= 0)
            {
                res += letter[parent[cur].se];
                cur = parent[cur].fi;
            }
            reverse(res.begin, res.end);
            cout << res;
            return;
        }
        vis[x][y] = true;
        f0(4)
        {
            int xi = x + moves[i].fi, yi = y + moves[i].se;
            if (valid(xi, yi, time) && !vis[xi][yi])
            {
                if (escape(xi, yi, time))
                {
                    escaped = 1;
                    ans = time;
                    res += letter[i];
                    cout << "YES \n" << ans << "\n"; 
                    while (cur >= 0)
                    {
                        res += letter[parent[cur].se];
                        cur = parent[cur].fi;
                    }
                    reverse(res.begin, res.end);
                    cout << res;
                    return;
                }
                q.push({{xi, yi}, time});
                vis[xi][yi] = true;
                parent.push_back({cur, i});
            }
        }
        cur++;
    }
}

signed main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    // ifstream cin("file.inp");
    // ofstream cout("file.out");
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char temp;
            cin >> temp;
            if (temp == '.')
                g[i][j] = 1000006;
            if (temp == 'A')
            {
                q.push({{i, j}, 0});
                g[i][j] = 1000006;
            }
            if (temp == 'M')
            {
                mon.push({{i, j}, 0});
                g[i][j] = 0;
            }
            if (temp == '#')
                g[i][j] = -1;
        }
    }
    pre();
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++)
    //     {
    //         cout << g[i][j] <<  setw(5);
    //     }
    //     cen;
    // }
    solve();
    if (escaped) return 0;
    // {
    //     cout << "YES \n";
    //     cout << ans;
    //     cen;
    //     cout << res;
    // }
    else
        cout << "NO";
    return 0;
}