// stack (push pop palindome)
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int elem) {
	if (top == MAX - 1) {
		printf("Overflow\n");
		return;
	}
	top++;
	stack[top] = elem;
}

int pop() {
	int elem;
	if (top == -1) {
		printf("Underflow\n");
	}
	elem = stack[top];
	top--;
	return elem; // deleted
}

void display() {
	int i;
	if (top == -1) {
		printf("Stack empty\n");
		return;
	}
	printf("Stack contents are : \n");
	for (i = 0; i <= top; i++) {
		printf("%d \n", stack[i]);
	}
}

void palindrome() {
	int flag = 1;
	int i;
	//og
	printf("Stack contents are : \n");
	for (i = top; i <= 0; i--) {
		printf("%d \n", stack[i]);
	}
	//reverse
	printf("Reverse stack contents are : \n");
	for (i = 0; i >= top; i++) {
		printf("%d \n", stack[i]);
	}

	for (i = 0; i < top / 2; i++) {
		if (stack[i] != stack[top - i]) {
			flag = 0;
			break;
		}
	}

	if (flag == 1) {
		printf("palindrome\n");
	}
	else {
		printf(" not palindrome\n");
	}
}

int main() {
	int choice, elem;
	while (1) {
        printf("\n 1. Push element!");
        printf("\n 2. Pop element!");
        printf("\n 3. Display element!");
        printf("\n 4. Palindrome check!");
        printf("\n 5. Exit ");
        printf("\n");
        scanf("%d", &choice);
    
        switch(choice) {
            case 1:
                printf("\n Enter element to be pushed : ");
                scanf("%d", &elem);
                push(elem);
                break;
            case 2:
                elem = pop();
                printf("\n Element popped is %d", elem);
                break;
            case 3:
                display();
                break;
            case 4:
                palindrome();
                break;
            case 5:
                exit(1);
            default:
                printf("\n Enter valid choice!");
                break;
		}
	}
	return 0;
}