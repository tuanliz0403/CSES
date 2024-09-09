#include <bits/stdc++.h>
#define ll long long
#define cen cout << "\n";

using namespace std;

const int MOD = 1e9 + 7;
const int mxn = 1e5 + 7;

vector<int> arr[mxn];
bool team[mxn], is_divided[mxn];
bool no_ans = 0;
void dfs(int curr){
    for(auto child:arr[curr])
        {
            if(no_ans) return;
            if(is_divided[child] == false){
                team[child] = team[child] == team[curr];
                is_divided[child] = true;
                dfs(child);
            }
            // else if(is_divided[child] && is_divided[curr] && team[])
            else if(is_divided[child] && team[child] == team[curr]) {
                no_ans = 1;
                return;
            }
        }
    is_divided[curr] = true;
}

int main(){
    int n, m;
    cin >> n >> m;
    memset(team, false, sizeof team);
    memset(is_divided, false, sizeof is_divided);
    while(m--){
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        dfs(i);
        if(no_ans) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << team[i] + 1 << " ";
    }
}