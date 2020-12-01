#include <iostream>
using namespace std;

#define B 11
#define Empty "**********"
#define Deleted "++++++++++"
typedef string ElementType;
typedef ElementType Dictionary[B];

int h(ElementType& x) {
	int i, sum = 0;

	for (i = 0;i < x.size();i++) {
		sum = sum + x[i];
	}
	return sum % B;
}

void MAKENULL_SET(Dictionary& D) {
	for (int i = 0; i < B; i++) {
		D[i] = Empty;
	}
}

int LOCATE(ElementType& x, Dictionary& D) {
	int i = 0;

	while ((i < B) && (D[(h(x) + i) % B] != x) && (D[(h(x) + i) % B] != Empty)) {
		i++;
	}
	return (h(x) + i) % B;
}

int LOCATE1(ElementType& x, Dictionary& D) {
	int i = 0;

	while ((i < B) && (D[(h(x) + i) % B] != x) && (D[(h(x) + i) % B] != Empty) && (D[(h(x) + i) % B] != Deleted)) {
		i++;
	}
	return (h(x) + i) % B;
}

int MEMBER(ElementType& x, Dictionary& D) {
	return (D[LOCATE(x, D)] == x);
}

void INSERT_SET(ElementType& x, Dictionary& D) {
	int bucket;

	if (D[LOCATE(x, D)] != x) {
		bucket = LOCATE1(x, D);
		if (D[bucket] == Empty || D[bucket] == Deleted)
			D[bucket] = x;
	}
	else
		cout << "Tap hop day" << endl;
}

void DELETE_SET(ElementType& x, Dictionary& D) {
	int bucket;
	bucket = LOCATE(x, D);
	if (D[bucket] == x)
		D[bucket] = Deleted;
}

void READ_SET(Dictionary& D) {
	int i, n;
	ElementType x;

	MAKENULL_SET(D);
	cout << "Nhap so phan tu cua tap hop: ";
	cin >> n;
	for (i = 0;i < n;i++) {
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> x;
		INSERT_SET(x, D);
	}
}

void PRINT_SET(Dictionary& D) {
	int i;

	for (i = 0; i < B; i++) {
		cout << D[i] << endl;
	}
}

int main() {
	Dictionary D;

	READ_SET(D);
	PRINT_SET(D);

	return 0;
}
