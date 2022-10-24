#include<bits/stdc++.h>
#define ll long long int
#define d double
#define ull unsigned long long

using namespace std;
map<pair<int,int> ,pair<int,bool> > MAP; 
map<pair<int,int> ,bool > fuck; 
map<pair<int,int> ,int > suck; 
int N,T;
struct infect{
	int x,y,expire,life;
	bool operator <(const infect & a) const{
		return expire > a.expire;
	}
};
struct z{
	int x,y,l;
};
main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> T;
	int F,S,Q;
	cin >> F >> S >> Q;
	priority_queue<infect> Ipq;
	priority_queue<infect> Dpq;
	int dead = 0;
	for(int i = 0 ; i < N ; i++){
		int a,b,l,c;
		cin >> a >> b >> l >> c;
		MAP[{a,b}] = {l,true};
		fuck[{a,b}] = false;
		if(c == 1){
			if(l <= Q) {
				dead++;
				MAP[{a,b}] = {l,false};;
			}
			else{
				fuck[{a,b}] = true;
				Ipq.push({a,b,l - S,l});
				Dpq.push({a,b,l - Q,l});
			}
			
		}
	}
	vector<z> zombie;
	int cnt = 0;
	int dx[] = {0,1,0,-1};
	int dy[] = {1,0,-1,0};
	while(!Ipq.empty() &&Ipq.top().expire <= 0){
		auto curr = Ipq.top();
		zombie.push_back({curr.x,curr.y,curr.life});
		Ipq.pop();
	}
	for(int i = 1 ; i <= T ; i++){
		while(!Dpq.empty() && Dpq.top().expire <= i){
			dead++;
			MAP[{Dpq.top().x,Dpq.top().y}] = {MAP[{Dpq.top().x,Dpq.top().y}].first,false};
			Dpq.pop();
		}
		for(int j = cnt ; j < zombie.size() ; j++){
			
			zombie[j].l--;
			int haha = 0;
			for(int k = 0 ; k < 4 && MAP[{zombie[j].x , zombie[j].y }].second ; k++){
				if(MAP.count({zombie[j].x + dx[k] , zombie[j].y + dy[k]})){
					int X = zombie[j].x, Y = zombie[j].y;
					if(!suck.count({X + dx[k] , Y + dy[k]})) suck[{X + dx[k] , Y + dy[k] }] = F - zombie[j].l;
					else {
						suck[{zombie[j].x + dx[k] , zombie[j].y + dy[k] }] += F - zombie[j].l;
					}
					if(!fuck[{X + dx[k] , Y + dy[k]}] && MAP[{X + dx[k] , Y + dy[k]}].first <= suck[{zombie[j].x + dx[k] , zombie[j].y + dy[k] }] ){
						fuck[{X + dx[k] , Y + dy[k]}] = true;
						Ipq.push({X + dx[k] , Y + dy[k],      MAP[{X + dx[k] , Y + dy[k]}].first + i - S, MAP[{X + dx[k] , Y + dy[k]}].first + i});
						Dpq.push({X + dx[k] , Y + dy[k],      MAP[{X + dx[k] , Y + dy[k]}].first + i - Q, MAP[{X + dx[k] , Y + dy[k]}].first + i});
						haha++;
					}
				}
				else {
					haha += 1;
				}
			}
			if(haha == 4 && !MAP[{zombie[j].x , zombie[j].y }].second){
				swap(zombie[cnt],zombie[j]);
				cnt++;
			}
			
		}
		suck.clear();
		while(!Ipq.empty() &&Ipq.top().expire <= i){
			auto curr = Ipq.top();
			zombie.push_back({curr.x,curr.y,curr.life - i});
			Ipq.pop();
		}
		
		
	}
	int numb = 0;
	while(!Dpq.empty()){
		if(Dpq.top().expire > T){
			numb++;
		}
		Dpq.pop();
	}
	cout <<numb << "\n" << dead;
}

