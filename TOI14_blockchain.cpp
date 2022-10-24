/*TASK:
LANG: C++
AUTHOR: Chayapat Kruthnim
CENTER: WU
*/
//FL539S
#include<bits/stdc++.h>
#define ll long long int
#define d double
#define ull unsigned long long

using namespace std;

main(){
	map< vector< pair <int,int> > ,int > A;
	int N,M;
	cin >> N >> M;
	for(int i = 0 ; i < N ; i++){
		int k;
		cin >> k;
		vector<pair<int,int> > p;
		for(int j = 0 ; j < k-1 ; j++){
			int a,b;
			cin >> a >> b;
			if(a > b){
				int temp = a;
				a = b;
				b = temp;
			}
			p.push_back({a,b});
		}
		sort(p.begin(),p.end());
		A[p]++;
	}
	for(int i = 0 ; i < M ; i++){
		int k;
		cin >> k;
		vector<pair<int,int> > p;
		for(int j = 0 ; j < k-1 ; j++){
			int a,b;
			cin >> a >> b;
			if(a > b){
				int temp = a;
				a = b;
				b = temp;
			}
			p.push_back({a,b});
		}
		sort(p.begin(),p.end());
		if(A.count(p)) cout << A[p] << "\n";
		else cout << 0 << "\n";
	}

}

