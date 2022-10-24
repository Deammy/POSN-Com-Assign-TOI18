#include<bits/stdc++.h>
#define ll long long int
#define d double
#define ull unsigned long long
using namespace std;
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	cin >> N >> K;
	pair<int,int> home[N];
	vector<int> key(N,INT_MAX);
	for(int i = 0 ; i < N ; i++){
		int a,b;
		cin >> a >> b;
		home[i] = {a,b};
	}
	vector<int> result;
	ll sum = 0;
	int a;
	for(int i = 0 ; i < N-1 ; i++){
		int mn = INT_MAX;
		for(int j = i+1 ; j < N ; j++){
			if(key[j] > abs(home[i].first - home[j].first) + abs(home[i].second - home[j].second)){
				key[j] = abs(home[i].first - home[j].first) + abs(home[i].second-home[j].second);			
			}
			if(mn > key[j]){
				a = j;
				mn = key[j];
			}
		}
		sum += mn;
		result.push_back(mn);
		swap(home[i + 1],home[a]);
		swap(key[a],key[i+1]);
		//cout << key[i+1] << "\n";
	}
	sort(result.begin(),result.end());
	for(int i = result.size() - 1 ; i > result.size() - K ; i--){
		sum -= result[i];
	}
	cout << sum;
}
