#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define en << endl
const int mxN = 2e5;
 
int main(){
    ll n, r = LONG_MIN, l = 0, res = LONG_MIN;
    cin >> n;
    ll arr[n], left[n], right[n];
    for(int i = 0; i < n; i++) cin >> arr[i], arr[i] = i == 0? arr[i]:(arr[i - 1] + arr[i]);
    if(n == 1){
        cout << arr[0];
        return 0;
    }
    for(int i = 0; i < n; i++){
        l = min(l, arr[i]);
        r = max(r,arr[n - i - 1]);
        left[i] = l;
        right[n - i - 1] = r;
    }
    for(int i = 1; i < n; i++){
        res = max(res, right[i] - left[i - 1]);
    }
    cout << res;
}