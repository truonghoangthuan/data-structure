#include<bits/stdc++.h>
using namespace std;
typedef int ElementType;
typedef struct Node{
	ElementType Data;
	Node *Next;
};
typedef struct Node *Pos;
typedef Pos List;

void MAKENULL_LIST(List &Header){
	Header=new Node;
	Header->Next=NULL;
}

Pos FIRST(List &L){
	return L;
}

Pos ENDLIST(List &L){
	return NULL;
}

void INSERT_LIST(ElementType X, Pos P, List &L){
	Pos T=new Node;
	T->Data=X;
	T->Next=P->Next;
	P->Next=T;
}

void DELETE_LIST(Pos P, List &L){
	Pos T;
	
	if(P->Next!=NULL){
		T=P->Next;
		P->Next=T->Next;
		free(T);
	}
}

Pos LOCATE(ElementType X, List &L){
	Pos P=L;
	
	while(P->Next!=NULL)
		if(P->Next->Data==X)
			break;
		else
			P=P->Next;
	return P;			
}

ElementType RETRIEVE(Pos P, List &L){
	if(P->Next!=NULL)
		return P->Next->Data;
	else
		return 0;	
}

void SORT_LIST(List &L){
	
	Pos i=FIRST(L);
	while(i!=ENDLIST(L)){
		Pos j=i->Next;
		while(j!=ENDLIST(L)){
			if(RETRIEVE(j, L)!=NULL && RETRIEVE(i, L)!=NULL && RETRIEVE(i, L)>RETRIEVE(j, L))
				swap(i->Next->Data, j->Next->Data);
			j=j->Next;	
		}
		i=i->Next;
	}
}

void ADD_ELEMENT(int x, List &L){
	
	for(Pos i=FIRST(L); i!=NULL; i=i->Next){
		if(RETRIEVE(i, L)!=NULL && RETRIEVE(i, L)>x || i->Next==ENDLIST(L)){
			INSERT_LIST(x, i, L);
			return;
		}
	}
}

void REPEAT(List &L){
	Pos i, j;
	
	for(i=FIRST(L); i!=ENDLIST(L); i=i->Next){
		for(j=i->Next; j!=ENDLIST(L); j=j->Next){
			if(i->Data!=NULL && j->Data!=NULL && i->Data==j->Data){
				DELETE_LIST(i, L);
				i=FIRST(L);
				break;
			}	
		}
	}
}

void READ_LIST(List &L){
	int n; cin>>n;
	
	MAKENULL_LIST(L);
	Pos P=FIRST(L);
	for(int i=1; i<=n; i++){
		int x; cin>>x;
		INSERT_LIST(x, P, L);
		P=P->Next;
	}
}

void READ_LIST2(List &L){
	int n; cin>>n;
	
	MAKENULL_LIST(L);
	for(int i=1; i<=n; i++){
		int x; cin>>x;
		INSERT_LIST(x, L, L);
	}
}

void PRINT_LIST(List &L){
	for(Pos i=FIRST(L); i!=ENDLIST(L); i=i->Next){
		if(RETRIEVE(i, L)!=NULL)
			cout<<RETRIEVE(i, L)<<" ";
	}
}

void INSERT_LIST2(List &L){
	List L1, L2;
	
	MAKENULL_LIST(L);
	MAKENULL_LIST(L1);
	READ_LIST(L1);
	MAKENULL_LIST(L2);
	READ_LIST(L2);
	Pos k=FIRST(L);
	Pos i=FIRST(L1);
	while(i!=ENDLIST(L1)){
		INSERT_LIST(RETRIEVE(i, L), k, L);
		k=k->Next;
		i=i->Next;
	}
	SORT_LIST(L);
	k=FIRST(L);
	Pos j=FIRST(L2);
	while(j!=ENDLIST(L2)){
		ADD_ELEMENT(RETRIEVE(j, L), L);
		k=k->Next;
		j=j->Next;
	}
}

void DELETE_ODD(List &L){
	
	for(Pos i=FIRST(L); i!=ENDLIST(L); i=i->Next){
		if(RETRIEVE(i, L)!=NULL && RETRIEVE(i, L)%2!=0){
			DELETE_LIST(i, L);
			i=FIRST(L);
		}
	}
}

//=====================//

void BT2a(List &L){
	READ_LIST(L);
}

void BT2b(List &L){
	READ_LIST2(L);
	PRINT_LIST(L);
}

void BT2c(List &L){
	READ_LIST(L);
	PRINT_LIST(L);
}

void BT3b(List &L){
	READ_LIST(L);
	SORT_LIST(L);
	PRINT_LIST(L);
}

void BT4(List &L){
	
	READ_LIST(L);
	SORT_LIST(L);
	int x; cin>>x;
	ADD_ELEMENT(x, L);
	PRINT_LIST(L);
}

void BT5(List &L){
	
	READ_LIST(L);
	int x; cin>>x;
	DELETE_LIST(LOCATE(x, L), L);
	PRINT_LIST(L);
}

void BT6(List &L){
	
	READ_LIST(L);
	SORT_LIST(L);
	int n; cin>>n;
	for(int i=1; i<=n; i++){
		int x; cin>>x;
		ADD_ELEMENT(x, L);
	}
	PRINT_LIST(L);
}

void BT7(List &L){
	
	READ_LIST(L);
	SORT_LIST(L);
	REPEAT(L);
	PRINT_LIST(L);
}

void BT8(List &L){
	
	READ_LIST(L);
	SORT_LIST(L);
	int n; cin>>n;
	for(int i=1; i<=n; i++){
		int x; cin>>x;
		ADD_ELEMENT(x, L);
	}
	REPEAT(L);
	PRINT_LIST(L);
}

void BT9(List &L){
	INSERT_LIST2(L);
	PRINT_LIST(L);
}

void BT10(List &L){
	
	READ_LIST(L);
	DELETE_ODD(L);
	PRINT_LIST(L);
}

int SUM(List& L) {
	int sum = 0;
	for(Pos i = FIRST(L); i != ENDLIST(L); i = i->Next){
		sum += RETRIEVE(i, L);
	}
	return sum;
}

//=====================//
int main(){
	List L;
	
	READ_LIST(L);
	PRINT_LIST(L);
	cout << endl;
	cout << SUM(L);
	
	return 0;
}
