#include <bits/stdc++.h>
#define ll long long int
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
#define inf LLONG_MAX



using namespace std;
const ll MOD = 1e9 + 7;
const ll mxn = 1e6 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/******************************************MY VARIABLES******************************************/
int n, m, q;
/******************************************MY FUNCTIONS******************************************/

signed main()
{
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  //ifstream cin("file.inp");
  // ofstream cout("file.out");
  cin >> n >> m >> q;
  ll mat[n + 1][n + 1];
  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++) 
    {
      if(i == j) mat[i][j] = 0;
      else
      mat[i][j] = inf;   
    }
  f0(m){
	  ll x, y, weight;
	  cin >> x >> y >> weight;
	  mat[x][y] = min(mat[x][y], weight);
	  mat[y][x] = min(mat[y][x], weight);
  }
  for(int k = 1; k <= n; k++)
  	for(int i = 1; i <= n; i++){
	  	for(int j = 1; j <= n; j++)
			if(mat[i][k] != inf && mat[k][j] != inf)
			  mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
  }
  f0(q){
	  int x, y;
	  cin >> x >> y;
    if(mat[x][y] != inf)
	  cout << mat[x][y] << "\n";
    else cout << -1 << "\n";
  }
  return 0;
}
