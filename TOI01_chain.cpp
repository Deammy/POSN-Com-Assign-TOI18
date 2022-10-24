/*TASK:
LANG: C++
AUTHOR: Chayapat Kruthnim
CENTER: WU
FL539S
*/
#include<bits/stdc++.h>
#define ll long long int
#define d double
using namespace std;
main(){
	int N;
	int W;
	cin >> N >> W;
	string A[W];
	for(int i = 0 ; i < W ; i++){
		cin >> A[i];
	}
	for(int i = 1 ; i < W ; i++){
		int count = 0;
		for(int j = 0 ; j < N ; j++){
			if(A[i][j] != A[i-1][j]){
				count++;
				if(count > 2){
					cout << A[i-1];
					return 0;
				}
			}
		}
	}
	cout << A[W-1];
}
