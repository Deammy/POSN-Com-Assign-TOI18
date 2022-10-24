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
bool cmp1(int a,int b){
	return a > b;
}

main(){
	ll N,sum = 0;
	cin >> N;
	int A[N],B[N],C[N];
	for(int i = 0 ; i < N ; i++){
		cin >> A[i];
	}
	for(int i = 0 ; i < N ; i++){
		cin >> B[i];
	}
	sort(A,A+N);
	sort(B,B+N,cmp1);
	for(int i = 0 ; i < N ; i++){
		C[i] = A[i] + B[i];
	}
	sort(C,C+N);
	sum = C[N-1] - C[0];
	cout << sum;

}

