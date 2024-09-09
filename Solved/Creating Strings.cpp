#include <bits/stdc++.h>
using namespace std;
#define INT long long
#define MOD 1000000007
set<string> check;
 
void run(string str, int curr, int n){
    if(curr == n) return;
    check.insert(str);
    for(int i = 0; i < n; i++){
        swap(str[curr], str[i]);
        run(str, curr + 1, n);
        swap(str[curr], str[i]);
    }
}
int main(){
    string st = "abc";
    cin >> st;
    sort(st.begin(), st.end());
    check.insert(st);
    run(st, 0, st.length());
    cout << check.size() << endl;
    for(auto i:check){
        cout << i << endl;
    }
    return 0;
}