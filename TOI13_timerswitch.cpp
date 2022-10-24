#include<bits/stdc++.h>
#define ll long long int
#define d double
#define ull unsigned long long

using namespace std;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	
	string S;
	cin >> N >> S;
	
	for(int i = 1 ; i <= N ; i++){
		if(N % i == 0){
			bool chk = true;
			for(int j = 0 ; j < N - i ; j++){
				if(S[j] != S[j + i]){
					chk = false;
					break;
				}
			}
			if(chk){
				cout << i ;
				return 0;
			}
		}
	}

}

