#include <iostream>

using namespace std;

#define MaxLength 100
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Data[MaxLength];
	Position Last;
} SET;

void MAKENULL_SET(SET& a) {
	a.Last = 0;
}

int MEMBER(ElementType& x ,SET& a) {
	for (Position i = 0;i <= a.Last;i++) {
		if (a.Data[i] == x)
			return 1;
	}
	return 0;
}

void INSERT_SET(ElementType& x, SET& a) {
	if (a.Last == MaxLength)
		cout << "Mang day" << endl;
	else if (MEMBER(x, a) == 0) {
		a.Last++;
		a.Data[a.Last - 1] = x;
	}
	else
		cout << "Phan tu da ton tai" << endl;
}

void READ_SET(SET& a) {
	int i, n, x;

	cout << "Nhap so phan tu: "; cin >> n;
	for (i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> x;
		INSERT_SET(x, a);
	}
}

void PRINT_SET(SET& a) {
	int i;

	for (i = 1; i <= a.Last;i++) {
		cout << a.Data[i - 1] << " ";
	}
}

int main() {
	SET a;

	MAKENULL_SET(a);
	READ_SET(a);
	PRINT_SET(a);

	return 0;
}
