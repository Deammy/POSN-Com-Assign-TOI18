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
const int n = 5e4 + 1;
bool A[110][n] = {false};

main(){
	int mx = 0;
	int N,a,b,c;
	cin >> N;
	while(N-- > 0){
		cin >> a >> b >> c;
		for(int j = b - 1 ; j < b + c - 1;j++){
			A[j][a-1] = true;
		}
		mx = max(mx,a);
	}
	for(int i = 0 ; i < mx ; i++){
		for(int j = 0 ; j < 70 ; j++){
			if(A[j][i]) cout << "x";
			else cout << "o";
		}
		cout << "\n";
	}
}

