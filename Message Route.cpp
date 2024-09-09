#include <bits/stdc++.h>
#define cen cout << endl;
using namespace std;
const int N = 1e5 + 7;
 
vector<int> route[N];
vector<int> ans;
bool not_visited[N];
int parent[N];
queue<int> q;
int main(){
    int m,n;
    cin>>n>>m;
    memset(not_visited, true, sizeof not_visited);
    memset(parent, 0, sizeof parent);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        route[a].push_back(b);
        route[b].push_back(a);
    }
    q.push(1);
    while(!q.empty()){
        int current = q.front();
        not_visited[current] = false;
        q.pop();
        for(auto i:route[current])
            if(not_visited[i]){
                not_visited[i] = false;
                parent[i] = current;
                if(i == n){
                    ans.push_back(n);
                    int trace = parent[i];
                    while(trace != 0){
                        ans.push_back(trace);
                        trace = parent[trace];
                    }
                    cout << ans.size() << endl;
                    for(int i = ans.size() - 1; i >= 0; i--)
                        cout << ans[i] << " ";
                    return 0;
                }
                q.push(i);
            }
    }
    cout << "IMPOSSIBLE";
}