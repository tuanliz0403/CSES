#include <bits/stdc++.h>
using namespace std;
#define INT long long
 
int main(){
    INT n, tmp, largest = 0, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        if(tmp < largest) res+= largest - tmp;
        largest = max(largest, tmp);
    }
    cout << res;
    return 0;
}