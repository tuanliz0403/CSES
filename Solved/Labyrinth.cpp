#include <bits/stdc++.h>
#define cen cout << endl;
using namespace std;
 
char mat[1002][1002];
const int xi[4] = {1,0,-1,0};
const int yi[4] = {0,1,0,-1};
typedef pair<int,int> pi;
queue<pi> q;
vector<char> p;
string ans;
bool check = true;
int target_x, target_y;
 
void domain_expansion(int x, int y){
 
}
 
int main(){
    int n, m;
    char temp;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == 'A') q.push({i,j});
            if(mat[i][j] == 'B') {
                target_x = i;
                target_y = j;
            }
        }
    while(!q.empty() && check){
        int x = q.front().first, y = q.front().second;
        q.pop();
//
        int new_x = x +xi[0], new_y = y + yi[0];
        if(mat[new_x][new_y] == '.' || mat[new_x][new_y] == 'B') {
        mat[new_x][new_y] = 'D';
        q.push({new_x,new_y});
        if(new_x == target_x && new_y == target_y){
                check = false;
                int a = target_x, b = target_y;
                while(true){
                    if(mat[a][b] == 'A') break;
                    ans += mat[a][b];
                    if(mat[a][b] == 'D') {a -= xi[0]; b-=yi[0];}
                    else if(mat[a][b] == 'R') {a -= xi[1]; b-=yi[1];}
                    else if(mat[a][b] == 'U') {a -= xi[2]; b-=yi[2];}
                    else if(mat[a][b] == 'L') {a -= xi[3]; b-=yi[3];}
                }
                reverse(ans.begin(), ans.end());
                cout << "YES" << endl << ans.length() << endl;
                cout << ans;
                return 0;
            }
        }
//
            new_x = x +xi[1], new_y = y + yi[1];
        if(mat[new_x][new_y] == '.' || mat[new_x][new_y] == 'B') {
        mat[new_x][new_y] = 'R';
        q.push({new_x,new_y});
        if(new_x == target_x && new_y == target_y){
                check = false;
                int a = target_x, b = target_y;
                while(true){
                    if(mat[a][b] == 'A') break;
                    ans += mat[a][b];
                    if(mat[a][b] == 'D') {a -= xi[0]; b-=yi[0];}
                    else if(mat[a][b] == 'R') {a -= xi[1]; b-=yi[1];}
                    else if(mat[a][b] == 'U') {a -= xi[2]; b-=yi[2];}
                    else if(mat[a][b] == 'L') {a -= xi[3]; b-=yi[3];}
                }
                reverse(ans.begin(), ans.end());
                cout << "YES" << endl << ans.length() << endl;
                cout << ans;
                return 0;
            }
        }
//
            new_x = x +xi[2], new_y = y + yi[2];
        if(mat[new_x][new_y] == '.' || mat[new_x][new_y] == 'B') {
        mat[new_x][new_y] = 'U';
        q.push({new_x,new_y});
        if(new_x == target_x && new_y == target_y){
                check = false;
                int a = target_x, b = target_y;
                while(true){
                    if(mat[a][b] == 'A') break;
                    ans += mat[a][b];
                    if(mat[a][b] == 'D') {a -= xi[0]; b-=yi[0];}
                    else if(mat[a][b] == 'R') {a -= xi[1]; b-=yi[1];}
                    else if(mat[a][b] == 'U') {a -= xi[2]; b-=yi[2];}
                    else if(mat[a][b] == 'L') {a -= xi[3]; b-=yi[3];}
                }
                reverse(ans.begin(), ans.end());
                cout << "YES" << endl << ans.length() << endl;
                cout << ans;
                return 0;
            }
        }
//
        new_x = x +xi[3], new_y = y + yi[3];
        if(mat[new_x][new_y] == '.' || mat[new_x][new_y] == 'B') {
        mat[new_x][new_y] = 'L';
        q.push({new_x,new_y});
        if(new_x == target_x && new_y == target_y){
                check = false;
                int a = target_x, b = target_y;
                while(true){
                    if(mat[a][b] == 'A') break;
                    ans += mat[a][b];
                    if(mat[a][b] == 'D') {a -= xi[0]; b-=yi[0];}
                    else if(mat[a][b] == 'R') {a -= xi[1]; b-=yi[1];}
                    else if(mat[a][b] == 'U') {a -= xi[2]; b-=yi[2];}
                    else if(mat[a][b] == 'L') {a -= xi[3]; b-=yi[3];}
                }
                reverse(ans.begin(), ans.end());
                cout << "YES" << endl << ans.length() << endl;
                cout << ans;
                return 0;
            }
        }
    }
    cout << "NO";
}