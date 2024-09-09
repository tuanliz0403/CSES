#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int get(int* st, int ss, int se, int si, int &qs, int &qe){
    if(qs <= ss && se <= qe) return st[si];
    if(qe < ss || qs > se) return 0;
    int mid = ss + (se - ss) / 2;
    return (get(st, ss, mid, si * 2 + 0, qs, qe) ^ get(st, mid + 1, se, si * 2 + 1, qs, qe));
}
 
int bld_uti(int* arr, int* st, int ss, int se, int si){
    if(ss == se) {
        st[si] = *(arr+ss);
//        cout << si << "#" << st[si] << endl;
        return st[si];
    }
    int mid = ss + (se - ss) / 2;
    st[si] = bld_uti(arr, st, ss, mid, si*2 + 0) ^ bld_uti(arr,st,mid+1,se,si*2+1);
//    cout << si << "#" << st[si] << endl;
    return st[si];
}
 
int *bld(int* arr, int &n){
    int max_size = 2*(1 << (int)ceil(log2(n)));
    int* st = new int[max_size];
    bld_uti(arr, st, 1, n, 1);
    return st;
}
 
int main()
{
    int n, q;
    cin>>n>>q;
    int arr[n + 1];
    for(int i=1;i<=n;i++) cin>>arr[i];
    int* st = bld(arr,n);
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << get(st, 1, n, 1, a, b) << endl;
    }
}