#include <iostream>
#include <string.h>

using namespace std;

struct Node {
	string Data;
	struct Node* pLeft;
	struct Node* pRight;
};
typedef struct Node NODE;
typedef NODE* Tree;

void MAKENULL_TREE(Tree& t) {
	t = NULL;
}

bool EMPTY_TREE(Tree& t){
	return (t == NULL);
}

void INSERT_TREE(Tree& t, string s) {
	if (t == NULL) {
		NODE* p = new NODE;
		p->Data = s;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else {
		if (s.compare(t->Data) == -1)
			INSERT_TREE(t->pLeft, s);
		else if (s.compare(t->Data) == 1)
			INSERT_TREE(t->pRight, s);
	}
}

Tree Search_Tree(Tree& t, string s) {
	if (t == NULL)
		return 0;
	else {
		if (s.compare(t->Data) == -1)
			return Search_Tree(t->pLeft, s);
		else if (s.compare(t->Data) == 1)
			return Search_Tree(t->pRight, s);
		else if (s.compare(t->Data) == 0)
			return t;
	}
}

/*===========NLR===========*/
void PreOrder(Tree& t) {
	if (t != NULL) {
		cout << t->Data << " ";
		PreOrder(t->pLeft);
		PreOrder(t->pRight);
	}
}

/*===========LNR===========*/
void InOrder(Tree& t) {
	if (t != NULL) {
		InOrder(t->pLeft);
		cout << t->Data << " ";
		InOrder(t->pRight);
	}
}

/*===========LRN===========*/
void PosOrder(Tree& t) {
	if (t != NULL) {
		PosOrder(t->pLeft);
		PosOrder(t->pRight);
		cout << t->Data << " ";
	}
}

/*===========DeleteNode===========*/
void Temp_Node(Tree& X, Tree& Y) {
	if (Y->pRight != NULL) {
		Temp_Node(X, Y->pRight);
	}
	else {
		X->Data = Y->Data;
		X = Y;
		Y = Y->pLeft;
	}
}

void BT12(Tree& t, string& s) {
	if (t == NULL)
		return;
	else {
		if (s.compare(t->Data) == 1)
			BT12(t->pRight, s);
		else if (s.compare(t->Data) == -1)
			BT12(t->pLeft, s);
		else {
			NODE* tmp = t;
			if (t->pRight == NULL)
				t = t->pLeft;
			else if (t->pLeft == NULL)
				t = t->pRight;
			else {
				Temp_Node(tmp, t->pLeft);
			}
			delete tmp;
		}
	}
}


/*===========DONGTHAP===========*/
void BT13(Tree &t, string city){
	if (Search_Tree(t, city) == false)
		return;
	if (EMPTY_TREE(t) == true){
		return;
	}
	cout << t->Data << endl;
	if (city.compare(t->Data) == 0){
		return;
	}
	else if (city.compare(t->Data) == 1){
		BT13(t->pRight, city);
	}
	else if (city.compare(t->Data) == -1){
		BT13(t->pLeft, city);
	}
}

void MOTHERBASE(Tree& t) {
	MAKENULL_TREE(t);
	while (true) {
		system("cls");
		cout << "Press 1 = Insert data\n";
		cout << "Press 2 = Print tree\n";
		cout << "Press 3 = Delete node\n";
		cout << "Press 4 = Search tree\n";
		cout << "Press 5 = DONGTHAP\n";
		cout << "Press 0 = Exit\n";
		int choice; cin >> choice;
		if (choice < 0 || choice > 8) {
			cout << "Wrong choice\n";
			system("pause");
		}
		else if (choice == 1) {
			string s;
			cout << "Insert a string: ";
			cin >> s;
			INSERT_TREE(t, s);
		}
		else if (choice == 2) {
			cout << "Press 1 = Print by PreOrder\n";
			cout << "Press 2 = Print by InOrder\n";
			cout << "Press 3 = Print by PosOrder\n";
			int choice2; cin >> choice2;
			if (choice2 == 1) {
				PreOrder(t);
				system("pause");
			}
			else if (choice2 == 2) {
				InOrder(t);
				system("pause");
			}
			else {
				PosOrder(t);
				system("pause");
			}
		}
		else if (choice == 3) {
			string s;
			cout << "Enter a string: ";
			cin >> s;
			BT12(t, s);
		}
		else if (choice == 4) {
			string s;
			cout << "Enter a string: ";
			cin >> s;
			cout << Search_Tree(t, s) << endl;
			system("pause");
		}
		else if (choice == 5) {
			string s;
			s = "DONGTHAP";
			BT13(t, s);
			system("pause");
		}
		else
			break;
	}
}

int main() {
	Tree t;

	MOTHERBASE(t);

	return 0;
}
