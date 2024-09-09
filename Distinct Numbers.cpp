#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define en << endl
int main(){
    ll n, tmp;
    set<int> p;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> tmp, p.insert(tmp);
    cout << p.size();
}