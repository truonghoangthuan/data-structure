#include <iostream>

using namespace std;

struct Node {
	int Data;
	struct Node* pLeft;
	struct Node* pRight;
};
typedef struct Node NODE;
typedef NODE* Tree;

void MAKENULL_TREE(Tree& t) {
	t = NULL;
}

void INSERT_TREE(Tree& t, int x) {
	if (t == NULL) {
		NODE* p = new NODE;
		p->Data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else {
		if (t->Data > x)
			INSERT_TREE(t->pLeft, x);
		else
			INSERT_TREE(t->pRight, x);
	}
}

Tree Search_Tree(Tree& t, int x) {
	if (t == NULL)
		return 0;
	else {
		if (t->Data > x)
			Search_Tree(t->pLeft, x);
		else if (t->Data < x)
			Search_Tree(t->pRight, x);
		else
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

/*===========isSibling===========*/
void SWAP(int& m, int& n) {
	int tmp;
	tmp = m;
	m = n;
	n = tmp;
}

bool BT8a(Tree& t, int m, int n) {
	if (t == NULL || t->Data == m || t->Data == n)
		return false;
	else if (t->pLeft->Data == m && t->pRight->Data == n)
		return true;
	else {
		if (t->Data > m)
			return BT8a(t->pLeft, m, n);
		else if (t->Data < m)
			return BT8a(t->pRight, m, n);	
	}	
}

/*===========isAncestor===========*/
bool BT8b(Tree& t, int m, int n) {
	if (t->Data > m)
		BT8b(t->pLeft, m, n);
	else if (t->Data < m)
		BT8b(t->pRight, m, n);
	else {
		NODE* p = t;
		if (Search_Tree(p, n) == t->pLeft || Search_Tree(p, n) == t->pRight)
			return true;
		else
			return false;
	}	
}

/*===========OnlyOneLeaf===========*/
void BT8c(Tree& t) {
	if (t != NULL) {
		if (t->pLeft == NULL && t->pRight != NULL || t->pLeft != NULL && t->pRight == NULL) {
			cout << t->Data << " ";
		}
		BT8c(t->pLeft);
		BT8c(t->pRight);
	}
}

/*===========CountLeaves===========*/
void BT8d(Tree& t, int& cnt) {
	if (t != NULL) {
		if (t->pLeft == NULL && t->pRight == NULL) {
			cnt = cnt + 1;
		}
		BT8d(t->pLeft, cnt);
		BT8d(t->pRight, cnt);
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

void BT12(Tree& t, int& x) {
	if (t == NULL)
		return;
	else {
		if (t->Data < x)
			BT12(t->pRight, x);
		else if (t->Data > x)
			BT12(t->pLeft, x);
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

void MOTHERBASE(Tree& t) {
	MAKENULL_TREE(t);
	while (true) {
		system("cls");
		cout << "Press 1 = Insert data\n";
		cout << "Press 2 = Print tree\n";
		cout << "Press 3 = Count leaves\n";
		cout << "Press 4 = Node with one leaf\n";
		cout << "Press 5 = Delete node\n";
		cout << "Press 6 = Search tree\n";
		cout << "Press 7 = Is sibling or not\n";
		cout << "Press 8 = Is ancestor or not\n";
		cout << "Press 0 = Exit\n";
		int choice; cin >> choice;
		if (choice < 0 || choice > 8) {
			cout << "Wrong choice\n";
			system("pause");
		}
		else if (choice == 1) {
			int x;
			cout << "Insert a number: ";
			cin >> x;
			INSERT_TREE(t, x);
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
			int cnt = 0;
			BT8d(t, cnt);
			cout << cnt << " ";
			system("pause");
		}
		else if (choice == 4) {
			BT8c(t);
			system("pause");
		}
		else if (choice == 5) {
			int x;
			cout << "Choose a number: ";
			cin >> x;
			BT12(t, x);
		}
		else if (choice == 6) {
			int x;
			cout << "Choose a number: ";
			cin >> x;
			cout << Search_Tree(t, x) << endl;
			system("pause");
		}
		else if (choice == 7) {
			int n, m;
			cout << "Choose a number: ";
			cin >> m;
			cout << "Choose another number: ";
			cin >> n;
			if (m > n)
				SWAP(m, n);
			if (BT8a(t, m, n) == true)
				cout << "True" << endl;
			else
				cout << "False" << endl;
			system("pause");
		}
		else if (choice == 8) {
			int n, m;
			cout << "Choose a number: ";
			cin >> m;
			cout << "Choose another number: ";
			cin >> n;
			if (BT8b(t, m, n) == true)
				cout << "True" << endl;
			else
				cout << "False" << endl;
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
