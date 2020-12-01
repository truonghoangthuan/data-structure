#include <iostream>
using namespace std;

#define B 5
typedef int ElementType;
typedef struct Node {
	ElementType Data;
	Node* Next;
};
typedef Node* Position;
typedef Position Dictionary[B];

int h(ElementType& x) {
	return x % B;
}

void MAKENULL_SET(Dictionary& D) {
	for (int i = 0;i < B;i++) {
		D[i] = NULL;
	}
}

int MEMBER(ElementType& x, Dictionary& D) {
	Position P = D[h(x)];
	while (P != NULL) {
		if (P->Data == x)
			return 1;
		else
			P = P->Next;
	}
}

void INSERT_SET(ElementType& x, Dictionary& D) {
	Position P;
	int Bucket;

	if (!MEMBER(x, D)) {
		Bucket = h(x);
		P = D[Bucket];
		D[Bucket] = new Node;
		D[Bucket]->Data = x;
		D[Bucket]->Next = P;
	}
}

void DELETE_SET(ElementType& x, Dictionary& D) {
	Position P, tmp;
	int Bucket=h(x);

	if (D[Bucket] != NULL) {
		if (D[Bucket]->Data == x) {
			tmp = D[Bucket];
			D[Bucket] = D[Bucket]->Next;
			free(tmp);
		}
	}
	else {
		P = D[Bucket];
		while (P->Next != NULL) {
			if (P->Next->Data == x) {
				break;
			}
			else
				P = P->Next;
		}
		if (P->Next != NULL) {
			tmp = P->Next;
			P->Next = tmp->Next;
			free(tmp);
		}
	}
}

void READ_SET(Dictionary& D) {
	int i, n;
	ElementType x;

	MAKENULL_SET(D);
	cout << "Nhap so phan tu cua tap hop: ";
	cin >> n;
	for (i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> x;
		INSERT_SET(x, D);
	}
}

void PRINT_SET(Dictionary& D) {
	int i;

	for (i = 0; i < B; i++) {
		Position P = D[i];
		cout << "Phan tu thu " << i+1 << ": ";
		while (P != NULL) {
			cout << P->Data << " ";
			P = P->Next;
		}
		cout << endl;
	}
}

int main() {
	Dictionary D;
	ElementType x;

	READ_SET(D);
	cout << "\nTap hop cua ban la:" << endl;
	PRINT_SET(D);
	cout << "\nNhap phan tu can xoa: ";
	cin >> x;
	if (MEMBER(x, D) == 1) {
		DELETE_SET(x, D);
		PRINT_SET(D);
	}
	else
		cout << "Phan tu khong ton tai!" << endl;

	return 0;
}
