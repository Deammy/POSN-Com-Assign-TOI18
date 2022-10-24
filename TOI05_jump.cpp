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
	int N,K,mx = 0,sum = 0;
	cin >> N >> K;
	pair<int,int> A[N];
	for(int i = 0 ; i < N ; i++){
		cin >> A[i].first;
		A[i].second = i;
	}
	for(int i = 0 ; i < N ; i++){
		for(int j = i ; j < N-1 ; j++){
			if(A[j+1].first > A[i].first + K){
				mx = max(mx,A[j].second - A[i].second);
				break;
			}
		}
	}
	cout << mx;

}

