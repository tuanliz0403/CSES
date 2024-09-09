#include <bits/stdc++.h>
using namespace std;
#define INT long long
#define MOD 1000000007
 
int main(){
    INT n, x, y;
    cin >> n;
    for(INT i = 0; i < n; i++){
        cin >> x >> y;
        if(x == y) {
            if (x % 3 == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
            continue;
        }
        if(x < y) swap(x,y);
        if(x - y <= y && ((x - 2*y) % 3 == 0 || 2*y - x == 0))
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}