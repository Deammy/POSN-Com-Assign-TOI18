/*TASK:
LANG: C++
AUTHOR: Chayapat Kruthnim
CENTER: WU
*/
//FL539S
#include<bits/stdc++.h>
#define ll long long int
#define d double
#define ull unsigned long long

using namespace std;
struct pos{
	int first;
	ll second;
	int third;
};
vector<pos> graph[3001];
bool cmp(pair<int,int> a , pair<int,int> b){
	return a.second < b.second;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,E;
	cin >> N >> E;
	for(int i = 0 ; i < E ; i++){
		int a,b,c,r;
		cin >> a >> b >> c >> r;
		graph[a].push_back({b,c,r});
		graph[b].push_back({a,c,r});
	}
	int p;
	cin >> p;
	vector<pair<ll,int> > cost;
	for(int i = 0 ; i < p ; i++){
		int a,b;
		cin >> a >> b;
		cost.push_back({a,b});
	}
	sort(cost.begin(),cost.end(),cmp);
	int st = 0;
	vector<ll> key(N,1e9);
	vector<bool> visited(N,false);
	key[st] = 0;
	priority_queue< pair<ll,int> , vector<pair<ll,int> > , greater<pair<ll,int> > > pq;
	pq.push({key[st],st});
	ull sum = 0;
	while(!pq.empty()){
		int curr = pq.top().second;
		pq.pop();
		if(!visited[curr]) sum += key[curr];
		visited[curr] = true;
		for(auto x : graph[curr]){
			int a = x.first;
			ll b = x.second;
			int c = x.third;
			if(c == 1 && !visited[a]){
				key[a] = 0;
				pq.push({key[a],a});
				continue;
			}
			int o;
			for(auto y : cost){
				if(b <= y.first) {
					o = y.second;
					break ;
				}
			}
			if(key[a] > o && !visited[a]){
				key[a] = o;
				pq.push({key[a],a});
			}
		}
	}
	cout << sum;
}

