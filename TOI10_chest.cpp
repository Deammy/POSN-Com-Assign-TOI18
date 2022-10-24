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
struct pos{
	int st;
	int ty;
	int value;
};
bool cmp(pos a,pos b){
	if(a.st == b.st) return a.ty < b.ty;
	return a.st < b.st;
}
main(){
	int N,L;
	cin >> N >> L;
	vector<pos> B;
	for(int i = 0 ; i < N ; i++){
		int a,b,c;
		cin >> a >> b >> c;
		B.push_back({b,2,a});
		B.push_back({c+1,1,a});
	}
	sort(B.begin(),B.end(),cmp);
	ll arr[11];
	for(int i = 2 ; i <= 7 ; i++){
		arr[i] = 1;
	}
	ll curr;
	int before = -1;
	int l = 0;
	ll mx = 0;
	for(auto x : B){
		curr = 1;
		if(x.ty == 2){
			if(x.value == 2) arr[2]++;
			if(x.value == 3) arr[3]++;
			if(x.value == 4) arr[2]+=2;
			if(x.value == 5) arr[5]++;
			if(x.value == 6) arr[2]++, arr[3]++;
			if(x.value == 7) arr[7]++;
			if(x.value == 8) arr[2]+=3;
			if(x.value == 9) arr[3]+=2;
			if(x.value == 10) arr[2]++, arr[5]++;	
		}
		if(x.ty == 1) {
			if(x.value == 2) arr[2]--;
			if(x.value == 3) arr[3]--;
			if(x.value == 4) arr[2]-=2;
			if(x.value == 5) arr[5]--;
			if(x.value == 6) arr[2]--, arr[3]--;
			if(x.value == 7) arr[7]--;
			if(x.value == 8) arr[2]-=3;
			if(x.value == 9) arr[3]-=2;
			if(x.value == 10) arr[2]--, arr[5]--;	
		}
		curr *= arr[2];
		curr *= arr[3];
		curr *= arr[5];
		curr *= arr[7];
		if(mx == curr){
			before = x.st;
			l++;
		}
		if(mx < curr){
			mx = curr;
			l = 1;
			before = x.st;
		}
		if(curr < mx && before != -1){
			l += x.st - before - 1;
			before = -1;
		}
	}
	cout << mx << " " << l;
}
/*
5 10 
3 0 4 
2 2 3 
5 4 7
6 7 9
2 3 3
*/

