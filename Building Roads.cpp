#include <bits/stdc++.h>
#define cen cout << endl;
using namespace std;
const int N = 1e5 + 7;
vector<int> route[N];
vector<pair<int, int>> ans;
bool not_visited[N];
 
void dfs(int current){
    not_visited[current] = false;
    for(auto i:route[current]) if (not_visited[i]) dfs(i);
}
 
int main(){
    int m,n;
    cin>>n>>m;
    memset(not_visited, true, sizeof not_visited);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        route[a].push_back(b);
        route[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    if(not_visited[i]){
        if(i != 1) ans.push_back({1, i});
        dfs(i);
    }
    cout << ans.size() << endl;
    for(auto i:ans) cout << i.first << " " << i.second << endl;
}