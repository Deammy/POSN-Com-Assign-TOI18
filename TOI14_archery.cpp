/*TASK:
LANG: C++
AUTHOR: Chayapat Kruthnim
CENTER: WU
*/
//FL539S
#include<bits/stdc++.h>
#define ll long long int
#define d double
#define ull unsigned long long
using namespace std;
pair <ll,ll> A[500001];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	ll mn = 1e9;
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		ll k;
		cin >> k;
		A[i].second = k;
		mn = min(mn,k);
	}
	ll numb = 0;
	for(int i = 0 ; i < N ; i++){
		cin >> A[i].first;
	}
	sort(A,A+N);
	ll sum = 0;
	for(int i = 1 ; i < N ; i++){
		sum += A[i].first - A[0].first;
	}
	ll a = sum;
	ll b = A[0].first;
	for(int i = 1 ; i < N ; i++){
		if(A[i].first > mn) break;
		sum -= (A[i].first - A[i-1].first) * (N-1);
		sum += A[i-1].first + (A[i-1].second - A[i].first);
		if(a > sum) a = sum,b = A[i].first;
	}
	cout << b << " " << a;
}
