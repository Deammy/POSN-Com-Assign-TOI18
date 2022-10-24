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
char graph[1002][1002];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
bool visited[1002][1002] = {false};
int cnt = 0;
void BFS(int i,int j){
	queue<pair<int,int> >q;
	q.push({i,j});
	graph[i][j] = '1';
	while(!q.empty()){
		int m = q.front().first;
		int n = q.front().second;
		
		q.pop();
		for(int k = 0 ; k < 4 ; k++){
			if(graph[m + dx[k]][n + dy[k]] == '.'){
				q.push({m + dx[k],n + dy[k]});
				graph[m + dx[k]][n + dy[k]] = '1';
			}
		}
	}
}
void BFS2(int i,int j){
	queue<pair<int,int> >q;
	q.push({i,j});
	visited[i][j] = true;
	while(!q.empty()){
		int m = q.front().first;
		int n = q.front().second;
		
		q.pop();
		for(int k = 0 ; k < 4 ; k++){
			if(graph[m + dx[k]][n + dy[k]] == '1') {
				//cout << m + dx[k] << " "  <<n + dy[k] << "\n";
				cnt++;
			}
			else if(graph[m + dx[k]][n + dy[k]] == 'X' && !visited[m + dx[k]][n + dy[k]]) {
				q.push({m + dx[k],n + dy[k]});
				visited[m + dx[k]][n + dy[k]] = true;
			}
		}
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M,N;
	cin >> M >> N;
	memset(graph,'\0',sizeof(graph));
	for(int i = 1 ; i <= M ; i++){
		for(int j = 1 ; j <= N ; j++){
			cin >> graph[i][j];
		}
	}
	
	for(int i = 1 ; i <= M ; i++){
		if(graph[i][1] == '.') BFS(i,1);
		if(graph[i][N] == '.') BFS(i,N);
	}
	for(int i = 1 ; i <= N ; i++){
		if(graph[1][i] == '.') BFS(1,i);
		if(graph[M][i] == '.') BFS(M,i);
	}
	int mx = 0;
	for(int i = 1 ; i <= M ; i++){
		for(int j = 1 ; j <= N ; j++){
			cnt = 0;
			if(graph[i][j] == 'X' && !visited[i][j]) BFS2(i,j);
			mx = max(mx,cnt);
		}
	}
	cout << mx;


}
/*
8 7
.......
.XXXXX.
.X...X.
.X.X.X.
.X.X.X.
.X...X.
.XXXXX.
.......
*/

