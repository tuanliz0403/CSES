#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define en << endl
const ll mxN = 2e5;
 
int main(){
    ll n, ans = 0;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> arr;
    ll temp;
    for(ll i = 0; i < n; i++) cin >> temp, arr.push(temp);
    temp = 0;
    for(ll i = 0; i < n; i++) {
        ll curr = arr.top();
        arr.pop();
        if(temp + 1 < curr){
            cout << temp + 1;
            return 0;
        }
        else temp += curr;
    }
    cout << temp + 1;
    return 0;
}