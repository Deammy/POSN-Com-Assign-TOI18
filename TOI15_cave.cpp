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
int N,P,U,E;
struct cave{
	ll node,w,lv;
	bool operator <(const cave & a) const{
		if(a.w == w) return lv > a.lv;
		return w > a.w;
	}
};
vector<pair<int,ll> > graph[10000];
vector<pair<int,ll> > result[10000];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> P >> U >> E;
	for(int i = 0 ; i < E ; i++){
		int a,b,c;
		cin >> a >> b >> c;
		graph[a].push_back({b,c});
	}
	priority_queue<cave> pq;
	pq.push({P,0,-1});
	while(!pq.empty()){
		cave curr = pq.top();
		pq.pop();
		for(auto x : graph[curr.node]){
			bool chk = true;
			for(vector<pair<int,ll> > :: iterator y = result[x.first].begin() ; y != result[x.first].end() ; y++){
				if(curr.lv + 1 == (*y).first && curr.w + x.second < (*y).second) {
					result[x.first][y - result[x.first].begin()] = {curr.lv + 1,curr.w + x.second};
					pq.push({x.first,curr.w + x.second,curr.lv + 1});
					chk = false;
					break;	
				}
				else if(curr.w + x.second >= (*y).second && curr.lv + 1 >= (*y).first){
					chk = false;
					break;
				}
			}
			if(chk) {
				result[x.first].push_back({curr.lv + 1,curr.w + x.second});
				pq.push({x.first,curr.w + x.second,curr.lv + 1});
			}
		}
	}
	int L ;
	cin >> L;
	for(int i = 0 ; i < L ; i++){
		int a;
		cin >> a;
		ll mn = LLONG_MAX;
		for(auto x : result[U]){
			mn = min(x.second + (x.first)*a,mn);
		}
		cout << mn << " ";
	}
	
}

