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
d A[8][8] = {0};
bool visited[8][8] = {false};
main(){
	int M,N;
	cin >> M >> N;
	int cnt = 0;
	for(int i = 1 ; i <= M ; i++){
		for(int j = 1 ; j <= N ; j++){
			cin >> A[i][j];		
		}
	}
	d sum = 0;
	while(cnt++ < M*N){
		int x,y;
		d mn = 1e9;
		for(int i = 1 ; i <= M ; i++){
			for(int j = 1 ; j <= N ; j++){
				if(mn > A[i][j] && !visited[i][j]){
					mn = A[i][j];
					x = i;
					y = j;
				}	
			}
		}
		sum += mn;
		d c = mn*(d)0.1;
		for(int i = -1 ; i < 2 ; i++){
			for(int j = -1 ; j < 2 ; j++){
				if(i != 0 || j != 0){
					A[x + i][y + j] += c;
				}
			}
		}
		visited[x][y] = true;
	}
	printf("%.2lf",sum);
}

