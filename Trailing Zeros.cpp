#include <bits/stdc++.h>
using namespace std;
#define INT long long
#define MOD 1000000007
 
int main(){
    INT n, i = 5, res = 0;
    cin >> n;
    while(n / i != 0){
        res += n / i;
        i*=5;
    }
    cout << res;
    return 0;
}