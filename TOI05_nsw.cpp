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
string A;
void Spin(int C1[],int C2[],int C3[]){
	for(int i = 0 ; i < 9 ; i++){
		C1[i] = (C1[i] +  A[0] - '0' ) % 9 ;
		C2[i] = (C2[i] + 8) % 9 ;
		C3[i] = (C3[i] + A[2] - '0' ) % 9 ;
	}
}

main(){
	string Inp;
	cin >> A >> Inp;
	int Ans[Inp.length()] = {0};
	int count = 0,k,l;
	int C1[9] = {0},C2[9] = {0},C3[9] = {0};
	for(int i = 0 ; i < 9 ; i++){
		C1[i] += (i + A[0] - '0' - 1)%9 ;
		C2[i] += (i + A[1] - '0' - 1)%9 ;
		C3[i] += (i + A[2] - '0' - 1)%9 ;
	}
	while(count < Inp.length()){
		Ans[count] = C3[ C2[ C1[ Inp[count] - '1']  ] ] + 1;
		count++;
		Spin(C1,C2,C3);
	}
	for(int i = 0 ; i < count ; i++){
		cout << Ans[i];
	}
}

