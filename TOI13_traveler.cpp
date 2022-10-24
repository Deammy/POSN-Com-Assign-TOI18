
/*TASK:
LANG: C++
AUTHOR: Chayapat Kruthnim
CENTER: WU
*/
//FL539S
#include<bits/stdc++.h>
#define ll long long int
#define d double
using namespace std;
ll qs[10001];
ll qs1[10001];
int N,M;
vector< pair<int,int> > City[10000];
void SP(int st,ll arr[]){
	for(int i = 0 ; i < N ; i++){
		arr[i] = LLONG_MAX;
	}
	arr[st] = 0;
	priority_queue< pair<ll,int> , vector<pair <ll,int> > ,greater<pair<ll,int> > > Q;
	Q.push({arr[st],st});
	while(!Q.empty()){
		ll curr = Q.top().second;
		Q.pop();
		for(auto x : City[curr]){
			ll a = x.first;
			ll b = x.second;
			if(arr[a] > arr[curr] + b){
				arr[a] = arr[curr] + b;
				Q.push({arr[a],a});
			}
		}
	}
}
main(){
	cin >> N >> M;
	int st,en;
	ll kilo;
	cin >> st >> en >> kilo;
	//vector< pair<int,int> > City[N];
	for(int i = 0 ; i < M ; i++){
		int a,b;
		ll c;
		cin >> a >> b >> c;
		City[a].push_back({b,c});
		City[b].push_back({a,c});
	}
	SP(st,qs);
	SP(en,qs1);
	int now = 1e9;
	ll mn = LLONG_MAX;
	ll mn1;
	for(int i = 0 ; i < N ; i++){
		if(qs[i] <= kilo && qs1[i] <= mn){
			if(mn > qs1[i]){
				mn = qs1[i];
				mn1 = qs[i];
				now = i;
			}
			if(mn == qs1[i] && now > i) now = i ;
		}
	}
	
	cout << now  << " "<< mn1 << " " << mn;
}


