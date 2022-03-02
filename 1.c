// Array operations -> insert, delete, display, create, exit

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int arr[MAX], pos, elem;
int n = 0; // empty

void create() {
	int i;
	printf("How many elements do you want : \n");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
}

void display() {
	int i;
	if (n == 0) {
		printf("Array is empty\n");
		return;
	}
	for (i = 0; i < n; i++) {
		printf("%d \n", arr[i]);
	}
}

void insert() {
	int i;
	if (n == MAX) {
		printf("Array full\n");
		return;
	}
	do {
		printf("Enter position you want to insert the element in : \n");
		scanf("%d", &pos);
	} while (pos > n);
	printf("Enter value to be inserted : \n");
	scanf("%d", &elem);
	for (i = n - 1; i >= pos; i--) {
		arr[i + 1] = arr[i];
	}
	arr[pos] = elem;
	n++;
	display();
}

void delete() {
	int i;
	if (n == 0) {
		printf("Array is empty\n");
		return;
	}
	do {
		printf("Enter position you want to delete : \n");
		scanf("%d", &pos);
	} while (pos >= n);
	elem = arr[pos];
	printf("\n Deleted element : ", elem);
	for (i = pos; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	n--;
	display();
}

int main() {
	int choice;
	while (1) {
		printf("1.Create array of N integers (1) \n");
		printf("2.Display Array \n");
		printf("3.Insert element at given position \n");
		printf("4.Delete element at given position \n");
		printf("5.Exit \n");
		printf("Enter choice : \n");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3: 
				insert();
				break;
			case 4:
				delete();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Invalid choice!\n");
				break;
		}
	}
}



