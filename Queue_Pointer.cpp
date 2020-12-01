#include<bits/stdc++.h>

using namespace std;

typedef int ElementType;
typedef struct Node {
	ElementType Element;
	Node* Next;
};
typedef Node* Position;
typedef struct {
	Position Front, Rear;
} Queue;

void MAKENULL_QUEUE(Queue& Q) {
	Position Header = new Node;
	Header->Next = NULL;
	Q.Front = Header;
	Q.Rear = Header;
}

ElementType EMPTY_QUEUE(Queue& Q) {
	return (Q.Front == Q.Rear);
}

ElementType TOP(Queue& Q) {
	return Q.Front->Next->Element;
}

void ENQUEUE(ElementType &X, Queue& Q) {
	Q.Rear->Next = new Node;
	Q.Rear = Q.Rear->Next;
	Q.Rear->Element = X;
	Q.Rear->Next = NULL;
}

void DEQUEUE(Queue& Q) {
	if (!EMPTY_QUEUE(Q)) {
		Position T = Q.Front;
		Q.Front = Q.Front->Next;
		free(T);
	}
	else
		cout << "Hang rong" << endl;
}

void READ_QUEUE(Queue& Q) {
	int n; cin >> n;

	MAKENULL_QUEUE(Q);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		ENQUEUE(x, Q);
	}
}

void PRINT_QUEUE(Queue& Q) {
	for (Position i = Q.Front; i <= Q.Rear; i++) {
		cout << TOP(Q) << " ";
		DEQUEUE(Q);
	}
}

int main() {
	Queue Q;

	READ_QUEUE(Q);
	PRINT_QUEUE(Q);

	return 0;
}
