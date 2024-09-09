#include <bits/stdc++.h>
using namespace std;
#define INT long long
#define MOD 1000000007
int n;
vector<pair<int,int>> res;
void run(int curr,int from,int to,int aux)
{
    if(curr == 0) return;
    run(curr - 1, from, aux, to);
    res.push_back(make_pair(from,to));
    run(curr - 1, aux, to, from);
}
int main(){
    cin >> n;
    run(n,1,3,2);
    cout << res.size() << endl;
    for(auto i:res){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}