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
vector<pair<int,int> > graph[10001];
int indegree[10001] = {0};
int D[10002] = {0};
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,F,T;
	cin >> N >> F >> T;
	D[N+1] = 1e9;
	priority_queue< pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > pq;
	for(int i = 1 ; i <= N ; i++){
		int a,b;
		cin >> a >> b;
		indegree[i] = b;
		D[a]++;
		if(b == 0){
			pq.push({a,i});
		}
		for(int i = 0 ; i < b ; i++){
			int k;
			cin >> k;
			graph[k].push_back({i,a});
		}
		
	}
	while(!pq.empty() && T--){
		int curr = pq.top().second;
		D[pq.top().first]--;
		cout << "ok" << "\n";
		pq.pop();
		for(auto x : graph[curr]){
			indegree[x.first]--;
			if(indegree[x.first] == 0) pq.push({x.second,x.first});
		}
		
	}
	bool chk = true;
	int ans;
	for(int i = 1 ; i <= F+1 ; i++){
		cout << D[i] << "\n";
		if(D[i] != 0){
			ans = i-1;
			//break;
		}
	}
	if(!ans) cout << -1;
	else cout << ans;
	return 0;


}

