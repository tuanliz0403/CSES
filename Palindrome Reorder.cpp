#include <bits/stdc++.h>
using namespace std;
#define INT long long
#define MOD 1000000007
 
int main(){
    string st;
    int numb[27], odd = 0;
    char odd_letter;
    fill_n(numb, 27, 0);
    cin >> st;
    sort(st.begin(), st.end());
    for(int i = 0; i < st.length(); i++) numb[st[i] - 'A']++;
    st = "";
    for(int i = 0; i < 26; i++) {
        if (numb[i] % 2 != 0) {
            odd++;
            odd_letter = 'A' + i;
        }
        if(odd > 1) {
            cout << "NO SOLUTION";
            return 0;
        }
        for(int j = 0; j < numb[i] / 2; j++)
            st += 'A' + i;
    }
    if (odd == 1){
        cout << st;
        cout << odd_letter;
        reverse(st.begin(), st.end());
        cout << st;
        return 0;
    }
    cout << st;
    reverse(st.begin(), st.end());
    cout << st;
    return 0;
}