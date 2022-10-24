#include<bits/stdc++.h>
#define ll long long int
#define d double
#define ull unsigned long long

using namespace std;
struct truck{
	int w,f,node,pro;
	bool operator <(const truck & a) const{
		if(w == a.w) {
			if(w == a.w) return pro > a.pro;
			return w > a.w;	
		}
		return w > a.w;
	}
};
int dist[1001][1001][2];
main(){
	int N;
	cin >> N;
	int city[N+1];
	vector<pair<int,int> > graph[N+1];
	for(int i = 1 ; i <= N ; i++){
		cin >> city[i];
	}
	int S,D,F;
	cin >> S >> D >> F;
	int M;
	cin >> M;
	for(int i = 0 ; i <= F ; i++){
		for(int j = 1 ; j <= N ; j++){
			dist[j][i][0] = INT_MAX;
			dist[j][i][1] = INT_MAX;
		}
		
	}
	for(int i = 0 ; i < M ; i++){
		int a,b,c;
		cin >> a >> b >> c;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}
	priority_queue<truck> pq;
	pq.push({0,0,S,1});
	while(!pq.empty()){
		auto curr = pq.top();
		pq.pop();
		if(curr.node == D && curr.f == F){
			cout << curr.w;
			return 0;
		}
		if(curr.f < F && dist[curr.node][curr.f+1][curr.pro] > curr.w + city[curr.node]){
			dist[curr.node][curr.f+1][curr.pro] = curr.w + city[curr.node];
			pq.push({curr.w + city[curr.node],curr.f + 1,curr.node,curr.pro});
		}
		if(curr.pro == 1 && dist[curr.node][F][0] > curr.w){
			dist[curr.node][F][0] = curr.w;
			pq.push({curr.w,F,curr.node,0});
		}
		for(auto x : graph[curr.node]){
			if(curr.f >= x.second && dist[x.first][curr.f - x.second][curr.pro] > curr.w){
				dist[x.first][curr.f - x.second][curr.pro] = curr.w;
				pq.push({curr.w,curr.f - x.second,x.first,curr.pro});
			}
		}
	}
	

}

