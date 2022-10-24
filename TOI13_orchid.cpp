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
	int N;
	cin >> N;
	int j = N;
	vector<int> result;
	
	for(int i = 0 ; i < j ; i++){
		int x;
		cin >> x;
		auto k = upper_bound(result.begin(),result.end(),x);
		if(k == result.end()){
			N--;
			result.push_back(x);
		}
		else{
			
			result[k - result.begin()] = x;
		}
	}
	cout << N;


}

