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
vector<ull> A;
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int mx = 0;
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		int k;
		cin >> k;
		mx = max(k,mx);
		A.push_back(k);
	}
	ull l = 0;
	ull r = mx;
	while(l < r){
		ull mid = (l + r)/2;
		vector<ull> chk;
		for(auto x : A){
			if(x > mid) chk.push_back(x);
		}
		bool chk1 = true;
		for(int i = 0 ; i < chk.size() ; i += 2){
			if(chk[i] != chk[i+1]){
				chk1 = false;
				break;
			}
		}
		if(chk1) r = mid;
		else l = mid + 1;
	}
	cout << r;

}

