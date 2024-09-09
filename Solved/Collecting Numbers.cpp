#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define en << endl
const int mxN = 2e5;
 
struct value{
    int val = 0;
    int position = 0;
 
    value(int v, int pos){
        val = v;
        position = pos;
    }
};
struct cmpFunction{
    bool operator()(value const &p1, value const &p2){
        return p1.val > p2.val;
    }
};
int main(){
    int n, ans = 0;
    cin >> n;
    priority_queue<value, vector<value>, cmpFunction> arr;
    int temp;
    for(int i = 0; i < n; i++) cin >> temp, arr.push(value(temp, i));
    temp = INT_MAX;
    for(int i = 0; i < n; i++) {
        value tmp = arr.top();
        if(temp > tmp.position) ans++;
        temp = tmp.position;
        arr.pop();
    }
    cout << ans;
}