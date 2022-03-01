// ---------------

// postfix evaluation -> // 512+4*+3- = 14

#include <stdio.h>

int stack[20], top = -1; // initially

// push element to stack
void push(int elem) {
    top++; // make space

    stack[top] = elem; // insert element onto stack
}

int pop() {
    int elem;
    elem = stack[top]; // store soon to be deleted elem temporarily in elem
    top--; // delete
    return elem; // return deleted elem
}

int main() {
    char post[25], symbol; // postfix string, symbol
    int operand1, operand2, i;
    printf("\n Enter postfix expression : ");
    scanf("%s", post);
    // length of string pos
    int len = 0;
    while(post[len] != '\0') {
       len++; // calc len
    }

    for (i = 0; i < len; i++) {
        // traverse through postfix string
        symbol = post[i]; // current element

        switch (symbol) {
            case '+':
                operand2 = pop();
                operand1 = pop();
                push(operand1 + operand2); // remove the indiv numbers from stack and push the result onto stack
                break;

            case '-':
                operand2 = pop();
                operand1 = pop();
                push(operand1 - operand2);
                break;

            case '*':
                operand2 = pop();
                operand1 = pop();
                push(operand1 * operand2);
                break;

            case '/':
                operand2 = pop();
                operand1 = pop();
                push(operand1 / operand2);
                break;

            case '^':
                operand2 = pop();
                operand1 = pop();
                push(operand1 ^ operand2);
                break;
            default:
                // empty (no expression)
                push(symbol - '0');
                break;
        }
    }
    printf("\n Value for given expression : %d", pop()); // at the remaining last element from stack -> answer
}

// ---------------