// ---------------

/*
11. Design, Develop and Implement a menu driven Program in C for BST
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
b. Traverse the BST in Inorder, Preorder and Post Order
c. Search the BST for a given element (KEY) and report the appropriate message
d. Exit
*/

#include <stdio.h>
#include <stdlib.h>

struct BST {
    // 3 parameters -> data, left child, right child
    int data;
    struct BST *lchild;
    struct BST *rchild;
};
typedef struct BST *node;

node create() {
    node temp;
    temp = (node)malloc(sizeof(struct BST));
    printf("\n Enter value : ");
    scanf("%d", &temp->data); // data -> value
    // initially left and right child -> null
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

// insert

// root -> root node, newnode -> new node
// if new node value < root value -> goes to left half (root->leftchild = newnode)
// if new node value > root value -> goes to right half (root->rightchild = newnode)
void insert(node root, node newnode) {
    // left part
    if (newnode->data < root->data) {
        // if empty
        if (root->lchild == NULL) {
            // insert
            root->lchild = newnode;
        }
        // if elements already there -> use recursion to insert
        insert(root->lchild, newnode);
    }

    // right part
    if (newnode->data > root->data) {
        // if empty
        if (root->rchild == NULL) {
            // insert
            root->rchild = newnode;
        }
        // else elements already there -> use recursion to insert
        insert(root->rchild, newnode);
    }
}

// searching

void search(node root) {
    int key;
    node curr;
    if (root == NULL) {
        // empty BST
        printf("\n BST is empty");
        return;
    }
    // if bst not empty
    printf("\n Enter element to be searched : ");
    scanf("%d", &key);
    curr = root; // head
    // traverse over BST
    while (curr != NULL) {
        // found
        if (curr->data == key) {
            printf("\n Key element is present in BST");
            return;
        }
        // if left half
        if (key < curr->data) {
            // check for left side
            curr = curr->lchild;
        }
        else {
            // check for right side
            curr = curr->rchild;
        }
    }
    // if none works
    printf("\n Key element is not found in BST");
}

// inorder -> Left -> Node -> Right (inorder(leftchild), root->data, inordere(rightchild))

void inorder(node root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

// preorder -> Node -> Left -> Right (root->data, preorder(lchild), preorder(rchild))

void preorder(node root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

// postorder -> Left -> Right -> Node (postorder(lchild), postorder(rchild), root-data))

void postorder(node root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}

int main() {
    int choice, key, value, i, n;
    node root = NULL, newnode; // initalise
    while (1) {
        printf("\n 1. Create BST");
        printf("\n 2. Search");
        printf("\n 3. BST traversals");
        printf("\n 4. Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("\n Enter number of elements : ");
            scanf("%d", &n);
            for (i = 1; i <= n; i++) {
                // create new node
                newnode = create();
                if (root == NULL) { // tree is empty -> push value of newnode as the root node.
                    root = newnode;
                }
                // else tree is not empty -> insert newnode in root
                insert(root, newnode);
            }
            break;

        case 2:
            search(root);
            break;

        case 3:
            if( root == NULL) {
                printf("\n Tree is not created"); // empty
            }
            else {
                printf("\n Preorder display : ");
                preorder(root);
                printf("\n Inorder display : ");
                inorder(root);
                printf("\n Postorder display : ");
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

// ---------------
