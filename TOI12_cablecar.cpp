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

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int N,E;
	cin >> N >> E;
	vector<pair<int,int> > graph[N+1];
	bool visited[N+1] = {false};
	for(int i = 0 ; i < E ; i++){
		int a,b,c;
		cin >> a >> b >> c;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}
	int st,en,p;
	cin >> st >> en >> p;
	priority_queue< pair<int,int> , vector<pair<int,int> > , less<pair <int,int> > > pq;
	pq.push({1e9,st});
	
	int curr;
	int mn = INT_MAX;
	while(!pq.empty()){
		if(curr == en) break;
		curr = pq.top().second;
		mn = min(pq.top().first,mn);
		pq.pop();
		visited[curr] = true;
		for(auto x : graph[curr]){
			if(!visited[x.first]) pq.push({x.second,x.first});
		}
		
	}
	cout << ceil((d)p / (d)(mn-1));

}

