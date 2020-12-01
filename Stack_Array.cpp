#include<bits/stdc++.h>
#define MaxLength 100

using namespace std;
typedef int ElementType;
typedef struct {
	ElementType Elements[MaxLength];
	int Top_idx;
} Stack;

void MAKENULL_STACK(Stack& S) {
	S.Top_idx = MaxLength;
}

int EMPTY_STACK(Stack& S) {
	return S.Top_idx == MaxLength;
}

int FULL_STACK(Stack& S) {
	return S.Top_idx == 0;
}

int TOP(Stack& S) {
	if (!EMPTY_STACK(S)) {
		return S.Elements[S.Top_idx];
	}
	else
		cout << "Empty stack";
}

void POP(Stack& S) {
	if (!EMPTY_STACK(S)) {
		S.Top_idx = S.Top_idx + 1;
	}
	else
		cout << "Empty stack" << endl;
}

void PUSH(ElementType &X, Stack& S) {
	if (FULL_STACK(S)) {
		cout << "Full stack" << endl;
	}
	else {
		S.Top_idx = S.Top_idx - 1;
		S.Elements[S.Top_idx] = X;
	}
}

void READ_STACK(Stack& S) {
	int n; 
	cout << "Enter the amount of number: ";
	cin >> n;

	MAKENULL_STACK(S);
	for (int i = 0; i < n; i++) {
		int x; 
		cout << "Enter a number: ";
		cin >> x;
		PUSH(x, S);
	}
}

void PRINT_STACK(Stack& S) {
	cout << "Your stack: " << endl;
	while (!EMPTY_STACK(S)) {
		cout << TOP(S) << " " << endl;
		POP(S);
	}
} 
//=======================//

void BT1c(Stack &S) {
	READ_STACK(S);
	PRINT_STACK(S);
}

void BT18a(Stack& S) {
	MAKENULL_STACK(S);
	int n; cin >> n;
	while (n != 0) {
		n = n % 2;
		PUSH(n, S);
		n = n /2;
	}
	PRINT_STACK(S);
}

//=======================//
int main() {
	Stack S;
	
	BT1c(S);

	return 0;
}
