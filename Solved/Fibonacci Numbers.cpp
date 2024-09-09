#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll* matrix_multiply(ll* a, ll* b, ll MOD){
    ll x; (x = ((*a) * (*b) + *(a + 1) * *(b + 2))); x %= MOD;
    ll y; (y = ((*a) * *(b + 1) + (*(a + 1)) * *(b + 3))); y %= MOD;
    ll z; (z = (*(a + 2) * (*b) + *(a + 3) * *(b + 2))); z%= MOD;
    ll t; (t = (*(a + 2) * *(b + 1) + *(a + 3) * *(b + 3))); t%= MOD;
    *a = x;
    *(a+1) = y;
    *(a+2) = z;
    *(a+3) = t;
    return a;
}
 
ll get_power(ll b, ll MOD, ll* arr)
{
    if (b == 0) return 0;
    if(b == 1 || b == 2) return 1;
    b -= 2;
    ll* ans = (ll*) new ll[2][2]{{1,1},{1,0}};
    ll res;
    ll* temp = arr;
    while(b > 0){
        if(b & 1) ans = matrix_multiply(ans, temp, MOD);
        temp = matrix_multiply(temp, temp, MOD);
        b = b >> 1;
    }
    res = *ans;
    return res;
}
 
signed main(){
    ll n;
    const ll MOD = 1e9 + 7;
    cin >> n;
    ll* arr = (ll*) new ll[2][2]{{1,1},{1,0}};
    cout << get_power(n, MOD, arr);
}
