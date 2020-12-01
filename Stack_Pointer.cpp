#include<bits/stdc++.h>

using namespace std;
typedef int ElementType;
typedef struct Node{
	ElementType Elements;
	Node *Next;
};
typedef struct Stack{
	Node *Top_idx;
};

void MAKENULL_STACK(Stack &S){
	S.Top_idx=NULL;
}

int EMPTY_STACK(Stack &S){
	return (S.Top_idx==NULL);
}

Node *GetNode(ElementType &X, Stack &S){
	Node *P = new Node;
	P->Next=NULL;
	P->Elements=X;
	return P;
}

void PUSH(ElementType &X, Stack &S){
	Node *P = GetNode(X, S);
	P->Next=S.Top_idx;
	S.Top_idx=P;
}

ElementType TOP(Stack &S){
	
	if(!EMPTY_STACK(S)){
		return S.Top_idx->Elements;
	}
}

void POP(Stack &S){
	
	if(!EMPTY_STACK(S)){
		S.Top_idx = S.Top_idx->Next;
	}
}

void READ_STACK(Stack &S){
	int n; cin >> n;
	
	MAKENULL_STACK(S);
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		PUSH(x, S);
	}
}

void PRINT_STACK(Stack &S){
	
	while(!EMPTY_STACK(S)){
		cout << S.Top_idx->Elements << " ";
		S.Top_idx=S.Top_idx->Next;
	}
}
//===============================//

void BT18a(Stack& S) {
	
	MAKENULL_STACK(S);
	int n; cin >> n;
	while (n != 0) {
		n = n % 2;
		PUSH(n, S);
		n = n / 2;
	}
	PRINT_STACK(S);
}

//===============================//
int main (){
	Stack S;
	
	BT18a(S);
	
	return 0;
}
