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
bool visited[1000001];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<ll> cannon;
	ll N,M,K,L;
	cin >> N >> M >> K >> L;
	for(int i = 0 ; i < N ; i++){
		int k;
		cin >> k;
		cannon.push_back(k);
	}
	sort(cannon.begin(),cannon.end());
	while(K--){
		int cnt = 0;
		memset(visited,false,sizeof(visited));
		for(int i = 0 ; i < M ; i++){
			ll k;
			cin >> k;
			auto low1 = lower_bound(cannon.begin(),cannon.end(),k-L);
			for(int j = low1 - cannon.begin() ; j < cannon.size() ; j++){
				if(cannon[j] > k + L) break;
				if(!visited[j]){
					visited[j] = true;
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}

}

