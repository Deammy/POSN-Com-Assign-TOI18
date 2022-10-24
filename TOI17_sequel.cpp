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
	int a = 50;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M,N;
	cin >> M >> N;
	int k;
	ll mem[M+1] = {0};
	ll qs[M+1][a+1] = {0};
	for(int i = 1 ; i <= M ; i++){
		cin >> mem[i];
		for(int j = 1 ; j <= a ; j++){
			qs[i][j] = qs[max(i-j,0)][j] + mem[i];
		}
	}
	while(N--){
		ll sum = 0;
		int l , m , r;
		cin >> l >> m >> r;
		r = (r-l)/m;
		r = r*m + l;
		if(m > a) {
			
			for(int i = l ; i <= r ; i+= m) {
				sum += mem[i];
			}
			cout << sum << " ";
			continue;	
		}
		cout << qs[r][m] - qs[max(l-m,0)][m] << " ";
		
	}


}

