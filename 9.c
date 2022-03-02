// Doubly Linked List


#include <stdio.h>
#include <stdlib.h>

struct node {
	char ssn[20], name[20], dept[20], designation[20];
	int sal;
	long int phone;
	struct node *lchild;
	struct node *rchild;
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
	printf("Enter SSN, Name, Dept, designation, salary, phone number : \n");
	scanf("%s %s %s %s %d %ld", snode->ssn, snode->name, snode->dept, snode->designation, &snode->sal, &snode->phone);
	snode->lchild = NULL;
	snode->rchild = NULL;
	count++;
	return snode;
}

node insertFront() {
	node temp;
	temp = create();
	if (head == NULL) {
		return temp;
	}
	temp->rchild = head;
	head->lchild = temp;
	return temp;
}

node insertEnd() {
	node curr, temp;
	temp = create();
	if (head  == NULL) {
		return temp;
	}
	curr = head;
	while (curr != NULL) {
		curr = curr->rchild;
	}
	curr->rchild = temp;
	temp->lchild = curr;
	return head;
}

node deleteFront() {
	node temp;
	if (head == NULL) {
		printf("DLL is empty\n");
		return NULL;
	}
	if (head->rchild == NULL) {
		printf("Employee node with ssn %s is deleted\n", head->ssn);
		free(head);
		count--;
		return NULL;
	}
	temp = head;
	head = head->rchild;
	temp->rchild = NULL;
	temp->lchild = NULL;
	printf("Employee node with ssn %s is deleted\n",temp->ssn);
	free(temp);
	count--;
	return head;
}

node deleteEnd() {
	node prev, curr;
	if (head == NULL) {
		printf("DLL is empty\n");;
		return NULL;
	}
	if (head->rchild == NULL) {
	printf("Employee node with ssn %s is deleted\n", head->ssn);
	free(head);
	count--;
	return NULL;
	}
	prev = NULL;
	curr = head;
	while (curr->rchild != NULL) {
		prev = curr;
		curr = curr->rchild;
	}
	curr->lchild = NULL;
	printf("Employee with ssn %s is deleted\n", curr->ssn);
	free(curr);
	prev->rchild = NULL;
	count--;
	return head;
}

void display() {
	node curr;
	int num = 1;
	curr = head;
	if (curr == NULL) {
		printf("LL is empty\n");
	}
	while (curr != NULL) {
		printf("\n | %d | SSN : %s | Name : %s | Dept : %s | | Designation : %s | | Salary : %d | | Phone Number : %ld |", num, curr->ssn, curr->name, curr->dept, curr->designation, curr->sal, curr->phone);
		curr = curr->rchild;
		num++;
	}
	printf("Number of employee nodes : %d \n", count);
}

void deque() {
	int choice;
	while (1) {
		 printf("\n 1. Insert Front \n 2. Delete Front \n 3. Insert Rear \n 4. Delete Rear \n 5. Display Status \n 6. Exit");
        scanf("%d", &choice);
        switch (choice) {
        	case 1:
        		head = insertFront();
        		break;
        	case 2:
        		head = deleteFront();
        		break;
        	case 3:
        		head = insertEnd();
        		break;
        	case 4:
        		head = deleteEnd();
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
	int choice, i , n;
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
        		printf("Enter number of employees : \n");
        		scanf("%d", &n);
        		for (i = 1; i <= n; i++) {
        			head = insertFront();
        		}
        		break;
        	case 2:
        		display();
        	case 3:
        		head = insertEnd();
        		break;
        	case 4:
        		head = deleteEnd();
        		break;
        	case 5:
        		insertFront();
        		break;
        	case 6:
        		head = deleteFront();
        		break;
        	case 7:
        		deque();
        		break;
        	case 8:
        		exit(0);
        	default:
        		printf("Enter valid choice\n");;
        }
	}

	return 0;
}































