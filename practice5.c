// ---------------

// infix to postfix 
// (A + B) * (C - D)
// AB+CD-*

#include <stdio.h>
char stack[20]; // not int unlike postfix eval
int top = -1; // initially

void push(char elem) {
    top++; // make space
    stack[top] = elem; // insert elem
}

char pop() {
    char temp; // 
    temp = stack[top]; // store in temp variable bcs it's soon to be deleted
    top--; // delete
    return temp; // return the deleted element
}

// precalculate
int prec(char symbol) {
    int p; // priority
    switch (symbol) {
        case '^':
            p = 3;  // priority = 3 (highes)
            break;

        case '/': case '*':
            p = 2;  // both have priority = 2
            break;

        case '+': case '-':
            p = 1;
            break;

        case '(': case ')':
            p = 0;  
            break;

        case '#':
            p = -1; // lowest priority = -1
            break;
    }
    return (p); // return priority
}

int main() {
    char post[25], infix[25], symbol, temp;
    int i, pos = 0;
    printf("\n Enter infix expression : "); 
    scanf("%s", infix);

    push('#'); // initially push with lowest priority -> -1
    // length
    int len = 0;
    while (infix[len] != '\0') {
        len++; // calculate 
    }

    for (i = 0; i < len; i++) {
        // traverse infix expression
        symbol = infix[i]; // current element
        
        switch (symbol) {
            case '(':
                push(symbol); // opening bracket!
                break;

            case ')':
                temp = pop(); // closing bracket = pop()
                // while temp != (, keep popping from temp (ans) how? by incrementing position from 0 till end of post
                while (temp != '(') {
                    post[pos++] = temp;
                    temp = pop();
                }
                break;

            case '+': case '-': case'*': case '/': case '^':
                // remember this case / line
                while (prec(stack[top]) >= prec(symbol)) {
                    temp = pop();
                    post[pos++] = temp;
                }
                push(symbol);
                break;
            default:
                post[pos++] = symbol; // if none of the options -> post[pos++] = symbol
                break;
        }
    }

    while (top > 0) { // while not empty -> keep popping
        temp = pop();
        post[pos++] = temp; // pop next (iterate)
    }
    post[pos] = '\0'; // reached end, answer in postfix string
    printf("\n Postfix expression : %s", post);

    return 0;
}

// ---------------
