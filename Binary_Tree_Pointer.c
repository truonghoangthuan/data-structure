#include <stdio.h>

typedef char Data;
typedef struct NODE* Node; 
struct NODE {
		Data data;
    	Node left, right;
};
typedef Node Tree;

void MakeNullTree(Tree *T) { 
	(*T) = NULL; 
}

Tree LeftChild(Tree n) {
	if (n != NULL) 
		return n -> left;
	else 
		return NULL; 
} 

Tree RightChild(Tree n) {
 	if (n!=NULL) 
	 	return n -> right;
 	else 
	 	return NULL;
}

void PreOrder(Tree T) {
  if (T!= NULL) {
  	printf("%c ",T -> data);  
   	PreOrder(LeftChild(T));
    PreOrder(RightChild(T));
  }
}

void InOrder(Tree T) {
  if (T != NULL) {
   	InOrder(LeftChild(T));
  	printf("%c ",T->data);  
    InOrder(RightChild(T));
  }
}

void PostOrder(Tree T) {
  if (T != NULL) {
   	PostOrder(LeftChild(T));
    PostOrder(RightChild(T));
  	printf("%c ",T -> data);  
  }
}

Tree Create2(Data v, Tree L, Tree R) {
	Tree N;
	N = (Node)malloc(sizeof(struct NODE));
	N -> data = v;
	N -> left = L;
	N -> right = R;
	return N; 
}

int main () {
	Tree T;
	
/*

           A
          /  \
		 B    C
        / \  / \  
       D  E F   G 
           / \   \ 
          I   J   K 			  
*/
	T = Create2('A',
			Create2('B', 
				Create2('D',NULL, NULL), 
				Create2('E',NULL, NULL)
			),
			Create2('C',
				Create2('F', 
					Create2('I', NULL, NULL),
					Create2('J', NULL, NULL)
				),
				Create2('G', 
					NULL,
					Create2('K', NULL, NULL)
				)
			)		
		);
	printf("Duyet tien tu: ");
	PreOrder(T);
	printf("\nDuyet trung tu: ");
	InOrder(T); 
	printf("\nDuyet hau tu: ");
	PostOrder(T);	
	
	return 0;
}
