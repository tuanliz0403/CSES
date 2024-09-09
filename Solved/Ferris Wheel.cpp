#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define en  endl
int main(){
    ll n, m, ans = 0, sum = 0;
    cin >> n >> m;
    int child[n];
    for(int i = 0; i < n; i++) cin >> child[i] , sum += child[i];
    sort(child, child + n);
    int l = 0, r = n - 1;
    while(l <= r){
        int temp = m,  i = 0;
        while(temp > 0 && l <= r && i < 2){
            i++;
            if(temp - child[r] >= 0 && l <= r){
                temp -= child[r];
                sum -= child[r];
                r--;
                if(temp == 0 || sum == 0 || i == 2) ans++;
                continue;
            }
            if(temp - child[l] >= 0 && l <= r){
                temp -= child[l];
                sum -= child[l];
                l++;
                if(temp == 0 || sum == 0 || i == 2) ans++;
                continue;
            }
            ans++;
            break;
        }
    }
    cout << ans;
}