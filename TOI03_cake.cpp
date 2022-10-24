/*TASK: Day8_07_Cake
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
	int sum = 0;
	int N;
	cin >> N;
	int Take = 0;
	int Cake[5] = {0};
	for(int i = 0 ; i < 5*N ; i++){
		int k;
		cin >> k;
		if(k != 0){
			sum += k;
			Cake[i % 5] += k;
		}
	};
	Take += Cake[0];
	sum -= Cake[0];
	while(sum > 0){
		int Pond = 8;
		while(Cake[1] > 0 && Pond >= 6){
			Cake[1]--;
			sum--;
			Pond -= 6;
		}
		while(Cake[2] > 0 && Pond >= 4){
			Cake[2]--;
			sum--;
			Pond -= 4;
		}
		while(Cake[3] > 0 && Pond >= 2){
			Cake[3]--;
			sum--;
			Pond -= 2;
		}
		while(Cake[4] > 0 && Pond >= 1){
			Cake[4]--;
			sum--;
			Pond -= 1;
		}
		Take++;
	}
	cout << Take;
}
