#include <bits/stdc++.h>
using namespace std;
 
int main(){
    unsigned long long n;
    cin >> n;
    while (true){
        cout << n << " ";
        if(n == 1) return 0;
        if(n & 1) n = n * 3 + 1;
        else n /= 2;
    }
    return 0;
}
