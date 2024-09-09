#include <bits/stdc++.h>
using namespace std;
#define INT long long
 
int main(){
    INT n, x, y, s, max_value;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> y >> x;
        s = max(x,y);
        max_value = s*s;
        if(x == y) cout << max_value - s + 1 << endl;
        else{
            if(s % 2 == 0) swap(x, y);
            cout << (max_value - s + 1) + (x - y) << endl;
        }
    }
}