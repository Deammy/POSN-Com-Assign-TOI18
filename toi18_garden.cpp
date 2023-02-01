#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll N,T;
    cin >> N >> T;
    ll tree[N+1];
    ll treerev[N+1];
    ll mem[N+1];
    ll memrev[N+1];
    for(int i = 0 ; i < N ; i++){
        cin >> tree[i];
        treerev[N - 1 - i] = tree[i];
    }
    vector<ll> lis;
    vector<ll> lisrev;
    for(int i = 0 ; i < N ; i++){

        auto x = lower_bound(lis.begin(),lis.end(),tree[i]);
        mem[i] = x - lis.begin() + 1;
        if(x != lis.end()) lis[x - lis.begin()] = tree[i];
        else lis.push_back(tree[i]);


        auto y = lower_bound(lisrev.begin(),lisrev.end(),treerev[i]);
        memrev[i] = y - lisrev.begin() + 1;
        if(y != lisrev.end()) lisrev[y - lisrev.begin()] = treerev[i];
        else lisrev.push_back(treerev[i]);
    }
    /*for(int i = 0 ; i < N ; i++){
        cout << mem[i] << " ";
    }
    cout << "\n";
    for(int i = 0 ; i < N ; i++){
        cout << memrev[i] << " ";
    }*/
    for(int i = 0 ; i < T ; i++){
        ll a;
        cin >> a;
        cout << min(mem[a] , memrev[N - 1 - a]) - 1 << "\n";
    }

}
