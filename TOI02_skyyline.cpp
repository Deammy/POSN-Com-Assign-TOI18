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
	int mx = 0,mn = 255;
	int Tower[255] = {0};
	int N;
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		int S,H,E;
		cin >> S >> H >> E;
		mx = max(mx,E);
		mn = min(mn,S);
		for(int i = S ; i < E ; i++){
			if(H > Tower[i]){
				Tower[i] = H;
			}
		}
	}
	for(int i = mn ; i <= mx ; i++){
		if(Tower[i] != Tower[i-1] || i == 0){
			cout << i << " " << Tower[i] << " ";
		}
	}


}

