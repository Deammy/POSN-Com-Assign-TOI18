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
/*bool Check(int k,int size){
	int count = 0;
	int posx = 0,posy = 0;
	for(int i = -1 ; i <= 1 ; i++){
		for(int j = -1 ; j <= 1; j++){
			if(A[i][j] == k && i == 0 && j == 0){
				posx += i;
				posy += j;
				count++;
				if(count == 2){
					if(abs(posx) > 0 && abs(posy) > 0){
						return true;
					}
					else{
						return false;
					}
				}
			}
		}
	}
}*/

main(){
	int N,sum = 0;
	cin >> N;
	int A[N][N];
	int a[9] = {0};
	int pos[9][2][N] = {0};
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin >> A[i][j];
			pos[A[i][j]][0][a[A[i][j]]] = i;
			pos[A[i][j]][1][a[A[i][j]]++] = j;
		}
	}
	for(int i = 1 ; i <= 9 ; i++){
		int posx = 0;
		int posy = 0;
		if(a[i] == 3){
			while(a[i]-- > 0){
				if(a[i] == 2){
					posx -= 2*pos[i][0][a[i]];
					posy -= 2*pos[i][1][a[i]];
				}
				else{
					posx += pos[i][0][a[i]];
					posx += pos[i][1][a[i]];
				}
			}
			if(abs(posx) && abs(posy)){
				sum++;
			}
		}
	}
	cout << sum;


}

