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
	int N,M;
	cin >> N >> M;
	char Row[N][M];
	int Column[M];
	for(int i = 0 ; i < N ; i++){
		cin >> Row[i];
	}
	for(int i = 0 ; i < M ; i++){
		int Block;
		cin >> Block;
		for(int j = 0 ; j < N ; j++){
			int h = j;
			if(Row[h][i] == 'O'){
				while(Block > 0 && h - 1 >= 0){
					Row[h - 1][i] = '#';
					h--;
					Block--;
				}
				break;
			}
			else if(h == N-1){
				while(Block > 0 && h >= 0){
					Row[h][i] = '#';
					h--;
					Block--;
				}
				break;
			}
		}
	}
	char *p;
	p = Row[0];
	for(int i = 0 ; i < N*M ; i++){
		cout << *(p+i);
		if(i % M == M-1){
			cout << "\n";
		}
	}
}
