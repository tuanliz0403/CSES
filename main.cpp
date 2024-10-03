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
class Solution
{
public:
  int minSubarray(vector<int> &num, int p)
  {
    int n = num.size();
    vector<long long> pre(n + 1, 0);
    int current = 0;
    for (int i = 0; i < n; i++)
    {
      current += num[i];
      pre[i + 1] = current;
    }
    int rem = current % p;
    for (int i : pre)
      cout << i space;
    return 0;
  }
};
signed main()
{
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  ifstream cin("file.inp");
  // ofstream cout("file.out");
  vector<int> arr;
  int temp;
  int p = 6;
  while (cin >> temp)
    arr.push_back(temp);
  Solution solve;
  int ans = solve.minSubarray(arr, p);
}
