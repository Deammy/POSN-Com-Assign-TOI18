/*TASK: Day8_10_SMS
LANG: C++
AUTHOR: Chayapat Kruthnim
CENTER: WU
*/
//FL539S
#include<bits/stdc++.h>
#define ll long long int
#define d double

using namespace std;

main(){
	int count = 0;
	int N;
	cin >> N;
	string A[3][3];
	A[0][1] = "ABC";
	A[0][2] = "DEF";
	A[1][0] = "GHI";
	A[1][1] = "JKL";
	A[1][2] = "MNO";
	A[2][0] = "PQRS";
	A[2][1] = "TUV";
	A[2][2] = "WXYZ";
	char Word[N];
	memset(Word,'\0',sizeof(Word));
	int currx,curry;
	int x,y,z;
	cin >> x >> z;
	currx = (x-1)/3;
	curry = (x-1)%3;
	//cout << "XY " << currx << " " << curry << "\n";
	if(currx != 0 || curry != 0){
		//cout << A[currx][curry][(z-1) % A[currx][curry].length()] << "\n";
		Word[count] = A[currx][curry][(z-1) % A[currx][curry].length()];
		count++;
	}
	for(int i = 1 ; i < N ; i++){
		cin >> y >> x >> z;
		currx += x;
		curry += y;
		currx = currx % 3;
		curry = curry % 3;
		if(currx < 0){
			currx = 3 - currx;
		}
		if(curry < 0){
			curry = 3 - curry;
		}
		//cout << "XY " << currx << " " << curry << "\n";
		if(currx != 0 || curry != 0){
			//cout << A[currx][curry][(z-1) % A[currx][curry].length()] << "\n";
			Word[count] = A[currx][curry][(z-1) % A[currx][curry].length()];
			count++;
		}
		else{
			while(z > 0 && count > 0){
				Word[count - 1] = '\0';
				count--;
				z--;
			}
		}
	}
	if(strlen(Word) > 0){
		char *p;
		p = Word;
		for(int i = 0 ; i < count ; i++){
			cout <<*(p+i);
		}
	}
	else{
		cout << "null";
	}
}
