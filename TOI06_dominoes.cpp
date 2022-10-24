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
string A = "--";
string B = "||";
string k[30];
void Domino(int target,int use,int count){
	if(use == target){
		for(int i = 0 ; i < count ; i++){
			cout << k[i] << "\n";
		}
		cout << "E\n";
	}
	else if (use < target){
		k[count] = A;
		Domino(target,use + 1,count+1);
		k[count] = B;
		Domino(target,use + 2,count+1);
	}			
}

main(){
	int N;
	cin >> N;
	Domino(N,0,0);


}

