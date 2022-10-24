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
int A[2001];
int B[2001];
main(){
	int N;
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		cin >> A[i];
	}
	for(int i = 0 ; i < N ; i++){
		cin >> B[i];
	}
	sort(A,A+N);
	sort(B,B+N);
	ll sum = 0;
	for(int i = 0 ; i < N ; i++){
		sum += abs(A[i] - B[i]);
	}
	cout << sum;
}

