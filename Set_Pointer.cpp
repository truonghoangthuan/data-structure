#include <iostream>

using namespace std;

typedef int ElementType;
typedef struct Cell {
	ElementType Element;
	Cell* next;
};
typedef Cell* SET;
typedef SET Set;

void MAKENULL_SET(Set& a) {
	a = new Cell;
	a->next = NULL;
}

int MEMBER(ElementType X, Set& a) {
	Set P;
	P = a->next;
	while (P != NULL) {
		if (P->Element == X)
			return 1;
		else
			P = P->next;
	}
	return 0;
}

void INTERSECTION(Set& Aheader, Set& Bheader, Set& C) {
	Set Acurrent, Bcurrent, Ccurrent;
	C = new Cell;
	Acurrent = Aheader->next;
	Bcurrent = Bheader->next;
	Ccurrent = C;
	while ((Acurrent != NULL) && (Bcurrent != NULL)) {
		if (Acurrent->Element == Bcurrent->Element) {
			Ccurrent->next = new Cell;
			Ccurrent = Ccurrent->next;
			Ccurrent->Element = Acurrent->Element;
			Acurrent = Acurrent->next;
			Bcurrent = Bcurrent->next;
		}
		else if (Acurrent->Element < Bcurrent->Element)
			Acurrent = Acurrent->next;
		else
			Bcurrent = Bcurrent->next;
	}
	Ccurrent->next = NULL;
}

void UNION(Set& Aheader, Set& Bheader, Set& C) {
	Set Acurrent, Bcurrent, Ccurrent;
	C = new Cell;
	Acurrent = Aheader->next;
	Bcurrent = Bheader->next;
	Ccurrent = C;
	while ((Acurrent != NULL) && (Bcurrent != NULL)) {
		if (Acurrent->Element == Bcurrent->Element) {
			Ccurrent->next = new Cell;
			Ccurrent = Ccurrent->next;
			Ccurrent->Element = Acurrent->Element;
			Acurrent = Acurrent->next;
			Bcurrent = Bcurrent->next;
		}
		else if (Acurrent->Element < Bcurrent->Element)
			Acurrent = Acurrent->next;
		else
			Bcurrent = Bcurrent->next;
	}
	Ccurrent->next = NULL;
}

void INSERT_SET(ElementType X, Set& a) {
	Set T, P;
	P = a;
	while (P->next != NULL)
		if (P->next->Element <= X)
			P = P->next;
		else
			break;
	if ((P->next == NULL) || (P->next != NULL) && (P->next->Element != X)) {
		T = new Cell;
		T->Element = X;
		T->next = P->next;
		P->next = T;
	}
}

void DELETE_SET(ElementType X, Set& a) {
	Set T, P;
	P = a;
	while (P->next != NULL)
		if (P->next->Element < X)
			P = P->next;
		else
			break;
	if (P->next != NULL)
		if (P->next->Element == X) {
			T = P->next;
			P->next = T->next;
			delete(T);
		}
}

void PRINT_SET(Set& a) {
	for (Set i = a->next; i != NULL; i = i->next) {
			cout << i->Element << " ";
	}
}

void READ_SET(Set& a) {
	int x, n, i;

	cout << "Nhap so phan tu tap hop: ";
	cin >> n;
	MAKENULL_SET(a);
	for (i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> x;
		INSERT_SET(x, a);
	}
}

int main() {
	Set a;

	MAKENULL_SET(a);
	READ_SET(a);
	PRINT_SET(a);

	return 0;
}
