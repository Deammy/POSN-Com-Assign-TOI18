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
int A[6000001] = {0};
int l[6000001];
struct WTF{
	ll a;
	int b;
};
main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n,w;
	ll mx = 0 , l = 0;
	cin >> n >> w;
	for(int i = 1 ; i <= n ; i++){
		int k;
		cin >> k;
		A[i] = A[i-1] + k;
	}
	deque<pair<ll,int> > Q;
	for(int i = 1 ; i <= n ; i++){
		while(!Q.empty() && Q.back().second >= A[i]) Q.pop_back();
		if(!Q.empty() && Q.front().first < i - w) Q.pop_front();
		Q.push_back({i,A[i]});
		if(Q.back().second - Q.front().second >= mx){
			if(mx == Q.back().second - Q.front().second && l > Q.back().first - Q.front().first) l = Q.back().first - Q.front().first;
			else{
				mx = Q.back().second - Q.front().second;
				l = Q.back().first - Q.front().first;
			}
		}
	}
	cout << mx << "\n" << l;
}
