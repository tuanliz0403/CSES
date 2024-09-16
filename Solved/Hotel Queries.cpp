#include <bits/stdc++.h>
#define ll long long
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
const ll mxn = 2e5 + 7;
const ll inf = LLONG_MAX;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int arr[mxn];

struct node
{
    int value;
    int ind;
    node *left = NULL;
    node *right = NULL;
};

node *root = new node;

int get(node* cur, int l, int r, int v)
{
    if(cur->value < v) return 0;
    if(l == r)
    {
        cur->value -= v;
        return cur->ind;
    }

    int mid = l + (r - l) / 2;
    if(cur->left->value >= v)
    {
        int idx = get(cur->left, l, mid, v);
        cur->value = max(cur->left->value, cur->right->value);
        return idx;
    }
    else
    {
        int idx = get(cur->right, mid + 1, r, v);
        cur->value = max(cur->left->value, cur->right->value);
        return idx;
    }
    return 0;
}

void bld(node *cur, int l, int r)
{
    if (l == r)
    {
        cur->value = arr[l];
        cur->ind = l;
        return;
    }
    int mid = l + (r - l) / 2;
    if (cur->left == NULL)
        cur->left = new node;
    bld(cur->left, l, mid);
    if (cur->right == NULL)
        cur->right = new node;
    bld(cur->right, mid + 1, r);
    if (cur->left->value > cur->right->value)
    {
        cur->value = cur->left->value;
        cur->ind = cur->left->ind;
    }
    else
    {
        cur->value = cur->right->value;
        cur->ind = cur->right->ind;
    }
    return;
}

signed main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    // ifstream cin("file.inp");
    // ofstream cout("file.out");
    int n, q;
    cin >> n >> q;
    fo(1, n) cin >> arr[i];
    bld(root, 1, n);
    f0(q){
        int g;
        cin >> g;
        cout << get(root, 1, n, g) space;
    }
    return 0;
}