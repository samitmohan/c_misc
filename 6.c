// postfix evaluation
#include <stdio.h>

int stack[20]; 
int top = -1;

void push(int elem) {
	top++;
	stack[top] = elem;
}

int pop() {
	int elem;
	elem = stack[top];
	top--;
	return elem; // deleted
}

int main() {
	char post[25], symbol;
	int op1, op2, i;
	printf("Enter Postfix expression : \n");
	scanf("%s", post);
	int len = 0;
	while (post[len] != '\0') {
		len++;
	}

	for (i = 0; i < len; i++) {
		symbol = post[i]; // current
		switch (symbol) {
			case '+':
				op2 = pop();
				op1 = pop();
				push(op1 + op2);
				break;
			case '-':
				op2 = pop();
				op1 = pop();
				push(op1 - op2);
				break;
			case '*':
				op2 = pop();
				op1 = pop();
				push(op1 * op2);
				break;
			case '/':
				op2 = pop();
				op1 = pop();
				push(op1 / op2);
				break;
			case '^':
				op2 = pop();
				op1 = pop();
				push(op1 ^ op2);
				break;
			default:
				push(symbol - '0');
				break;
		}
	}
	printf("Value for given expression : %d \n", pop());

}
