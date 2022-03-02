// BST -> traverse inorder preorder postorder, search bst for given key, exit, create.

#include <stdio.h>
#include <stdlib.h>

struct BST {
	int data;
	struct BST *lchild;
	struct BST *rchild;
};
typedef struct BST *node;

node create() {
	node temp;
	temp = (node)malloc(sizeof(struct BST));
	printf("Enter value : \n");
	scanf("%d", &temp->data);
	temp->lchild = NULL;
	temp->rchild = NULL;
	return temp;
}

void insert(node root, node newnode) {
	if (newnode->data < root->data) {
		if (root->lchild == NULL) {
			root->lchild = newnode;
		}
		insert(root->lchild, newnode);
	}
	if (newnode->data > root->data) {
		if (root->rchild == NULL){
			root->rchild = newnode;
		}
		insert(root->rchild, newnode);
	}
}

void search(node root) {
	int key;
	node curr;
	if (root == NULL) {
		printf("BST Empty\n");
		return;
	}
	printf("Enter element to search : \n");
	scanf("%d", &key);
	curr = root; // curr = head
	while (curr != NULL) {
		if (curr->data == key) {
			printf("Found!\n");
			return;
		}
		if (key < curr->data) {
			curr = curr->lchild;
		} 
		else {
			curr = curr->rchild;
		}
	}
	printf("Key not found\n");
}

void inorder(node root) { // l n r
	if (root != NULL) { 
		inorder(root->lchild);
		printf("%d \n", root->data);
		inorder(root->rchild);
	}
}

void preorder(node root) { // n l r
	if (root != NULL) { 
		printf("%d \n", root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void postorder(node root) { // l r n
	if (root != NULL) { 
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d \n", root->data);
	}
}

int main() {
	int choice, key, value, i, n;
	node root = NULL, newnode;
	while (1) {
		printf("\n 1. Create BST");
        printf("\n 2. Search");
        printf("\n 3. BST traversals");
        printf("\n 4. Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
        	case 1:
        		printf("Enter number of elements : \n");
        		scanf("%d", &n);
        		for (i = 1; i <= n; i++) {
        			newnode = create();
        			if (root == NULL) {
        				root = newnode;
        			}
        			insert(root, newnode);
        		}
        		break;
        	case 2:
	        	search(root);
	        	break;
        	case 3:
        		if (root == NULL) {
        			printf("Tree empty\n");
        		}
        		else {
	        		printf("Preoreder : \n");
	        		preorder(root);
	        		printf("Inorder : \n");
	        		inorder(root);
	        		printf("Postorder : \n");
	        		postorder(root);
        		}
        		break;
        	case 4:
        		exit(0);
        	default:
        		break;
        }
	}
}








