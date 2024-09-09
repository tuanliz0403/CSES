#include <bits/stdc++.h>
using namespace std;
#define INT long long
 
int main(){
    INT n, tmp = 0;
    cin >> n;
    string res = "";
    if(n == 1) cout << 1;
    else if(n <= 3) cout << "NO SOLUTION";
    else {
        while(tmp + 4 <= n){
            tmp += 4;
            res += to_string(tmp - 1) + " " + to_string(tmp - 3) + " " + to_string(tmp) + " " + to_string(tmp - 2) + " ";
        }
        if(n - tmp == 1) res = to_string(n) + " " + res;
        else if (n - tmp == 2) res = to_string(n) + " " + res + to_string(n - 1);
        else if (n - tmp == 3) res = to_string(n - 1) + " " + res + to_string(n) + " " + to_string(n - 2) ;
    }
    cout << res;
}