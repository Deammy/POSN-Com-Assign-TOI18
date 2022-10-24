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
char Table[5][5];
int k;
void Fall(int A,int B){
	for(int i = 0 ; i < A-1 ; i++){
		for(int j = 1 ; j < B - 1 ; j++){
			k = i;
			if(Table[i][j] != '-' && Table[i][j] != '#'){
				while(Table[k+1][j] == '-'){
					k++;
				}
				Table[k][j] = Table[i][j];
				Table[i][j] = '-';
			}	
		}
	}
}
bool Point(int x,int y,int *score){
	int chk = 0;
	if(Table[x+1][y] == Table[x][y]){
		chk = 1;
		Table[x+1][y] = '-';
		*score += 5;
	}
	if(Table[x][y+1]== Table[x][y]){
		chk = 1;
		Table[x][y+1] = '-';
		*score += 5;
	}
	if(Table[x][y-1] == Table[x][y]){
		chk = 1;
		Table[x][y-1] = '-';
		*score += 5;
	}
	return chk;
}

main(){
	int A,B,x,y,chk;
	char cmd,mem;
	cin >> A >> B;
	for(int i = 0 ; i < A ; i++){
		for(int j = 0 ; j < B ; j++){
			cin >> Table[i][j];
		}
	}
	int N,score = 0;
	cin >> N;
	while(N-- > 0){
		cin >> x >> y >> cmd;
		mem = Table[x][y];
		Table[x][y] = '-';
		if(cmd == 'L') y--;
		else y++;
		if(Table[x][y] == '-'){
			while(Table[x+1][y] == '-'){
				x++;
			}
			Table[x][y] = mem;
			//cout << x << " " << y << "\n";
			//cout << Table[x][y];
			chk = Point(x,y,&score);
		}
		if(chk){
			Table[x][y] = '-';
			score += 5;
		}
		else {
			score -= 5;
		}
		Fall(A,B);
	}
	cout << score << "\n";
	for(int i = 0 ; i < A ; i++){
		for(int j = 0 ; j < B ; j++){
			cout << Table[i][j] << " ";
		}
		cout << "\n";
	}
}

