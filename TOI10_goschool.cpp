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
int graph[52][52] = {0};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M,N,q;
	cin >> M >> N >> q;
	while(q--){
		int b,a;
		cin >> b >> a;
		graph[N-a][b] = -1;
	}
	graph[N-1][1] = 1;
	for(int i = N-1 ; i >= 0 ; i--){
		for(int j = 1 ; j <= M ; j++){
			if(graph[i][j] == -1) graph[i][j] = 0;
			else if(i != N-1 || j != 1){
				graph[i][j] = graph[i+1][j] + graph[i][j-1];
			}
		}
	}
	for(int i = 0 ; i < N ; i++){
		for(int j = 1 ; j <= M ; j++){
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}

	cout << graph[0][M];
	return 0;
}
