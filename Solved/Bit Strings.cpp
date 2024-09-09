#include <bits/stdc++.h>
using namespace std;
#define INT long long
#define MOD 1000000007
 
int main(){
    INT n, i = 1;
    cin >> n;
    while(n){
        n--;
        i = i * 2 % MOD;
    }
    cout << i;
    return 0;
}