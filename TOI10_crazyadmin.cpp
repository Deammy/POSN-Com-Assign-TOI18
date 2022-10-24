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
int A[1001];
int N,Q;
int find(int l,int r){
	int mid = (l+r)/2;
	while(l < r){
		int ans = 0;
		int cnt = 1;
		for(int i = 0 ; i < Q ; i++){
			if(ans + A[i] > mid){
				if(A[i] > mid){
					cnt = 1e9;
					break;
				}
				ans = A[i];
				cnt++;
			}
			else ans += A[i];
		}
		if(cnt > N) l = mid+1;
		if(cnt <= N) r = mid;
		mid = (l+r)/2;
	}
	return r;
}

main(){
	cin >> N >> Q;
	int sum = 0;
	if(N > Q) N = Q;
	for(int i = 0 ;i < Q ; i++){
		cin >> A[i];
	}
	cout << find(0,150000);
	
/*
4 3 1000 1500 1200
3 4 
800 
400 
400 
700 */
}

