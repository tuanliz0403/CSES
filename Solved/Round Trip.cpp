#include <bits/stdc++.h>
#define ll long long
#define cen cout << "\n";
#define space << " "
using namespace std;

const int MOD = 1e9 + 7;
const int mxn = 1e5 + 7;

vector<int> adj[mxn];
vector<int> ans;
bool visited[mxn];
bool found;
int root;

void dfs(int curr, int parent){
    visited[curr] = true;
    for(auto child:adj[curr]){
        if(!visited[child]){
            visited[child] = true;
            dfs(child, curr);
            if(found && root != 0) {
                ans.push_back(curr);
                if(root == curr) root = 0;
                return;
            }
            if(found) return;
        }
        else if(visited[child] && child != parent){
            found = true;
            ans.push_back(child);
            ans.push_back(curr);
            root = child;
            return;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]) dfs(i, 0);
        if(found){
            cout << ans.size(); cen
            for(auto i:ans) cout << i space;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}