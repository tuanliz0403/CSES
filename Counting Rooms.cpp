#include <bits/stdc++.h>
#define cen cout << endl;
using namespace std;
 
bool mat[1007][1007];
const int xi[4] = {1,0,-1,0};
const int yi[4] = {0,1,0,-1};
typedef pair<int,int> pi;
queue<pi> q;
 
void domain_expansion(int x, int y){
    mat[x][y] = false;
    for(int i = 0; i < 4; i++){
        if(mat[x+xi[i]][y+yi[i]]) domain_expansion(x+xi[i], y+yi[i]);
    }
}
 
int main(){
    int n, m, ans = 0;
    char temp;
    cin >> n >> m;
    for(int i = 0; i <= m; i++) {
        mat[0][i] = 0;
        mat[n + 1][i] = 0;
    }
    for(int i = 0; i <= n; i++) {
        mat[i][0] = 0;
        mat[i][m + 1] = 0;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> temp, mat[i][j] = temp == '.';
            if(temp == '.') q.push({i,j});
        }
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(mat[x][y]) {
            domain_expansion(x,y);
            ans++;
        }
    }
    cout << ans;
}