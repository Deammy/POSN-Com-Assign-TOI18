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

main(){
	ll sum0P = 0,sum50P = 0;
	int N,W,H;
	cin >> W >> H >> N;
	int Filter[W] = {0};
	for(int i = 0 ; i < N ; i++){
		int S,E;
		cin >> S >> E;
		for(int j = S ; j <= S+E - 1 ; j++){
			if(j < W){
				Filter[j]++;
			}
		}
	}
	for(int i = 0 ; i < W ; i++){
		if(Filter[i] == 0){
			sum0P += H;
		}
		else if(Filter[i] == 1){
			sum50P += H;
		}
	}
	cout << sum0P << " " << sum50P;
}

