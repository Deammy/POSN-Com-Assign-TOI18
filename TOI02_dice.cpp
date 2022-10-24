/*TASK: TOI02_dice
LANG: C++
AUTHOR: Chayapat Kruthnim
CENTER: WU
*/
//FL539S
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void Swap(int *p,int a,int b,int c,int d){
	int temp = *(p+a);
	*(p+a) = *(p+b);
	*(p+b) = *(p+c);
	*(p+c) = *(p+d);
	*(p+d) = temp;
}

main(){
	int N;
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		int N[6] = {1,2,3,5,4,6};
		//cout << "TOP " << N[0] << " FRONT " << N[1] << " LEFT "<< N[2] << " BACK " << N[3] << " RIGHT " << N[4] << " DOWN " << N[5];
		string cmd;
		cin >> cmd;
		for(int j = 0 ; j < cmd.length(); j++){
			if(cmd[j] == 'F'){
				Swap(N,3,5,1,0);
			}
			else if(cmd[j] == 'B'){
				Swap(N,0,1,5,3);
			}
			else if(cmd[j] == 'L'){
				Swap(N,2,0,4,5);
			}
			else if(cmd[j] == 'R'){
				Swap(N,0,2,5,4);
			}
			else if(cmd[j] == 'C'){
				Swap(N,4,3,2,1);
			}
			else if(cmd[j] == 'D'){
				Swap(N,1,2,3,4);
			}
			//cout << "TOP " << N[0] << " FRONT " << N[1] << " LEFT "<< N[2] << " BACK " << N[3] << " RIGHT " << N[4] << " DOWN " << N[5];
		}
		cout << N[1] << " ";
	}


}

