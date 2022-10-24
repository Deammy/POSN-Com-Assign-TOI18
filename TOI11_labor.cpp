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
unsigned long long N,Q;
unsigned long long A[1000001];
unsigned long long Find(unsigned long long l , unsigned long long r){
	unsigned long long ans = 0;
	unsigned long long mid = (l+r)/2;
	//cout << "ok\n";
	while(l < r){
		ans = 0;
		for(int i = 0 ; i < N ; i++){
			ans += mid/A[i];
			if(ans > Q) break;
		}
		//cout << ans << "\n";
		if(ans >= Q) r = mid;
		if(ans < Q) l = mid+1;
		mid = (l+r)/2;
		
	}
	return l;
}
main(){
	cin >> N >> Q;
	unsigned long long mx = 0;
	for(int i = 0 ; i < N ; i++){
		cin >> A[i];
		mx = max(mx,A[i]);
	}
	//cout << mx*Q << "\n";
	cout << Find(0,mx*Q);
	

}

