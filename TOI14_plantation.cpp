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
pair<int,int> A[100001];
ll divide(int l , int r,int n){
	ios::sync_with_stdio(0);
	cin.tie(0);
	if(l >= r) return 1e9;
	int mid = (l+r)/2;
	int dx = divide(l,mid,n);
	int dy = divide(mid+1,r,n);
	ll mn = min(dx,dy);
	int l1 = max(0,mid-50);
	int r1 = min(n-1,mid+50);
	for(int i = l1 ; i <= r1 ; i++){
		if(i != mid){
			ll d1 = abs(A[i].first - A[mid].first);
			ll d2 = abs(A[i].second - A[mid].second);
			mn = min(mn,d1*d1 + d2*d2);
		}
		
	}
	return mn;
	
}
main(){
	int T;
	cin >> T;
	while(T--){
		int N,R,D;
		cin >> N >> R >> D;
		for(int i = 0 ; i < N ; i++){
			cin >> A[i].first >> A[i].second;
		}
		sort(A,A+N,[&](pair <int,int> a , pair<int,int> b){
			if(a.first == b.first) return a.second < b.second;
			return a.first < b.first;
		});
		ll ans = divide(0,N-1,N);
		if(ans >= (2*R + D)*(2*R + D) ) cout << "Y\n";
		else cout << "N\n";
	}
	


}

