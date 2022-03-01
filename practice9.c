// ---------------

// Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

// Design, Develop and Implement a menu driven Program in C for the following operations on 
// Doubly Linked List (DLL) of Employee Data with the fields: 
// SSN, Name, Dept, Designation, Sal, PhNo

struct node {
    char ssn[25], name[25], dept[10], designation[25];
    int sal;
    long int phone;
    // doubly linked list has 2 pointers -> left node and right node
    struct node *left_link;
    struct node *right_link;
};
typedef struct node *node;

node head = NULL;
int count = 0;

node create() {
    node snode;
    snode = (node)malloc(sizeof(struct node));
    if (snode == NULL) {
        // empty
        printf("\n Linked list empty");
        exit(0);
    }
    // else -> input operations
    printf("\n Enter SSN, Name, Dept, Designation, Salary, Phone number of employee :");
    scanf("%s %s %s %s %d %ld", snode->ssn, snode->name, snode->dept, snode->designation, &snode->sal, &snode->phone);
    // set left and right pointers to null as of now
    snode->left_link = NULL;
    snode->right_link = NULL;
    // count increase -> new node created
    count++;
    return snode;
}

// insert at front
node insertAtFront() {
    node temp;
    temp = create(); // node created, count/size++ done
    if (head == NULL) {
        return temp; // linked list empty
    }
    // else -> right link address points to head (first), and head point to left link (vice versa)
    // easier to draw and imagine
    temp->right_link = head;
    head->left_link = temp;
    return temp;
}

// insert at end
node insertAtEnd() {
    node curr, temp;
    temp = create();
    if (head == NULL) {
        return temp;
    }
    curr = head;
    while (curr->right_link != NULL) {
        // traverse until right link points to null
        curr = curr->right_link;
    }
    // right_link is at end posn, point it to temp.
    curr->right_link = temp;
    temp->left_link = curr; // vice versa
    return head;
}

// delete at front

node deleteAtFront() {
    node temp;
    if (head == NULL) {
        printf("\n Doubly Linked List is empty");
        return NULL;
    }
    // only 1 element / employee
    if (head->right_link == NULL) {
        printf("\n The employee node with ssn %s is deleted", head->ssn); // first one
        free(head);
        count--;
        return NULL;
    }
    // else -> multiple entries (head = head.next trick) (here next = rlink)
    temp = head;  // curr node
    head = head->right_link;
    temp->right_link = NULL; // curr (old / deleted) node points to null (both left and right)
    temp->left_link = NULL;
    printf("\n Employee node with ssn %s is deleted", temp->ssn);
    free(temp);
    count--;
    return head;
}

// delete at end

node deleteAtEnd() {
    node prev, curr;
    if (head == NULL) {
        printf("\n Doubly Linked List is empty");
        return NULL;
    }
    // only 1 element / employee
    if (head->right_link == NULL) {
        printf("\n The employee node with ssn %s is deleted", head->ssn); // first one
        free(head);
        count--;
        return NULL;
    }
    // else -> multiple entries
    prev = NULL;
    curr = head;
    // traverse through LL
    while(curr->right_link != NULL) {
        prev = curr;
        curr = curr->right_link;
    }
    // prev is at last node, prev.next = NULL in this case prev.rlink = NULL
    // and curr->left_link should also be NULL
    curr->left_link = NULL;
    printf("\n Employee node with ssn %s is deleted", curr->ssn);
    free(curr);
    prev->right_link = NULL;
    count--;
    return head;
}

void display() {
    node curr;
    int num = 1; // node number (entry/index)
    curr = head;
    if (curr == NULL) {
        // empty
        printf("\n Linked List is empty!");
    }
    while (curr != NULL) {
        printf("\n | %d | SSN : %s | Name : %s | Dept : %s | | Designation : %s | | Salary : %d | | Phone Number : %ld |", num, curr->ssn, curr->name, curr->dept, curr->designation, curr->sal, curr->phone);
        curr = curr->right_link; // next
        num++; 
    }
    printf("\n Number of employee nodes : %d", count); // count
}

// deque (both front and rear entry)

void deque() {
    int choice;
    while (1) {
        printf("\n 1. Insert Front \n 2. Delete Front \n 3. Insert Rear \n 4. Delete Rear \n 5. Display Status \n 6. Exit");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                head = insertAtFront();
                break;
            case 2:
                head = deleteAtFront();
                break;
            case 3:
                head = insertAtEnd();
                break;

            case 4:
                deleteAtEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                return;
        }
    }
}

int main() {
    int choice, i, n;
    while (1) {
        printf("\n 1: Create DLL of Employee Nodes");
        printf("\n 2: Display status");
        printf("\n 3: Insert at end");
        printf("\n 4: Delete at end");
        printf("\n 5: Insert at front");
        printf("\n 6: Delete at front");
        printf("\n 7: Deque Demo");
        printf("\n 8: Exit");
        printf("\n Please enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n Enter number of employees : ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++) {
                    head = insertAtEnd();
                }
                break;

            case 2:
                display();
                break;

            case 3:
                head = insertAtEnd();
                break;

            case 4:
                head = deleteAtEnd();
                break;

            case 5:
                head = insertAtFront();
                break;

            case 6:
                head = deleteAtFront();

            case 7:
                deque();
                break;

            case 8:
                exit(0);

            default:
                printf("\n Enter valid choice!");
        }
    }
}

// ---------------
