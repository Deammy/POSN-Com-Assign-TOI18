#include<bits/stdc++.h>
#define ll long long int
#define d double
#define ull unsigned long long
using namespace std;
struct Warp{
	int W1,W2,O1,O2;
};
struct order{
	int w,x,y,p;
	bool operator <(const order & a) const{
		if(w == a.w) return p < a.p;
		return w > a.w;
	}
};
int dist[20002][20];
int mndist[20002];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M,N,K,P;
	cin >> M >> N;
	cin >> K >> P;
	vector<Warp> w;
	for(int i = 0 ; i < K ; i++){
		int a1,b1,a2,b2;
		cin >> a1 >>b1 >> a2 >> b2;
		w.push_back({a1,b1,a2,b2});
	}
	w.push_back({M,N,M,N});
	priority_queue< order > pq;
	pq.push({0,1,1,P});
	for(int i = 0 ; i < w.size() ; i++){
		for(int j = 0 ; j <= P ; j++){
			dist[i][j] = INT_MAX;
		}
		mndist[i] = INT_MAX;
	}
	while(!pq.empty()){
		auto curr= pq.top();
		pq.pop();
		if(curr.x == M && curr.y == N){
			cout << curr.w << " " << P - curr.p;
			return 0;
		}
		for(int i = 0 ; i < w.size() ; i++){
			int X = abs(curr.x - w[i].W1);
			int Y = abs(curr.y - w[i].W2);
			if(w[i].W1 != M || w[i].W2 != N){
				if(curr.p > 0){
					bool chk = true;
					for(int j = curr.p ; j <= P ; j++){
						if(dist[i][j] <= curr.w + X + Y){
							chk = false;
							break;
						}
					}
					if(chk){
						dist[i][curr.p] = curr.w+X+Y;
						pq.push({X+Y + curr.w,w[i].O1,w[i].O2,curr.p-1});
					}
				}
			}
			else if(dist[i][curr.p] > curr.w + X + Y){
				dist[i][curr.p] = curr.w + X + Y;
				pq.push({X+Y + curr.w,w[i].O1,w[i].O2,curr.p});
			}
		}
	}
}
