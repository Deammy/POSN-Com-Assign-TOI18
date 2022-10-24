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
int A[1200][1200];
int mn1 = 1e9;
int mn2 = 1e9;

struct MAP{
	int Up;
	int Down;
	int Left;
	int Right;
	bool visited;
};
MAP mp[40001] = {{-1,-1,-1,-1,0}};
void solve(int a,int i,int j){
	A[i][j] = a;
	mn1 = min(i,mn1);
	mn2 = min(j,mn2);
	mp[a].visited = true;
	if(mp[a].Right != -1 && !mp[mp[a].Right].visited){
		solve(mp[a].Right,i,j+1);
	}
	if(mp[a].Left != -1&& !mp[mp[a].Left].visited){
		solve(mp[a].Left,i,j-1);
	}
	if(mp[a].Up != -1&& !mp[mp[a].Up].visited){
		solve(mp[a].Up,i-1,j);
	}
	if(mp[a].Down != -1&& !mp[mp[a].Down].visited){
		solve(mp[a].Down,i+1,j);
	}
}

main(){
	int a,b;
	cin >> a >> b;
	
	for(int i = 0 ; i < a*b-1 ; i++){
		int m,n;
		char k;
		cin >> m >> k >> n;
		if(k == 'U'){
			mp[m].Down = n;
			mp[n].Up = m;
		}
		else{
			mp[m].Right = n;
			mp[n].Left = m;
		}	
	}
	solve(0,600,600);
	for(int i = mn1 ; i < mn1 + a ; i++){
		for(int j = mn2 ; j < mn2 + b ; j++){
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
}

