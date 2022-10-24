/*TASK: TOI04_cromartie
LANG: C++
AUTHOR: Chayapat Kruthnim
CENTER: WU
*/
//FL539S
#include<bits/stdc++.h>
using namespace std;
main(){
    int N,mx1 = 0,mx2 = 0,S,H,S1;
    cin >> N;
    char Table[10][100] = {0};
    for(int i = 0 ; i < N ; i++){
        cin >> S >> H;
        S--;
        S1 = S+(2*H-1);
        mx1 = max(H,mx1);
        mx2 = max(S + (2*H),mx2);
        for(int i = 0 ; i < H ; i++){
        	if(Table[i][S] == 2) Table[i][S++] = 3;
        	else Table[i][S++] = 1;
        	if(Table[i][S1] == 1) Table[i][S1--] = 3;
			else(Table[i][S1--]) = 2;
		}
    }
    int chk[100] = {0};
    for(int i = mx1 - 1 ; i >= 0 ; i--){
    	for(int j = 0 ; j < mx2 ; j++){
    		if(Table[i][j] == 0 && chk[j] == 0) cout << ".";
    		else if (Table[i][j] == 1 && chk[j] == 0){
    			cout << "/";
    			chk[j] = 1; 
			}
			else if(Table[i][j] == 2 && chk[j] == 0){
    			cout << "\\";
    			chk[j] = 1; 
			}
			else if(Table[i][j] == 3 && chk[j] == 0){
				cout << "v";
				chk[j] = 1;
			}
			else cout << "X";
		}
		cout << "\n";
	}
}
