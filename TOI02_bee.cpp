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
void Bee(ll *B1, ll *B2,ll *B3){
	int B2X,B3X;
	B2X = *B3;
	B3X = *B2;
	B2X += *B2;
	B2X += *B1;
	*B2 = B2X;
	*B3 = B3X;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int St,mx = 0;
	ll B1 = 1,B2 = 1, B3 = 0;
	ll memo[25][2] = {0};
	cin >> St;
	while(St != -1){
		if(mx > St){
			cout << memo[St][0] << " " << memo[St][1] + memo[St][0] + B1 << "\n";
			cin >> St;
			continue;
		}
		while(mx < St){
			mx++;
			Bee(&B1,&B2,&B3);
			memo[St][0] = B2;
			memo[St][1] = B3;
		}
		cout << B2 << " " << B1 + B2 + B3 << "\n";
		cin >> St;
	}
}
