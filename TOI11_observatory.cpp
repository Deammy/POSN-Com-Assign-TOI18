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
int NonA[2002][2002] = {0};
int NonB[2002][2002] = {0};
int TriangleA[2002][2002] = {0};
int TriangleB[2002][2002] = {0};
int A[2002][2002] = {0};
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M,N,k;
	cin >> M >> N >> k;
	ll mx = LLONG_MIN;
	for(int i = 1 ; i <= M ; i++){
		for(int j = 1 ; j <= N ; j++){
			cin >> A[i][j];
		}
	}
	for(int i = 1 ; i <= M ; i++){
		for(int j = 1 ; j <= N ; j++){
			int h = N+1-j;
			NonA[i][j] = NonA[i][j-1] + A[i][j]+NonA[i-1][j] - NonA[i-1][j-1];
			NonB[i][h] = NonB[i][h+1] + A[i][h] + NonB[i-1][h] - NonB[i-1][h+1];
			TriangleA[i][j] = NonA[i][j] - NonA[i-1][j] + TriangleA[i-1][j-1];
			TriangleB[i][h] = NonB[i][h] - NonB[i-1][h] + TriangleB[i-1][h+1];
			if(i >= k && j >= k){
				ll ans = max(TriangleA[i][j] - TriangleA[i-k][j-k] - NonA[i][j-k] + NonA[i-k][j-k], TriangleB[i][h] - TriangleB[i-k][h+k] - NonB[i][h+k] + NonB[i-k][h+k]);
				mx = max(ans,mx);
			}
		}
	}
	cout << mx;
}
