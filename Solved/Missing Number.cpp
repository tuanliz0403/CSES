#include <bits/stdc++.h>
using namespace std;
#define INT long long
 
int main(){
    INT n, sum = 0, temp;
    cin >> n;
    for (INT i = 0 ; i < n - 1; i++){
            cin >> temp;
            sum += temp;
    }
    cout << (n + 1) * n / 2 - sum;
    return 0;
}