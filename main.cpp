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
#define begin begin()
#define end end()
using namespace std;
const ll MOD = 1e9 + 7;
const ll mxn = 2e5 + 7;
const ll inf = LLONG_MAX;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int arr[mxn];

struct node{
    ll val;
    node* left;
    node* right;
};

node* root = new node;

ll get(node* curr, int l, int r, int s, int e){
    if(e < l || s > r) return inf;
    if(l == r) return curr->val;
    if(s <= l && r <= e) return curr->val;
    int mid = l + (r - l) / 2;
    ll s1 = inf, s2 = inf;
    if(s <= mid) s1 = get(curr->left, l, mid, s, e);
    if(e >= mid + 1) s2 = get(curr->right, mid + 1, r, s, e);
    return min(s1,s2);
}

void upd(node* curr, int l, int r, int k, int u){
    if(k < l || k > r) return;
    if(l == r && l == k){
        curr->val = u;
        return;
    }
    int mid = l + (r - l) / 2;
    if(k <= mid) upd(curr->left, l, mid, k, u);
    else upd(curr->right, mid + 1, r, k, u);
    ll s1 = inf, s2 = inf;
    if(curr->left != NULL) s1 = curr->left->val;
    if(curr->right != NULL) s2 = curr->right->val;
    curr->val = min(s1, s2);
    return;
}

void bld(node* curr, int l, int r){
    if(curr == NULL) curr = new node;
    if(l == r) { 
        curr->val = arr[l];
        return;
    }
    int mid = l + (r - l) / 2;
    curr->left = new node;
    bld(curr->left, l, mid);
    curr->right = new node;
    bld(curr->right, mid + 1, r);
    ll s1 = inf, s2 = inf;
    if(curr->left != NULL) s1 = curr->left->val;
    if(curr->right != NULL) s2 = curr->right->val;
    curr->val = min(s1, s2);
    return;
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    // ifstream cin("file.inp");
    // ofstream cout("file.out");
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    bld(root, 1, n);
    f0(q){
        int qt, a, b;
        cin >> qt >> a >> b;
        if(qt == 1){
            upd(root, 1, n, a, b);
        }
        else {
            cout << get(root, 1, n, a, b);
            cen;
        }
    }
    return 0;
}