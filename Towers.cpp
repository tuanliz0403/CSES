#include <bits/stdc++.h>
#define cen cout << "\n";
const int mxn = 2e5 + 7;
 
using namespace std;
typedef pair<int,int> pii;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, ans = 0;
    set<pii> q;
    cin >> n;
    vector<pii> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i].first, arr[i].second = i;
    for(int i = 0; i < n; i++) {
        set<pii>::iterator pos = q.upper_bound(arr[i]);
        if(pos != q.end()) q.erase(pos);
        else ans++;
        q.insert(arr[i]);
    }
    cout << ans;
}