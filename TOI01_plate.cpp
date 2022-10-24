/*TASK: TOI01_plate
LANG: C++
AUTHOR: Chayapat Kruthnim
CENTER: WU
*/
//FL539S
#include<bits/stdc++.h>
#define ll long long int
#define d double

using namespace std;
typedef struct Q{
	int Grade;
	int Id;
	struct Q *next;
}STUDENT;
STUDENT *EnterQ(STUDENT *head,STUDENT *p){
	STUDENT *q;
	q = head;
	while(q->Grade != p->Grade){
		if(q->next == NULL){
			q->next = p;
			return p;
		}
		q = q->next;
	}
	while((q -> next != NULL)&&(q -> next-> Grade == p-> Grade )){
		q = q->next;
	}
	STUDENT *temp;
	temp = q->next;
	q ->next = p;
	p->next = temp;
}

STUDENT *getnode(){
	STUDENT *p;
	p = new STUDENT;
	p->next = NULL;
	return p;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ID[10000];
	int A,B;
	cin >> A >> B;
	for(int i = 0 ; i < B ; i++){
		int a,b;
		cin >> a >> b;
		ID[b] = a;
	}
	string cmd;
	STUDENT *head;
	head = getnode();
	STUDENT *last;
	while(cmd != "X"){
		if(cmd == "E"){
			int k;
			cin >> k;
			STUDENT *p;
			p = getnode();
			p->Id = k;
			p->Grade = ID[k];
			if(head->next == NULL){
				head->next = p;
			}
			else{
				STUDENT *m;
				m = EnterQ(head,p);
			}
		}
		if(cmd == "D"){
			STUDENT *backup;
			backup = head -> next;
			head -> next = head -> next -> next;
			cout << backup->Id << "\n";
			delete backup;
		}
		cin >> cmd;
	}
	cout << 0;

}

