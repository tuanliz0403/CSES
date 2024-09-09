#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define en << endl
 
 
int main(){
    ll n, m;
    cin >> n >> m;
    set<pair<int,int>> tick;
    int temp;
    for(int i = 0; i < n; i++) cin >> temp, tick.insert({temp, i});
    for(int j = 0; j < m; j++) {
        if(tick.empty()) {cout << "-1" en; continue;}
        int val; cin >> val;
        auto tmp = tick.lower_bound({val + 1, 0});
        if(tmp == tick.begin()) {
                cout << "-1" en;
                continue;
        }
        tmp--;
        cout << (*tmp).first en;
        tick.erase(tmp);
    };
    return 0;
}