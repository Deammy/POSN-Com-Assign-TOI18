#include<bits/stdc++.h>
using namespace std;
#define ll long long int
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll N,T;
    cin >> N >> T;
    ll road[N+1];
    ll point[N+1];
    road[0] = 0;
    point[0] = 0;
    for(int i = 1 ; i <= N ; i++){
        ll a;
        cin >> a;
        if(a < 0){
            road[i] = road[i-1] + (a *(-1));
            point[i] = point[i-1];
        }
        else{
            road[i] = road[i-1];
            point[i] = point[i-1] + a;
        }
    }

    while(T--){
        ll x,h;
        cin >> x >> h;
        x++;
        auto y = lower_bound(road + 1,road + N + 1,road[x-1] + h);
        //cout << y - road << "\n";
        cout << point[(y - road) - 1] - point[x-1] << "\n";
    }
}