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
	map< string ,int> m;
	string k;
	for(int i = 0 ; i < A ; i++){
		cin >> k;
		m[k] = i+1;
	}
	int N,Q;
	string Word;
	cin >> N;
	set< int,less<int> > S[N];
	for(int j = 0 ; j < N ; j++){
		int chk[A+1] = {0};
		string Ans;
		cin >> Q;
		cin >> Word;
		for(int i = 0 ; i <= Q - B ; i++){
			Ans = Word.substr(i,B);
			if(m.count(Ans)) {
				S[j].insert(m[Ans]);
			}
		}
	}
	for(int i = 0 ; i < N ; i++){
		if(!S[i].empty()){
			for(set<int, less<int> > :: iterator x = S[i].begin() ; x != S[i].end() ; x++){
				cout << *x << " ";
			}
		}
		else cout << "OK";
		cout << "\n";
	}

}
