#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define en << endl
struct check{
    bool is_there = false;
    int position = 0;
};
map<int, check> arr;
int main(){
    ll n, sum, temp;
    cin >> n >> sum;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(arr[sum - temp].is_there) {
            cout << arr[sum - temp].position << " " << i + 1;
            return 0;
        }
        arr[temp].is_there = true;
        arr[temp].position = i + 1;
    }
    cout << "IMPOSSIBLE";
}