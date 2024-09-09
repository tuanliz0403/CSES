#include <bits/stdc++.h>
#define cen cout << "\n";
const int mxn = 2e5 + 7;
 
using namespace std;
 
struct node{
    bool res = false;
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,l = 0, ans = 0, arr[mxn];
    cin >> n;
    map<int, node> check;
    for(int r = 0; r < n; r++) {
        cin >> arr[r];
        if(check[arr[r]].res) {
            while(arr[l] != arr[r] && l < n) check[arr[l++]].res = false;
            l++;
        }
        ans = max(ans,r - l + 1);
        check[arr[r]].res = true;
    }
    cout << ans;
}