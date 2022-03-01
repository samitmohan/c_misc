// ---------------

// stack (push pop palindrome)

#include <stdio.h>
#include <stdlib.h>
#define MAX 5 // array size

int stack[MAX]; // create stack of size 5
int top = -1; // initially


// inserting value
void push(int elem) {
    // if stack is full -> top = max - 1 -> stack overflow
    if (top == MAX - 1) {
        printf("\n Stack overflow!");
        return;
    }
    // else top++, stack[top] = elem (insert)
    top++; // increment size
    stack[top] = elem; // insert elem
}

int pop() {
    int elem;
    // if stack is already empty -> stack underlfow
    if (top == -1) {
        printf("\n Stack underflow!!");
        return -1;
    }
    // else
    // remove the topmost element -> elem = stack[top], top--, return elem(returns the deleted element)
    elem = stack[top]; // store temp in elem 
    top--; // delete
    return elem; // returns the deleted element
}

void display() {
    int i;
    // if stack empty
    if (top == -1) {
        printf("\n Stack is empty!");
        return;
    }
    // else
    printf("\n Stack elements are : ");
    // traverse in reverse order because stack (FIFO)
    for (i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
}

// check for palindrome

void palindrome() {
    int flag = 1;
    int i;
    printf("\n Stack contents are : ");
    // print contents (og order)
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    // print contents (reverse order)
    printf("\n Reverse of stack contents are : ");
    for (i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }

    // main logic -> go till half of the elements in stack
    for (i = 0; i <= top/2; i++) {
        // if one half of stack elements is not equal to other half -> not palindrome (flag = 0)
        if (stack[i] != stack[top - i]) {
            flag = 0;
            break;
        }
    }
    
    // answer
    if (flag == 1) {
        // palindrome found!
        printf("\n Palindrome!");
    } else {
        printf("\n Not Palindrome!");
    }
}

int main() {
    int choice, elem;
    while(1) {
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
}

// ---------------
