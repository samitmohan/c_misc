// circular queue

#include <stdio.h>
#include <stdlib.h>

#define MAX 3
int cq[MAX];
int front = -1, rear = -1;

int isFull() {
	if (front == rear + 1 || front == 0 && rear == MAX - 1) {
		return 1;
	}
	return 0;
}

int isEmpty() {
	if (front == -1) {
		return 1;
	}
	return 0;
}

void insert(int elem) {
	if (isFull()) {
		printf("Overflow\n");
	}
	if (front == -1) {
		front = 0; // reset
	}
	rear = (rear + 1) % MAX;
	cq[rear] = elem;
	printf("Inserted = %d\n",elem);
}


int delete() {
	int elem;
	if (isEmpty()) {
		printf("Underflow\n");
	}
	front = (front + 1) % MAX;
	printf("Deleted element = %d\n", elem);
	return elem;
}


void display() {
	int i;
	if (isEmpty()) {
		printf("Queue is empty\n");
	}
	printf("Front -> %d\n",front);
	for (i = front; i != rear; i = (i+1)%MAX) {
		printf("%d", cq[i]);
	}
	printf("Rear -> %d\n",rear);
}

int main() {
	int choice;
	char elem;
	while (1) {
        printf("\n 1. Insertion and Overflow demo");
        printf("\n 2. Deletion and Underflow demo");
        printf("\n 3. Display");
        printf("\n 4. Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        	case 1:
        		printf("Enter element to be inserted : \n");
        		scanf("%c", &elem);
        		insert(elem);
        		break;
        	case 2:
        		delete();
        		break;
        	case 3:
        		display();
        		break;
        	case 4:
        		exit(1);
        	default:
        		printf("Invalid choice!\n");

        }
	}
	return 0;
}

