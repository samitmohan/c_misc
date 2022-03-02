// Linked List -> USN, name, branch, sem, phone number
// insertfront, insertend, deletefront, deleteend, status, count number of nodes in it.

#include <stdio.h>
#include <stdlib.h>

struct node {
	char usn[20], name[20], branch[20];
	int sem;
	long int phone;
	struct node *nxt;
};
typedef struct node *node;
node head = NULL;
int count = 0;

node create() {
	node snode;
	snode = (node)malloc(sizeof(node));
	if (snode == NULL) {
		printf("No memory\n");
		exit(1);
	}
	printf("Enter usn, name, branch, sem and phone number : \n");
	scanf("%s %s %s %d %ld", snode->usn, snode->name, snode->branch, &snode->sem, &snode->phone);
	snode->nxt = NULL;
	count++;
	return snode;
}


node insertFront() {
	node temp;
	temp = create();
	if (head == NULL) {
		return temp;
	}
	temp->nxt = head;
	return temp;
}

node insertEnd() {
	node curr, temp;
	temp = create();
	if (head == NULL) {
		return temp;
	}
	curr = head;
	while (curr->nxt != NULL) {
		curr = curr->nxt;
	}
	curr->nxt = temp;
	return head;
}

node deleteFront() {
	node temp;
	if (head == NULL) {
		printf("Linked list is empty\n");
		return NULL;
	}
	if (head->nxt == NULL) {
		printf("Student node with %s usn is deleted\n", head->usn);
		count--;
		free(head);
		return NULL;
	}
	temp = head;
	head = head->nxt;
	printf("Student node with %s is deleted\n", temp->usn);
	count--;
	free(temp);
	return head;
}


node deleteEnd() {
	node curr, prev;
	if (head == NULL) {
		printf("Linked list is empty\n");
		return NULL;
	}
	if (head->nxt == NULL) {
		printf("Student node with %s usn is deleted\n", head->usn);
		count--;
		free(head);
		return NULL;
	}
	prev = NULL;
	curr = head;
	while (curr->nxt != NULL) {
		prev = curr;
		curr = curr->nxt;
	}
	printf("Student node with %s usn is deleted\n", curr->usn);
	free(curr);
	prev->nxt = NULL;
	count--;
	return head;
}

void display() {
	node curr;
	int num = 1;
	if (head == NULL) {
		printf("Linked list is empty\n");
		return;
	}

	printf("Contents of Linked List : \n");
	curr = head;
	while (curr != NULL) {
		printf("\n |%d| |USN: %s| | Name:%s | | Branch:%s | | Sem:%d | | Ph:%ld |", num, curr->usn, curr->name, curr->branch, curr->sem, curr->phone);
        curr = curr->nxt; // iterate to next 
        num++;
	}
	printf("Number of student nodes : %d \n", count);

}


void stack() {
	int choice;
	while (1) {
		printf("\n 1. Push operation \n 2. Pop operation \n 3. Display \n 4. Exit");
        printf("\n Enter choice for stack demo :");
        scanf("%d", &choice);

        switch (choice) {
        	case 1:
        		insertFront();
        		break;
        	case 2:
        		deleteFront();
        		break;
        	case 3:
        		display();
        		break;
        	default:
        		return;
        }
	}
}

int main() {
	int choice, i , n;
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
        		printf("Enter number of students : \n");
        		scanf("%d", &n);
        		for (i = 1; i <= n; i++) {
        			head = insertFront();
        		}
        		break;
        	case 2:
        		display();
        		break;
        	case 3:
        		head = insertEnd();
        		break;
        	case 4:
        		head = deleteEnd();
        		break;
        	case 5:
        		stack();
        		break;
        	case 6:
        		exit(0);
        	default:
        		printf("Enter valid choice\n");
        }
	}

	return 0;
}






