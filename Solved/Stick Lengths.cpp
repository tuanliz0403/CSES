#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define en << endl
const int mxN = 2e5;
 
int main(){
    ll n, ans = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 0; i < n; i++) ans += abs(arr[i] - arr[n / 2 + n % 2 - 1]);
    cout << ans;
}