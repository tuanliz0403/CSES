#include <bits/stdc++.h>
using namespace std;
#define INT unsigned long long
#define MOD
int main(){
    INT n;
    cin >> n;
    for(INT i = 1; i <= n; i++){
        if(i == 1) cout << "0" << endl;
        else if(i == 2) cout << "6" << endl;
        else{
            INT sum = ((i * i * (i * i - 1) / 2) - (4 * (i - 1) * (i - 2))) ;
            cout << sum << endl;
        }
    }
    return 0;
}