#include <bits/stdc++.h>
#define cen cout << "\n";
const int mxn = 2e5 + 7;
 
using namespace std;
typedef pair<int,int> pii;
 
struct customsort{
    bool operator()(int a, int b) const{
        return a > b;
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int len, m;
    cin >> len >> m;
    set<int> arr;
    arr.insert(0);
    arr.insert(len);
    multiset<int, customsort> l;
    l.insert(len);
    while(m--){
        int x;
        cin >> x;
        arr.insert(x);
        auto pos = arr.find(x);
        auto n = next(pos);
        auto p = prev(pos);
        int target = *n - *p;
        auto replace = l.find(target);
        l.erase(replace);
        l.insert(*n - x);
        l.insert(x - *p);
        cout << *(l.begin()) << " ";
    }
    return 0;
}