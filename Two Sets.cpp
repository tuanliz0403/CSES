#include <bits/stdc++.h>
using namespace std;
#define INT long long
 
int main(){
    INT n, target, s1s = 0, dummy;
    string str1 = "";
    cin >> n;
    dummy = n;
    string s1 = "", s2 = "";
    target = ((n + 1) * n / 2);
    if(target & 1) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    target /= 2;
    while(n){
        if(target - n >= 0){
            target -= n;
            s1 += to_string(n) + " ";
            s1s++;
        }
        else s2 += to_string(n) + " ";
        n--;
    }
    cout << s1s << endl << s1 << endl << dummy - s1s << endl << s2;
    return 0;
}