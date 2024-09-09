#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define en << endl
int main(){
    ll n, s = 0, ans = 0; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; ++i) cin >> p[i], s+=p[i];
 
    for(int i = 0; i < 1 << n; i++){
        ll temp = 0;string st = "";
        for(int j = 0; j < n; j++) if(i >> j & 1) {
            temp += p[j];
            st += to_string(p[j]) + " ";
        }
//        cout << "#" << temp en;
//        cout << st << endl;
        if(temp <= s / 2) ans = max(ans, temp);
    }
    cout << s - ans * 2;
    return 0;
}