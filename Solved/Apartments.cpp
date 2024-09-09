#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define en  endl
int main(){
//    ifstream inp;
//    inp.open("file.inp");
//        inp >> n >> m >> k;
//        vector<ll> a(n),b(m);
//        bool check[n];
//        for(int i = 0; i < n; i++) inp >> a[i];
//        for(int i = 0; i < m; i++) inp >> b[i];
//
//    inp.close();
    ll n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector<int> a(n),b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    while(i < n){
        while(j < m && b[j] < a[i] - k) j++;
        if(abs(b[j] - a[i]) <= k){
            i++;
            j++;
            ans++;
        }
        else i++;
    }
    cout << ans;
}