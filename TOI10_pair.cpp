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
char game[1000];
int mem[1000][1000] = {0};

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	
	for(int i = 0 ; i < N ; i++){
		cin >> game[i];
	}
	for(int j = 0 ; j < N ; j++){
		for(int i = j-1 ; i >= 0 ; i--){
			if(game[i] == game[j]) mem[i][j] = mem[i+1][j-1]+1;
			for(int k = i ; k < j ; k++){
				mem[i][j] = max(mem[i][j],mem[i][k] + mem[k+1][j]);
			}
		}
	}
	cout << mem[0][N-1];


}

