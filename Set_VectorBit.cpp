#include <iostream>

using namespace std;

#define maxlength 10
typedef int SET[maxlength];

void MAKENULL_SET(SET& a) {
	int i;
	for (i = 0; i < maxlength; i++)
		a[i] = 0;
}

void UNION(SET& a, SET& b, SET& c) {
	int i;

	for (i = 0; i < maxlength; i++)
		c[i] = ((a[i] == 1) || (b[i] == 1));
}

void INTERSECTION(SET& a, SET& b, SET& c) {
	int i;

	for (i = 0; i < maxlength; i++)
		c[i] = ((a[i] == 1) && (b[i] == 1));
}

void DIFFERENCE(SET& a, SET& b, SET& c) {
	int i;

	for (i = 0; i < maxlength; i++)
		c[i] = ((a[i] == 1) && (b[i] == 0));
}

bool MEMBER(int x, SET& a) {
	int i;

	for (i = 0; i < maxlength; i++) {
		if (a[i] == x) {
			return true;
			break;
		}
	}
	return false;
}

void INSERT_SET(int x, SET& a) {
	int i, n;

	MAKENULL_SET(a);
	cout << "Nhap so phan tu: ";
	cin >> n;
	for (i = 0; i < n; i++) {
		cout << "Nhap vi tri phan tu thu " << i + 1 <<": ";
		cin >> x;
		a[x - 1] = 1;
	}
}

void PRINT_SET(SET& a) {
	int i;

	for (i = 0; i < maxlength; i++) {
		cout << a[i] << " ";
	}
	cout << endl << endl;
}

int main() {
	SET a, b, c;
	int x{};

	INSERT_SET(x, a);
	PRINT_SET(a);
	INSERT_SET(x, b);
	PRINT_SET(b);
	
	cout << "Hop cua 2 tap hop: ";
	UNION(a, b, c);
	PRINT_SET(c);
	
	cout << "Tap hop a hieu b: ";
	DIFFERENCE(a, b, c);
	PRINT_SET(c);

	cout << "Giao cua 2 tap hop: ";
	INTERSECTION(a, b, c);
	PRINT_SET(c);

	return 0;
}

