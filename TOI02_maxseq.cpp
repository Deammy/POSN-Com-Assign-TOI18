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
	ll mx = 0;
	ll curr;
	int N,count = 0,mxc = 0,end;
	cin >> N;
	int A[N];
	for(int i = 0 ; i < N ; i++){
		cin >> A[i];
		if(i == 0){
			curr = A[i]; 
		}
		else if(curr + A[i] > A[i]){
			curr += A[i];
			count++;
		}
		else{
			curr = A[i];
			count = 0;
		}
		if(mx < curr){
			mx = curr;
			mxc = count;
			end = i;
		}
	}
	if(mx == 0){
		cout << "Empty sequence";
		return 0;
	}
	for(int i = end - mxc ; i <= end ; i++){
		cout << A[i] << " ";
	}
	cout << "\n" << mx;
}

