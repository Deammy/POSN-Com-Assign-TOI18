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
int Map[20][20];
bool MAP(int targetx,int targety,int targett,int currx,int curry,int size){
	bool check1 = 0;
	bool check2 = 0;
	bool check3 = 0;
	bool check4 = 0;
	if(currx == targetx && curry == targety){
		return true;
	}
	if(Map[currx][curry] <= targett){
		return false;
	}
	if(Map[currx+1][curry] < Map[currx][curry] && currx+1 < size){
		check1 = MAP(targetx,targety,targett,currx+1,curry,size);
	}
	if(Map[currx-1][curry] < Map[currx][curry] && currx-1 >= 0){
		check2 = MAP(targetx,targety,targett,currx-1,curry,size);
	}
	if(Map[currx][curry+1] < Map[currx][curry] && curry+1 < size){
		check3 = MAP(targetx,targety,targett,currx,curry+1,size);
	}
	if(Map[currx][curry-1] < Map[currx][curry] && curry-1 >= 0){
		check4 = MAP(targetx,targety,targett,currx,curry-1,size);
	}
	return check1 || check2 || check3 || check4;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M,X,Y,count = 0;
	cin >> M >> X >> Y;
	int check[43] = {0};
	int Sort[43][2][M*M] = {0};
	for(int i = 0 ; i < M ; i++){
		for(int j = 0 ; j < M ; j++){
			cin >> Map[j][i];
			if(Map[j][i] >= -5 && Map[j][i] <= 37){
				Sort[Map[j][i] + 5][0][check[Map[j][i] + 5]] = j;
				Sort[Map[j][i] + 5][1][check[Map[j][i] + 5]] = i;
				check[Map[j][i] + 5]++;
			}
		}
	}
	for(int i = 42 ; i >=0 ; i--){
		while(check[i]-- > 0){
			if(MAP (X-1, Y-1, Map[X-1][Y-1], Sort[i][0][check[i]], Sort[i][1][check[i]], M)){
				cout << i - 5;
				return 0;
			}
		}
	}
}

