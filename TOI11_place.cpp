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

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int E;
	cin >> N >> E;
	vector<pair <int,int> > graph[N+1];
	for(int i = 0 ; i < E ; i++){
		int a,b,c;
		cin >> a >> b >> c;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}
	int st = 1;
	vector<int> key(N+1,INT_MIN);
	vector<bool> chk(N+1,false);
	ll sum = 0;
	key[st] = 0;
	priority_queue < pair<int,int> , vector <pair <int,int> > , less<pair<int,int> > > pq;
	pq.push({key[st],st});
	while(!pq.empty()){
		int curr = pq.top().second;
		if(!chk[curr]){
			//cout << "ok\n";
			sum += key[curr];
		}
		//cout << curr << " " << pq.top().first << "\n";
		chk[curr] = true;
		pq.pop();
		for(auto x : graph[curr]){
			int a = x.first;
			int b = x.second;
			if(key[a] < b && !chk[a] ){
				key[a] = b;
				pq.push({key[a],a});
			}
		}
	}
	cout << sum - N + 1;

}

