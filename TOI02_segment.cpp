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
string A[3];
string B[3];
ll PicToIntA(int j,ll k){
	if(A[0][j-1] == '_' && A[1][j-2] == '|' && A[1][j-1] == '_' && A[1][j] == '|' && A[2][j-2] == '|' && A[2][j-1] == '_' && A[2][j] == '|'){
		return 8*k;
	}
	else if(A[0][j-1] == '_' && A[1][j-2] == '|' && A[1][j-1] == '_' && A[1][j] == '|'  && A[2][j-1] == '_' && A[2][j] == '|'){
		return 9*k;
	}
	else if(A[0][j-1] == '_' && A[1][j-2] == '|' && A[1][j-1] == '_' && A[2][j-2] == '|' && A[2][j-1] == '_' && A[2][j] == '|'){
		return 6*k;
	}
	else if(A[0][j-1] == '_' && A[1][j-2] == '|' && A[1][j] == '|' && A[2][j-2] == '|' && A[2][j-1] == '_' && A[2][j] == '|'){
		return 0;
	}
	else if(A[0][j-1] == '_' && A[1][j-1] == '_' && A[1][j] == '|' && A[2][j-2] == '|' && A[2][j-1] == '_'){
		return 2*k;
	}
	else if(A[0][j-1] == '_' && A[1][j-2] == '|' && A[1][j-1] == '_' && A[2][j-1] == '_' && A[2][j] == '|'){
		return 5*k;
	}
	else if(A[0][j-1] == '_' && A[1][j-1] == '_' && A[1][j] == '|'  && A[2][j-1] == '_' && A[2][j] == '|'){
		return 3*k;
	}
	else if(A[1][j-2] == '|' && A[1][j-1] == '_' && A[1][j] == '|' && A[2][j] == '|'){
		return 4*k;
	}
	else if(A[0][j-1] == '_'  && A[1][j] == '|'  && A[2][j] == '|'){
		return 7*k;
	}
	else if(A[1][j] == '|'  && A[2][j] == '|'){
		return k;
	}
}
ll PicToIntB(int j,ll k){
	if(B[0][j-1] == '_' && B[1][j-2] == '|' && B[1][j-1] == '_' && B[1][j] == '|' && B[2][j-2] == '|' && B[2][j-1] == '_' && B[2][j] == '|'){
		return 8*k;
	}
	else if(B[0][j-1] == '_' && B[1][j-2] == '|' && B[1][j-1] == '_' && B[1][j] == '|'  && B[2][j-1] == '_' && B[2][j] == '|'){
		return 9*k;
	}
	else if(B[0][j-1] == '_' && B[1][j-2] == '|' && B[1][j-1] == '_' && B[2][j-2] == '|' && B[2][j-1] == '_' && B[2][j] == '|'){
		return 6*k;
	}
	else if(B[0][j-1] == '_' && B[1][j-2] == '|' && B[1][j] == '|' && B[2][j-2] == '|' && B[2][j-1] == '_' && B[2][j] == '|'){
		return 0;
	}
	else if(B[0][j-1] == '_' && B[1][j-1] == '_' && B[1][j] == '|' && B[2][j-2] == '|' && B[2][j-1] == '_'){
		return 2*k;
	}
	else if(B[0][j-1] == '_' && B[1][j-2] == '|' && B[1][j-1] == '_' && B[2][j-1] == '_' && B[2][j] == '|'){
		return 5*k;
	}
	else if(B[0][j-1] == '_' && B[1][j-1] == '_' && B[1][j] == '|'  && B[2][j-1] == '_' && B[2][j] == '|'){
		return 3*k;
	}
	else if(B[1][j-2] == '|' && B[1][j-1] == '_' && B[1][j] == '|' && B[2][j] == '|'){
		return 4*k;
	}
	else if(B[0][j-1] == '_'  && B[1][j] == '|'  && B[2][j] == '|'){
		return 7*k;
	}
	else if(B[1][j] == '|'  && B[2][j] == '|'){
		return k;
	}
}

main(){
	ll sum = 0;
	int a,b;
	cin >> a >> b;
	for(int i = 0 ; i < 3 ; i++){
		getline(cin,A[i]);
	}
	cout << "OKK";
	for(int i = 0 ; i < 3 ; i++){
		getline(cin,B[i]);
	}
	for(int j = 0 ; j < a ; j++){
		sum += PicToIntA(j*4 + 2,(ll)pow(10,a-1-j));
	}
	for(int j = 0 ; j < b ; j++){
		sum += PicToIntB(j*4 + 2,(ll)pow(10,b-1-j));
	}
	cout << sum;
}

