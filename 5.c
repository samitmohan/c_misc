// infix to postfix 

#include <stdio.h>
char stack[20];
int top = -1;

void push(char elem) {
	top++;
	stack[top] = elem;
}

char pop() {
	char elem;
	elem = stack[top];
	top--;
	return elem;
}

int prec(char symbol) {
	int p;
	switch (symbol) {
		case '^':
			p = 3;
			break;
		case '/': case '*':
			p = 2;
			break;
		case '+': case '-':
			p = 1;
			break;
		case '(': case ')':
			p = 0;
			break;
		case '#':
			p = -1;
			break;
	}
	return (p);
}

int main() {
	char post[25], infix[25], symbol, elem;
	int i, pos = 0; // for now
	printf("Enter infix expression : \n");
	scanf("%s", infix);
	// lowest priority push
	push('#');
	int len = 0;
	while (infix[len] != '\0') {
		len++;
	}

	for (i = 0; i < len; i++) {
		symbol = infix[i]; // curr elelm
		switch (symbol) {
			case '(':
				push(symbol);
				break;
			case ')':
				elem = pop();
				while(elem != '(') {
					post[pos++] = elem;
					elem = pop();
				}
				break;
			case '+': case '-': case '*': case '/': case '^':
				while(prec(stack[top]) >= prec(symbol)) {
					elem = pop();
					post[pos++] = elem;
				}
				// push into stack
				push(symbol);
				break;
			default:
				post[pos++] = symbol;
				break;
		}
	}

	while (top > 0) {
		// not empty
		elem = pop();
		post[pos++] = elem;
	}
	post[pos] = '\0';
	printf("Postfix expression : %s \n", post);

	return 0;

}