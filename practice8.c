// ---------------

// Linked List -> USN, Name, Branch, Sem, PhNo
// insertAtFront(), insertAtEnd(), deleteAtFront(), deleteAtEnd(), status of LL and count number of nodes in it.

#include <stdio.h>
#include <stdlib.h>

// node
struct node {
    char usn[25], name[25], branch[25];
    int sem;
    long int phone;
    struct node *nxt; // next pointer
};

typedef struct node *node; // now we just have to mention node

// initially
node head = NULL;
int count = 0;

// creating node
node create() {
    node snode;
    snode = (node)malloc(sizeof(struct node));

    if (snode == NULL) {
        // empty
        printf("\n Linked list is empty");
        exit(1);
    }
    // else -> input data (usn, name, branch, sem, phone number)
    printf("\n Enter USN, Name, Branch, SEM, Phone Number of student : ");
    scanf("%s %s %s %d %ld", snode->usn, snode->name, snode->branch, &snode->sem, &snode->phone);
    snode->nxt = NULL; // nxt pointer points to null as of now (since only 1 element)
    count++; // from 0 -> 1
    return snode;
}

// insert at front
node insertAtFront() {
    node temp;
    temp = create(); // temp node created, count/size++ done
    if (head == NULL) {
        // empty
        return temp; // return head
    }
    // insert at front = move head to next (temp node created, it points to head (if it wants to be the first element))
    temp->nxt = head; // head = temp, return head
    return temp;
}

// insert at end
node insertAtEnd() {
    node curr, temp;
    temp = create(); // temp node created
    if (head == NULL) {
        // empty
        return temp; // head
    }
    // else
    curr = head; // start point
    // traverse through the linked list and go to the end 
    while (curr -> nxt != NULL) {
        curr = curr->nxt; // iterate
    }
    // reached last pointer
    curr->nxt = temp; // last element points to temp (new last element)
    return head; // return LL
}

// delete at front
// [HEAD] 10 (2k) -> 20 (3k) -> 30 (NULL) [TAIL]
// [HEAD] 20 (3k) -> 30 (NULL) [TAIl]

// shift head to head.next

node deleteAtFront() {
    node temp;
    if (head == NULL) {
        // empty
        printf("\n Linked list is empty");
        return NULL;
    }
    // if only 1 element
    if (head->nxt == NULL) {
        printf("\n Student node with usn : %s is deleted", head->usn);
        // decrement size of LL
        count--; 
        free(head);
        return NULL;
    }
    // else -> more than 1 element
    temp = head; // temp
    head = head->nxt; // main logic
    printf("\n Student node with usn : %s is deleted", temp->usn); // current
    count--;
    free(temp);
    return head; // pretty easy explaination if you think about it visually
}

// delete at end -> you go to last element and point it to null .
// if more than 1 element in linked list. (first size--)
/*
    [HEAD] 10 (2k) -> 20 (3k) -> 30 (NULL) [TAIL]
    Removing element? Make 3k = NULL, and shift TAIL to 20.
    Now address of 30 (last (3k) = removed) 
    New tail = Node having value 20.
*/

node deleteAtEnd() {
    node curr, prev;
    if (head == NULL) {
        // empty
        printf("\n Linked list is empty!");
        return NULL;
    }
    // if only 1 element
    if (head->nxt == NULL) {
        printf("\n Student node with usn : %s is deleted", head->usn);
        free(head);
        count--;
        return NULL;
    }
    // else -> more than 1 element
    prev = NULL;
    curr = head;
    // go to last element
    while (curr->nxt != NULL) {
        prev = curr; // store current value of curr in prev and go to the end
        curr = curr->nxt;
    }
    // now prev has last node value, just do prev.address = NULL to delete last node
    printf("\n Student node with usn %s is deleted", curr->usn); // last element
    free(curr);
    prev->nxt = NULL;
    count--;
    return head;
}

// display
void display() {
    node curr;
    int num = 1; // index (1. 2. 3.) -> number of entries
    if (head == NULL) {
        printf("\n Linked list is empty!");
        return;
    }
    // else -> contents
    printf("\n Contents of Linked List : ");
    curr = head;
    // traverse
    while (curr != NULL) {
        printf("\n |%d| |USN: %s| | Name:%s | | Branch:%s | | Sem:%d | | Ph:%ld |", num, curr->usn, curr->name, curr->branch, curr->sem, curr->phone);
        curr = curr->nxt; // iterate to next 
        num++;
    }
    printf("\n Number of student nodes : %d", count);
}

// stack demo (FIFO)
void stack() {
    int choice;
    while (1) {
        printf("\n 1. Push operation \n 2. Pop operation \n 3. Display \n 4. Exit");
        printf("\n Enter choice for stack demo :");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertAtFront();
                break;
            case 2:
                head = deleteAtFront();
            case 3:
                display();
                break;
            default:
            return;
        }
    }
}

int main() {
    int choice, i, n;
    while (1) {
        printf("\n Enter choice for Linked List operations! \n");
        printf("\n 1. Create linked list of student nodes");
        printf("\n 2. Display Status");
        printf("\n 3. Insert at end");
        printf("\n 4. Delete at end");
        printf("\n 5. Stack demo");
        printf("\n 6. Exit \n");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n Enter number of students : ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++){
                    head = insertAtFront();
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
                stack();
                break;

            case 6:
                exit(0);

            default:
                printf("\n Enter valid choice!");
        }
    }
    return 0;
}

// ---------------