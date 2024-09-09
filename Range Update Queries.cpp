#include <bits/stdc++.h>
#define f0(n) for(LL i = 0; i < n; i++)
#define f1(n) for(LL i = 1; i <= n; i++)
using namespace std;
typedef long long LL;
 
LL get(LL idx, vector<LL>& F){
    LL res = 0;
    while(idx > 0){
        res += F[idx];
        idx -= idx & (-idx);
    }
    return res;
}
 
void add(LL idx, LL value, vector<LL>& F){
    while(idx < F.size()){
        F[idx] += value;
        idx += idx & (-idx);
    }
}
 
void upd(LL l, LL r, LL value,vector<LL>&  F){
    add(l, value, F);
    add(r+1, -value, F);
}
 
int main()
{
    LL n, q;
    cin >> n >> q;
    vector<LL> arr(n + 1, 0), F(n+1, 0);
    f1(n) cin >> arr[i], upd(i, i, arr[i], F);
    f0(q){
        LL qt, a, b,c;
        cin >> qt;
        if(qt == 1){
            cin >> a >> b>>c;
            upd(a, b, c, F);
            continue;
        }
        cin >> a;
        cout << get(a, F) << endl;
    }
}
