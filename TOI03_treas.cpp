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
	string k;
	cin >> k;
	d currx = 0,curry = 0;
	int sum = 0;
	while(k != "*"){
		int cnt = 0;
		sum = 0;
		//cout << "OK";
		while(k[cnt] >= '0' && k[cnt] <= '9'){
			sum += k[cnt]-'0';
			sum *= 10;
			cnt++;
		}
		sum = sum/10;
		if(k[cnt] == 'N' && k[cnt+1] == 'E'){
			currx += sum / (sqrt(2));
			curry += sum / (sqrt(2));
		}
		else if(k[cnt] == 'N' && k[cnt+1] == 'W'){
			currx -= sum / (sqrt(2));
			curry += sum / (sqrt(2));
		}
		else if(k[cnt] == 'S' && k[cnt+1] == 'W'){
			currx -= sum / (sqrt(2));
			curry -= sum / (sqrt(2));
		}
		else if(k[cnt] == 'S' && k[cnt+1] == 'E'){
			currx += sum / (sqrt(2));
			curry -= sum / (sqrt(2));
		}
		else if(k[cnt] == 'N'){
			curry += sum;
		}
		else if(k[cnt] == 'S'){
			curry -= sum;
		}
		else if(k[cnt] == 'E'){
			currx += sum;
		}
		else if(k[cnt] == 'W'){
			currx -= sum;
		}
		cin >> k;
	}
	printf("%.3lf %.3lf\n%.3lf",currx,curry,sqrt(pow(currx,2) + pow(curry,2)));


}

