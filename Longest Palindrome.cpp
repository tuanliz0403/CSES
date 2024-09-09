#include <bits/stdc++.h>
#define cen cout << "\n";
using namespace std;
const int N = 1e3 + 7;
string st, temp = "";
int ans = 0;
pair<int, int> pos;
 
void solve(){
    int l = 1,  r = 1, n = temp.length();
    temp = string("&") + temp + string("^");
    vector<int> arr(n + 2, 0);
    for(int i = 1; i <= n; i++){
        int mirror = l + r - i;
        arr[i] = max(0, min(r - i, arr[mirror]));
        while(temp[arr[i] + i] == temp[i - arr[i]]) arr[i]++;
        if(i + arr[i] > r){
            l = i - arr[i];
            r = i + arr[i];
        }
        if(ans < r - l + 1){
            ans = r - l + 1;
            pos.first = l;
            pos.second = r;
        }
    }
    for(int i = max(pos.first + 1, 1); i < min(pos.second, n + 1); i++) if(temp[i] != '#') cout << temp[i];
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> st;
    for(int i = 0; i < st.length(); i++) temp += string("#") + st[i]; temp += string("#");
    solve();
    return 0;
}