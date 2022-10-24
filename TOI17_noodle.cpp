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
	ll N,M,K;
	cin >> N >> M >> K;
	ll arr[N];
	ll r = 0;
	for(int i = 0 ; i < N ; i++){
		cin >> arr[i];
		r += arr[i];
	}
	ll sum = 0;
	ll cnt = 0;
	ll l = 0;
	while(l < r){
		ll mid = (l + r) / 2;
		sum = 0;
		cnt = 0;
		priority_queue< ll,vector<ll> , greater<ll> > pq;
		for(int i = 0 ; i < N ; i++){
			if(pq.size() < K){
				sum += arr[i];
				pq.push(arr[i]);
			}
			else if(pq.top() < arr[i]){
				sum -= pq.top();
				sum += arr[i];
				pq.pop();
				pq.push(arr[i]);
			}
			if(sum >= mid && pq.size() == K) {
				cnt++;
				sum = 0;
				if(cnt == M) break;
				while(!pq.empty()) {
					pq.pop();
				}
			}
		}
		while(!pq.empty()) {
			pq.pop();
		}
		//cout << r << " k\n";
		if(cnt < M) r = mid;
		else l = mid+1;
	}
	//cout << sum << "\n";
	cout << l-1;
	


}

