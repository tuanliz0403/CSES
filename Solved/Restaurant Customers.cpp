#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define en << endl
typedef pair<int,int> pi;
 
int main(){
    ll n, x, y;
    priority_queue<pi,vector<pi>, greater<pi>> e;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        e.push({x,1});
        e.push({y, -1});
    }
    int temp = 0;
    int res = 0;
    while(!e.empty()){
        pi i = e.top();
        e.pop();
        temp += i.second;
        res = max(res, temp);
    }
    cout << res;
}