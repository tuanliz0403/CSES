#include <bits/stdc++.h>
 
using namespace std;
int solve(int* s, int &n){
    const int INF = 1e9 + 31;
    int res = 0;
    vector<int> dp(n + 2, INF);
    dp[0] = -INF;
    for(int i = 0; i < n; i++){
        int target = *(s + i);
        int l = upper_bound(dp.begin(), dp.end(), target) - dp.begin();
        if(dp[l - 1] < *(s + i) && *(s+i) < dp[l]) {
            dp[l] = *(s + i);
            res = max(res, l);
        }
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    int* st = (int*) new int[n];
    for(int i = 0; i < n; i++) cin >> *(st + i);
    cout << solve(st, n);
}