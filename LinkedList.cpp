#include <bits/stdc++.h>
using namespace std;
struct NODE{
	int data;
	struct NODE *Next;
};
typedef struct NODE Node;

struct LIST{
	Node *Head;
	Node *Tail;
};
typedef struct LIST List;

void MAKENULL_LIST(List &L){
	L.Head=L.Tail=NULL;
}

Node *GetNode(int x){
	Node *P=new Node;
	P->Next=NULL;
	P->data=x;
	return P;
}

void ADD_TAIL(Node *P, List &L){
	if(L.Head==NULL)
		L.Head=L.Tail=P;
	else {
		L.Tail->Next=P;
		L.Tail=P;
	}	
}

void ADD_HEAD(Node *P, List &L){
	if(L.Head==NULL)
		L.Head=L.Tail=P;
	else{
		P->Next=L.Head;
		L.Head=P;
	}	
}

void SORT_LIST(List &L){
	Node *i, *j;
	
	i=L.Head;
	while(i!=NULL){
		j=i->Next;
		while(j!=NULL){
			if(i->data>=j->data){
				swap(i->data, j->data);
			}
			j=j->Next;
		}
		i=i->Next;
	}
}

void ADD_NODE(Node *P, Node *i, List &L){
	Node *tmp;
	
	for(Node *j=L.Head; j!=NULL; j=j->Next){
		if (j->data==P->data){
			tmp=i->Next;
			i->Next=P;
			P->Next=tmp;
		}
	}
}

void ADD_ELEMENT(int x, List &L){
	Node *i;
	
	if(L.Head->data>=x){
		ADD_HEAD(GetNode(x), L);
		return;	
	}
	else{
		while(i<L.Tail->data){
			ADD_NODE(GetNode(x), i, L);
			return;
		}		
		i=i->Next;
	}	
	ADD_TAIL(GetNode(x), L);
}

Node *DELETE_HEAD(List &L){
	if(L.Head==NULL)
		cout<<"Loi";
	else
		L.Head=L.Head->Next;
	return L.Head;		
}

Node *DELETE_TAIL(List &L){
	Node *P=L.Head;
	while(P->Next->Next!=NULL){
		P=P->Next;
	}
	P->Next=P->Next->Next;
	return L.Head;
}

/*void DELETE(int Pos, List &L){
	if(Pos==0 || L.Head==NULL)
		
}*/

void READ_LIST(List &L){
	int n; cin>>n;
	for(int i=1; i<=n; i++){
		int x; cin>>x;
		Node *p=GetNode(x);
		ADD_TAIL(p, L);
	}
}

void READ_LIST2(List &L){
	int n; cin>>n;
	for(int i=1; i<=n; i++){
		int x; cin>>x;
		Node *p=GetNode(x);
		ADD_HEAD(p, L);
	}
}

void PRINT_LIST(List &L){
	for(Node *P=L.Head; P!=NULL; P=P->Next){
		cout<<P->data<<" ";
	}
}

//=======================//

void BT2a(List &L){
	MAKENULL_LIST(L);
	READ_LIST(L);
}

void BT2b(List &L){
	MAKENULL_LIST(L);
	READ_LIST2(L);
}

void BT2c(List &L){
	MAKENULL_LIST(L);
	READ_LIST(L);
	PRINT_LIST(L);
}

void BT3b(List &L){
	MAKENULL_LIST(L);
	READ_LIST(L);
	SORT_LIST(L);
	PRINT_LIST(L);
}

void BT4(List &L){
	MAKENULL_LIST(L);
	READ_LIST(L);
	SORT_LIST(L);
	int X; cin>>X;
	ADD_ELEMENT(X, L);
	PRINT_LIST(L);
}

//=======================//
int main (){
	List L;
	
	BT4(L);
	
	return 0;
}
