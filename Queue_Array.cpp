#include<iostream>
#define MaxLength 100

using namespace std;
typedef string ElementType;
typedef struct {
	ElementType Elements[MaxLength];
	int Front, Rear;
} Queue;

void MAKENULL_QUEUE(Queue& Q) {
	Q.Front = -1;
	Q.Rear = -1;
}

int EMPTY_QUEUE(Queue& Q) {
	return (Q.Front == -1);
}

ElementType TOP(Queue& Q) {
	return Q.Elements[Q.Front];
}

int FULL_QUEUE(Queue& Q) {
	return (Q.Rear - Q.Front + 1 == MaxLength);
}

void DEQUEUE(Queue& Q) {
	if (!EMPTY_QUEUE(Q)) {
		Q.Front = Q.Front + 1;
		if (Q.Front > Q.Rear) {
			MAKENULL_QUEUE(Q);
		}
	}
	else
		cout << "Empty queue" << endl;
}

void ENQUEUE(ElementType& X, Queue& Q) {
	if (!FULL_QUEUE(Q)) {
		if (EMPTY_QUEUE(Q))
			Q.Front = 0;
		if (Q.Rear == MaxLength - 1) {
			for (int i = Q.Front; i <= Q.Rear; i++)
				Q.Elements[i - Q.Front] = Q.Elements[i];
			Q.Rear = MaxLength - Q.Front - 1;
			Q.Front = 0;
		}
		Q.Rear = Q.Rear + 1;
		Q.Elements[Q.Rear] = X;
	}
	else
		cout << "Full queue" << endl;
}

void READ_QUEUE(Queue& Q) {
	int n; 
	cout << "Enter the amount of numbers: ";
	cin >> n;

	MAKENULL_QUEUE(Q);
	for (int i = 1; i <= n; i++) {
		string x; 
		cout << "Enter a number: ";
		cin >> x;
		ENQUEUE(x, Q);
	}
}

void PRINT_QUEUE(Queue& Q) {
	cout << "Your queue: ";
	for (int i = Q.Front; i <= Q.Rear; i++) {
		cout << TOP(Q) << " ";
		DEQUEUE(Q);
	}
}

//==============================//

void BT19(){
    char input[100], output[100];
    
    cout << "Enter input file name: "; cin >> input;
    cout << "Enter output file name: "; cin >> output;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
    Queue Q; MAKENULL_QUEUE(Q);
    while (true) {
    	string s;
        getline(cin, s);
        if (s == "\0")
        	break;
        ENQUEUE(s, Q);
    }
    while (!EMPTY_QUEUE(Q)){
        cout << TOP(Q) << "\n";
        DEQUEUE(Q);
    }
}

//==============================//

int main() {
	Queue Q;

	BT19();

	return 0;
}
