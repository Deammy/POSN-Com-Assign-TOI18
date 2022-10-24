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
	ll a,b;
	int count = 0;
	stack<char> A;
	stack<ll> B;
	string Pro;
	cin >> Pro;
	char Bot[Pro.length()];
	for(int i = 0 ; i < Pro.length() ; i++){
		if(Pro[i] == '['){
			A.push(Pro[i]);
		}
		else if(Pro[i] == ']'){
			while(A.top() != '['){
				Bot[count++] = A.top();
				A.pop();
			}
			A.pop();
		}
		else if(Pro[i] >= '1' && Pro[i] <= '3'){
			while(!A.empty() && A.top() != '[' && Pro[i] <= A.top()){
				Bot[count++] = A.top();
				A.pop();
			}
			A.push(Pro[i]);
		}
		else{
			Bot[count++] = Pro[i];

		}
	}
	while(!A.empty()){
		Bot[count++] = A.top();
		A.pop();
	}
	for(int i = 0 ; i < count ; i++){
		if(Bot[i] == '1'){
			a = B.top();
			B.pop();
			b = B.top();
			B.pop();
			B.push(( (a+b)*(4.00 / 100) ) + a + b)	;
		}
		else if(Bot[i] == '2'){
			a = B.top();
			B.pop();
			b = B.top();
			B.pop();
			B.push(( (a+b)*(8.00 / 100 ) ) + a + b)	;
		}
		else if(Bot[i] == '3'){
			a = B.top();
			B.pop();
			b = B.top();
			B.pop();
			B.push(( (a+b)*(16.00 / 100) ) + a + b)	;
		}
		else{
			B.push(20);
		}
	}
	cout << B.top();
}

