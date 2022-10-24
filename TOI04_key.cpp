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

main(){
	int A,B;
	cin >> A >> B;
	char Lock1[A],Lock2[A],Key[B];
	cin >> Lock1 >> Lock2 >> Key;
	for(int i = 0 ; i < B ; i++){
		for(int j = 0 ; j < A ; j++){
			if(Key[i] > Lock1[j] && Key[i] > Lock2[j]) Key[i] = (char)max(Lock1[j],Lock2[j]);
			else if(Key[i] < Lock1[j] && Key[i] < Lock2[j]) Key[i] = (char)min(Lock1[j],Lock2[j]);
		}
	}
	cout << Key ;


}

