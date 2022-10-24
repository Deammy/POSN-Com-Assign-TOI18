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
char C[25][25];
int Change(char k){
	if(k>= 'a' && k <= 'z') return k -'a';
	else return k - 'A';
}
char Changechar(char k){
	if(k>= 'a' && k <= 'z') return k;
	else return k - 'A' + 'a';
}
bool FindWord(int x,int y,string Word,int currx , int curry,int A , int B){
	for(int i = 2 ; i < Word.length() ; i++){
		currx += x;
		curry += y;
		//cout << currx << " " << curry << " ";
		if(Changechar(Word[i]) != C[currx][curry] || currx < 0 || curry < 0 || currx >= A || curry >= B){
			return false;
		}
	}
	return true;
}
main(){
	int a,b,k,safe1,safe2;
	cin >> a >> b;
	int countarr[26] = {0};
	int A[26][a*b][2];
	for(int i = 0 ; i < a ; i++){
		for(int j = 0 ; j < b ; j++){
			cin >> C[i][j];
			k = Change(C[i][j]);
			//cout << k << " ";
			C[i][j] = Changechar( C[i][j] );
			A[k][countarr[k]][0] = i;
			A[k][countarr[k]++][1] = j;
		}
	}
	int N,count;
	cin >> N;
	while(N-- > 0){
		int chk = 0,count = 0;
		string Word;
		cin >> Word;
		k = Change(Word[0]);
		while(!chk){
			for(int i = -1 ; i < 2 ; i++){
				for(int j = -1 ; j < 2 ; j++){
					safe1 = A[k][count][0] + i;
					safe2 = A[k][count][1] + j;
					if(Word[1] != '\0' && (i != 0 || j != 0 )&& safe1 >= 0 && safe1 < a && safe2 >= 0 && safe2 < b && C[safe1][ safe2] == Changechar(Word[1]) ){
						chk = FindWord(i,j,Word,safe1,safe2,a,b);
					}
					if(chk || Word[1] == '\0'){
						cout << A[k][count][0] << " " << A[k][count][1] << "\n";
						chk = 1;
						break;
					}
				}
				if(chk) break;
			}
			count++;
		}
	}
	/*
8 11
ascDEFGhigg
hTqkComPutk
FayUcompuTm
FcsierMqsrc
bkoArUePeyv
Klcbqwekumk
sreTNIophtb
yUiqlxcnBje
1
stack
*/
}

