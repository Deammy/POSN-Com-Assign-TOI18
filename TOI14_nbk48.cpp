#include<bits/stdc++.h>
#define ll long long int
#define d double
#define ull unsigned long long

using namespace std;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,Q;
	cin >> N >> Q;
	ll discovery[N+1] = {0};
	vector<pair<ll,int> > customer;
	for(int i = 1 ; i <= N ; i++){
		int a;
		cin >> a;
		discovery[i] = discovery[i-1] + a;
		//cout << discovery[i] << " ";
	}
	for(int i = 0 ; i < Q ; i++){
		ll q;
		cin >> q;
		customer.push_back({q,i});
	}
	sort(customer.begin(),customer.end(),[&](pair<int,int> a , pair<int,int> b){
		return a.first > b.first;});
	int cnt = 0;
	bool chk = false;
	for(int i = N ; i >= 0 ; i--){
		while(discovery[i] <= customer[cnt].first){
			customer[cnt++].first = i;
			if(cnt == Q){
				chk = true;
				break;
			}
		}
		if(chk) break;
	}
	sort(customer.begin(),customer.end(),[&](pair<int,int> a , pair<int,int> b){
		return a.second < b.second;});
	for(int i = 0 ; i < Q ; i++){
		cout << customer[i].first << "\n";
	}
}

