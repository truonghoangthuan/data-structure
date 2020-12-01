#include<bits/stdc++.h>

#define oo 1000000000
#define MaxLength 100
using namespace std;
typedef int ElementType;
typedef int Position;
typedef struct{
	ElementType Elements[MaxLength];
	Position Last;
} List;

void MAKENULL_LIST(List& L){
	L.Last=0;
}

void INSERT_LIST(ElementType X, Position P, List& L){
	if(L.Last==MaxLength)
		printf("Ds day");
	else if(P<1 || P>L.Last+1)
		printf("Vt khong hop le");
	else{
		Position i;
		for(i=L.Last; i>P-1; i--)
			L.Elements[i]=L.Elements[i-1];
		L.Elements[P-1]=X;
		L.Last++;
	}
}

void DELETE_LIST(Position P, List& L){
	Position i;
	
	for(i=P; i<L.Last; i++)
		L.Elements[i-1]=L.Elements[i];
	L.Last--;
}

Position LOCATE(ElementType X, List& L){
	Position i=1;
	
	while(i!=L.Last+1){
		if(L.Elements[i-1]==X)
			return i;
		else
			i++;	
	} 
}

Position FIRST(List& L){
	return 1;
}

ElementType RETRIEVE(Position P, List& L){
	return L.Elements[P-1];
}

Position ENDLIST(List& L){
	return L.Last+1;
}

Position NEXT(Position P, List& L){
	return P+1;
}

void SORT_LIST(List& L){
	
	Position p=FIRST(L);
	while(p!=ENDLIST(L)){
		Position q=NEXT(p, L);
		while(q!=ENDLIST(L)){
			if(RETRIEVE(p, L)>=RETRIEVE(q, L))
				swap(L.Elements[p-1], L.Elements[q-1]);
			q=NEXT(q, L);
		}
		p=NEXT(p, L);
	}
}

void ADD_ELEMENT(ElementType X, List& L){
	Position i=1;
	
	for(i=1; i<=L.Last; i++){
		if(RETRIEVE(i, L)>=X){
			INSERT_LIST(X, i, L);
			return;
		}
	}
	INSERT_LIST(X, L.Last+1, L);
}	 

void ADD_ELEMENT2(List& L){
	ElementType X;
	Position n, i=1;
	
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &X);
		ADD_ELEMENT(X, L);
	}
}

void INSERT_LIST2(List& L){
	Position i, n;
	ElementType x;
	
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &x);
		INSERT_LIST(x, 1, L);
	}
}

void REPEAT(List& L){
	Position p,q;
	
	for(p=1; p<=L.Last; p++){
		for(q=p+1; q<=L.Last; q++){
			if(RETRIEVE(p, L)==RETRIEVE(q, L)){
				DELETE_LIST(p, L);
				p--;
			}		
		}
	}
}

void DELETE_ODD(List& L){
	Position i=FIRST(L);
	
	while(i!=ENDLIST(L)){
		if(RETRIEVE(i, L)%2!=0){
			DELETE_LIST(i, L);
			i--;
		}
		i=NEXT(i, L);
	}
}

void READ_LIST(List& L){
	int n, x, i;
	
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &x);
		INSERT_LIST(x, i, L);
	}
}

void PRINT_LIST(List& L){
	int i;
	
	for(i=1; i<=L.Last; i++)
		printf("%d ", RETRIEVE(i, L));
	printf("\n");
}

void INSERT_LIST3(List& L){
	List L1, L2;
	Position i=1;
	
	MAKENULL_LIST(L);
	MAKENULL_LIST(L1);
	READ_LIST(L1);
	MAKENULL_LIST(L2);
	READ_LIST(L2);
	for(i=1; i<=L1.Last; i++){
		INSERT_LIST(L1.Elements[i-1], i, L);
	}
	SORT_LIST(L);
	for(i=1; i<=L2.Last; i++){
		ADD_ELEMENT(RETRIEVE(i, L2), L);
	}
}

void EVEN_ODD(List& L){
	Position i;
	List L1, L2;
	
	MAKENULL_LIST(L1);
	MAKENULL_LIST(L2);
	for(i=1; i<=L.Last; i++){
		if(RETRIEVE(i, L)%2!=0)
			INSERT_LIST(L.Elements[i-1], L1.Last+1, L1);
		else
			INSERT_LIST(L.Elements[i-1], L2.Last+1, L2);
	}
	PRINT_LIST(L1);
	PRINT_LIST(L2);
}
/*======================*/

void BT1a(List& L){
	
	READ_LIST(L);
}

void BT1b(List& L){
	int i, X, n;
	
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &X);
		INSERT_LIST(X, 1, L);
	}	
}

void BT1c(List& L){
	
	MAKENULL_LIST(L);
	READ_LIST(L);
	SORT_LIST(L);
	PRINT_LIST(L);
}

void BT3a(List& L){
	
	SORT_LIST(L);
}

void BT4(List& L){
	ElementType X;
	
	MAKENULL_LIST(L);
	READ_LIST(L);
	SORT_LIST(L);
	scanf("%d", &X);
	ADD_ELEMENT(X, L);
	PRINT_LIST(L);
}

void BT5(List& L){
	ElementType X;
	
	MAKENULL_LIST(L);
	READ_LIST(L);
	PRINT_LIST(L);
	scanf("%d", &X);
	DELETE_LIST(LOCATE(X, L), L);
	PRINT_LIST(L);
}

void BT6(List& L){
	
	MAKENULL_LIST(L);
	READ_LIST(L);
	SORT_LIST(L);
	ADD_ELEMENT2(L);
	PRINT_LIST(L);
}

void BT7(List& L){
	
	MAKENULL_LIST(L);
	READ_LIST(L);
	REPEAT(L);
	SORT_LIST(L);
	PRINT_LIST(L);
}

void BT8(List& L){
	
	MAKENULL_LIST(L);
	READ_LIST(L);
	SORT_LIST(L);
	ADD_ELEMENT2(L);
	REPEAT(L);
	PRINT_LIST(L);
}

void BT9(List& L){
	
	INSERT_LIST3(L);
	PRINT_LIST(L);
}

void BT10(List& L){
	
	MAKENULL_LIST(L);
	READ_LIST(L);
	DELETE_ODD(L);
	PRINT_LIST(L);
}

void BT11(List& L){
	
	MAKENULL_LIST(L);
	READ_LIST(L);
	EVEN_ODD(L);
}
/*======================*/

int main(){
	ElementType X;
	List L;
	Position P;
	
	BT9(L);
	
	return 0;
}

