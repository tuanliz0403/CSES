#include <bits/stdc++.h>
#define cen cout << endl;
using namespace std;
 
const int N = 2e5 + 7;
vector<int> tree[N + 1];
int sub[N+1];
 
void dfs(int current, int parent){
    sub[current] = 1;
    for(auto child:tree[current])
    if(child != parent){
        dfs(child, current);
        sub[current] += sub[child];
    }
}
 
void pri(int n){cout << n << " ";}
 
int main(){
    int n;
    cin >> n;
    memset(sub, 0, sizeof sub);
    vector<int> arr(n, 0);
    int temp;
    for(int i = 1; i < n; i++) cin >> temp, temp--, tree[i].push_back(temp), tree[temp].push_back(i);
    dfs(0,-1);
    for(int i = 0; i < n; i++) pri(sub[i] - 1);
}