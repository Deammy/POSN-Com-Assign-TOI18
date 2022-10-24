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
	ios::sync_with_stdio(0);
	cin.tie(0);
	int L,N,X,p,cnt,a,k,b;
	cin >> L >> N >> X;
	int lift[L],time[X],staff[L];
	vector<ll> st;
	st.push_back(0);
	for(int i = 0 ; i < L ; i++){
		cin >> lift[i];
	}
	for(int i = 0 ; i < L ; i++){
		int o;
		cin >> o;
		lift[i] -= o;
	}
	for(int i = 1 ; i <= N ; i++){
		cin >> p;
		st.push_back(p);
		st[i] = st[i-1] + p;
	}
	for(int i = 0 ; i < X ; i++){
		cin >> time[i];
	}
	bool chk;
	auto s = st.begin();
	for(int i = 0 ; i < X ; i++){
		chk = false;
		cin >> a;
		for(int j = 0 ; j < L ; j++){
			cnt = 0;
			if(j != L-1) cin >> b;
			else b = N;
			k = a;
			while(true){
				int x = upper_bound(s + k , s + b , st[k-1] + lift[j]) - s;
				if(x == b) break;
				else {
					cnt++;
					k = x;
					if(cnt > time[i]){
						chk = true;
						break;
					}
				}
			}
			if(chk) break;
			a = b;
		}
		if(!chk) cout << "P\n";
		else cout << "F\n";
	}
}

