#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void udp_uti(ll *st, int ss, int se, int si, int idx, int diff){
    if(idx < ss || idx > se) return;
    st[si] += diff;
    if(ss != se){
            int mid = (ss + (se - ss) / 2);
            udp_uti(st, ss, mid, si*2+1, idx, diff);
            udp_uti(st, mid+1, se, si*2+2, idx, diff);
    }
}
 
ll get_sum(ll *st, int ss, int se, int qs, int qe, int si){
    if(qs <= ss && se <= qe) return st[si];
    if(qs > se || qe < ss) return 0;
    int mid = (ss + (se - ss) / 2);
    return(get_sum(st, ss, mid, qs, qe, si * 2 + 1) + get_sum(st, mid + 1, se, qs, qe, si * 2 + 2));
}
 
ll bld_uti(ll arr[], ll *st,int ss,int se,int si){
    if(ss == se) {
        st[si] = arr[ss];
        return st[si];
    }
    int mid = (ss + (se - ss) / 2);
    st[si] =  bld_uti(arr, st, ss, mid, si*2+1) + bld_uti(arr, st, mid + 1, se, si*2+2);
    return st[si];
}
 
ll *bld(ll arr[], int N){
    int max_size = 4*N;
    ll *st = new ll[max_size];
    bld_uti(arr, st, 1, N, 1);
    return st;
}
 
int main()
{
    int n, q;
    cin >> n >> q;
    ll arr[n+1];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    ll *st = bld(arr, n);
    for(int i = 0 ; i < q; i++){
        int qt, a, b;
        cin >> qt >> a>> b;
        if(qt == 2) cout << get_sum(st, 1, n, a, b,  1) << endl;
        else{
            udp_uti(st, 1, n, 1, a, b - arr[a]);
            arr[a] = b;
        }
    }
}