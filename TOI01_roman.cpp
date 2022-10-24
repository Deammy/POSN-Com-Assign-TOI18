/*TASK: Day8_01_Roman
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
	int N;
	int C[5] = {0};
	cin >> N;
	for(int i = 1 ; i <= N ; i++){
		int k = i;
		while(k >= 100){
			C[4]++;
			k = k - 100;
		}
		while(k >= 90){
			C[4]++;
			C[2]++;
			k = k - 90;
		}
		while(k >= 50){
			C[3]++;
			k = k - 50;
		}
		while(k >= 40){
			C[3]++;
			C[2]++;
			k = k - 40;
		}
		while(k >= 10){
			C[2]++;
			k = k - 10;
		}
		while(k >= 9){
			C[2]++;
			C[0]++;
			k = k - 9;
		}
		while(k >= 5){
			C[1]++;
			k = k - 5;
		}
		while(k >= 4){
			C[1]++;
			C[0]++;
			k = k - 4;
		}
		C[0] += k;
	}
	for(int i = 0 ; i < 5 ; i++){
		cout << C[i] << " ";
	}
}
