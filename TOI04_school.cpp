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
char MAP[100][100];
int MAP2[100][100] = {1};
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
main(){
	int A,B,s1,s2,size;
	cin >> B >> A;
	for(int i = 1 ; i <= A ; i++){
		for(int j = 1 ; j <= B ; j++){
			cin >> MAP[i][j];
			if(MAP[i][j] == 'T'){
				MAP2[i][j] = 0;
			}
		}
	}
	for(int i = 1 ; i <= A ; i++){
		for(int j = 1 ; j <= B ; j++){
			MAP2[i][j] += MAP2[i-1][j] + MAP2[i][j-1] - MAP2[i-1][j-1];
		}
	}
	bool chk = false;
	for(int i = min(A,B) ; i >= 0 ; i--){
		for(int j = i ; j <= A ; j++){
			for(int k = i ; k <= B ; k++){
				int h1 = MAP2[j][k] - MAP2[j-i][k] - MAP2[j][k-i] + MAP2[j-i][k-i];
				d h2 = MAP2[j][k] - MAP2[j-i][k] - MAP2[j][k-i] + MAP2[j-i][k-i];
				if(h1 == h2 && MAP[j][k] != 'T') {
					cout << (i)*(i) << " " << j << " " << k << "\n";
					
					chk = true;
					s1 = j-i;
					s2 = k-i;
					size = i;
					break;
				}
			}
			if(chk) break;
		}
		if(chk) break;
	}
	int numb = 0;
	queue<pair<int,int> > Q;
	for(int i = s1+1 ; i < s1 + size ; i++){
		for(int j = s2+1 ; j < s2 + size ; j++){
			if(MAP[i][j] == 'P'){
				numb++;
				MAP[i][j] = 'S';
				Q.push(make_pair(i,j));
				while(!Q.empty()){
					int currx = Q.front().first;
					int curry = Q.front().second;
					Q.pop();
					for(int k = 0 ; k < 4 ; k++){
						if(MAP[currx+dx[k]][curry + dy[k]] == 'P'){
							Q.push(make_pair(currx+dx[k],curry + dy[k]));
							MAP[currx+dx[k]][curry + dy[k]] = 'S';
						}
					}
				}
			}
		}
	}
	cout << numb;
	
}

