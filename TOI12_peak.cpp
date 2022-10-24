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
bool cmp(int a , int b){
	return a > b;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int K;
	cin >> N >> K;
	int A[N+1] = {0};
	cin >> A[1];
	vector< int > result;
	priority_queue< int , vector<int> , less <int> > pq;
	for(int i = 2 ; i <= N ; i++){
		cin >> A[i];
		if(A[i] < A[i-1] && A[i-1] > A[i-2]) pq.push(A[i-1]);
	}
	if(A[N] > A[N-1]) pq.push(A[N]);
	bool chk = false;
	while(!pq.empty()){
		if(result.empty()){
			result.push_back(pq.top());
			chk = true;
		} 
		else if(result[ result.size() - 1 ] != pq.top()){
			result.push_back(pq.top());
		}
		pq.pop();
		if(result.size() == K) break;
	}
	if(result.size() == K) sort(result.begin(),result.end(),cmp);
	else sort(result.begin(),result.end());
	if(chk){
		for(int i = 0 ; i < result.size() ; i++){
			cout << result[i] << "\n";
		}
	}
	else cout << -1;
	
}

