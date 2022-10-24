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
short int m,n;
bool MAP[2011][2011];
int x[8] = {1,0,-1,1,1,-1,-1,0};
int y[8] = {0,1,1,-1,1,-1,0,-1};


main(){
	cin >> m >> n;
	int cnt = 0;
	int currx,curry;
	memset(MAP,0,sizeof(MAP));
	for(int i = 1 ; i <= m ; i++){
		string k;
		cin >> k;
		for(int j = 1 ; j <= n ; j++){
			MAP[i][j] = k[j-1] -'0';
		}
	}
	queue<pair<int , int> > Q;
	for(int i = 1 ; i <= m ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(MAP[i][j]){
				cnt++;
				Q.push(make_pair(i,j));
				while(!Q.empty()){
					currx = Q.front().first;
					curry = Q.front().second;
					Q.pop();
					MAP[currx][curry] = false;
					for(int k = 0 ; k < 8 ; k++){
						if(MAP[currx + x[k]][curry + y[k]]){
							Q.push(make_pair(currx + x[k],curry + y[k]));
							MAP[currx + x[k]][curry + y[k]] = false;
						}
					}
				}
			}
		}
	}
	cout << cnt;


}
