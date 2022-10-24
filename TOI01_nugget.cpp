/*TASK: Day8_03_Nugget
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
	bool Check = true;
	int N;
	cin >> N;
	int A[N];
	/*if(((N % 20) % 3 != 0 || N % 20 == 3) && (N % 3 != 0 || N == 3)){
		cout << "no";
		return 0;
	}*/
	for(int i = 1 ; i <= N ; i++){
		int j = i;
		while(j >= 0){
			if(j % 3 == 0 && j != 3){
				Check = false;
				cout << i << "\n";
				break;
			}
			j -= 20;
		}
	}
	if(Check){
		cout << "no";
	}


}
