// ---------------

// Array operations -> Create, Display, Insert, Delete, Exit.

#include <stdio.h>
#include <stdlib.h>
#define MAX 5 // size of array

int arr[MAX], pos, elem;
int n = 0; // number of elements


// create array

void create() 
    int i;
    printf("\n Enter number of elements : ");
    scanf("%d", &n);
    // input + store
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// display

void display() {
    int i;
    // if empty array
    if (n == 0) {
        printf("\n No elements!");
        return;
    }
    // else
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
}

// insert element in array

void insert() {
    int i;
    // array is full (when -> number of elements in array -> MAX -> 5)
    if (n == MAX) {
        printf("\n Array is full");
        return;
    }
    // else -> Store number
    do {
        printf("\n Enter valid posn where element to be inserted : ");
        scanf("%d", &pos);
    } while (pos > n); // example -> 4th posn, 4 > n (number of elements) for example number of elem -> 5; 
    // while 4 > 5; take valud posn where element to be inserted

    // actual inserting number
    printf("\n Enter value to be inserted : ");
    scanf("%d", &elem);

    // start from end -> go the posn by decrementing i
    for (i = n - 1; i >= pos; i--) {
        // insert element -> keep shifting to left to make extra space 
        arr[i + 1] = arr[i]; // next element becomes curr element (Add)
    }
    // now arr[pos] is empty
    arr[pos] = elem;
    n++; // number of elements now increased
    display();
}

// delete element in array

void delete() {
    int i;
    if (n == 0) {
        printf("\n Array empty");
        return;;
    }
    // else
    do {
        printf("\n Enter value posn where element to be deleted : ");
        scanf("%d", &pos);
    } while (pos >= n);

    // delete element
    elem = arr[pos];
    printf("\n Deleted element : %d", elem);
    
    // shift array to right (to delete one space) (start from pos, go to end of array by incrementing i
    for (i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1]; // current element becomes next element (Delete)
    }
    n--; // number of elements now decreased
    display();
}

int main() {
    int choice;
    while (1) {
        printf("\n 1. Create array of N integers");
        printf("\n 2. Display array");
        printf("\n 3. Insert element at given position");
        printf("\n 4. Delete element at given position");
        printf("\n 5. Exit");

        printf("\n Enter choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                create();
                break;

            case 2:
                display();

            case 3:
                insert();
                break;

            case 4:
                delete();
                break;

            case 5:
                exit(1);
                break;

            default:
                printf("\n Enter valid choice!");
                break;
        }
    }
}

// ---------------

// ---------------

// Read a main string(STR), pattern string(PTR), replace string(REP)
// Find and replace all occurrences of PAT in STR with REP if PAT exists.
// Traverse original string and count number of times old word occurs in string
// Make new string of sufficient size so that new word can be replaced
// Copy original string to new string with replacement of word

// Enter pattern string : hello 
// Enter replace string : beautiful
// Resultant string : beautiful world⏎                                                                                                     
#include <stdio.h>

char str[50], pat[20], rep[20], ans[50];
// i j k (dont set), flag = 0, m = 0, counter
int count = 0, m = 0, i = 0, j = 0, k, flag = 0;

void string_match() {
    while(str[count] != '\0') { // main string count != 0 (iterate over main string)
        if (str[m] == pat[i]) { // is string[m] and pattern_string[i] is same
            // increment both i and m (to check for next)
            i++;
            m++;

            // if pattern string reached till end (meaning-> string contains pattern string fully)
            if (pat[i] == '\0') {
                flag = 1; // ans!
                for (k = 0; rep[k] != '\0'; k++, j++) {
                    ans[j] = rep[k];
                }
                // line a
                i = 0; // set i back to 0
                count = m; // count back to m
            }
        }
        else {
            ans[j] = str[count]; // increment j and count
            j++;
            count++;
            // line a 
            m = count; // opp
            i = 0; // set i back to 0
        }
    }
    // ans[j] = end 
    ans[j] = '\0';
}


int main() {
    printf("\n Enter main string : ");
    gets(str);
    printf("\n Enter pattern string : ");
    gets(pat);
    printf("\n Enter replace string : ");
    gets(rep);
    string_match();
    if (flag == 1) { // ans found
        printf("\n Resultant string : %s", ans);
    } else {
        printf("\n Pattern string not found!");
    }

    return 0;
}

// ---------------

// ---------------

// Create structure to store name acc number balance of customers
// Conditions -:
    // Function to print names of customers having balance < 200
    // Add 100$ in the balance of all customers having more than 1000$ in their balance
    // Print incremented value to their balance

#include <stdio.h>

struct bank_customer {
    char name[20];
    char acc_number[20];
    float balance;
} s[3]; // name of struct

void display(struct bank_customer s[]) {
    int i;
    for (i = 0; i < 3; i++) {
        printf("\n %3s %3s %3f", s[i].name, s[i].acc_number, s[i].balance);
    }
}

void print_less_than_200(struct bank_customer s[]) {
    int i;
    for (i = 0; i < 3; i++) {
        if (s[i].balance < 200) {
            printf("\n Less than 200 : %s", s[i].name);
        }
    }
}

void add_100(struct bank_customer s[]) {
    int i;
    for (i = 0; i < 3; i++) {
        if (s[i].balance > 1000) {
            // add 100$
            s[i].balance += 100; 
        }
    }
    display(s);
}

int main() {
    int i;
    printf("\n Enter name, account number, balance : ");
    for (i = 0; i < 3; i++) {
        scanf("%s %s %f", s[i].name, s[i].acc_number, &s[i].balance);
    }

    print_less_than_200(s);
    add_100(s);
    return 0;
}

// ---------------

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
        if (stack[i] != stack[top - i]) { // example stack[0] != stack[top] or stack[1] != stack[top - 1] and so on...
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
    int i, pos = 0; // for now
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

// 6b

// ---------------

// towers of hanoi

#include <stdio.h>

// n -> number of discs
// if plates == 1, then -> move plate from source to destination direclty
// else -> move n - 1 plates from source to helper via destination
        // move 1 remaining plate from source to desination directly
        // move n - 1 plates from helper to destination via source
        
void solve(char source, char destination, char helper, int n) {
    // base case
    if (n == 1) {
        printf("\n Moving plate 1 from %c to %c", source, destination);
        return;
    } // else
    solve(source, helper, destination, n - 1); // source -> helper via destination (n - 1) plates
    printf("\n Moving plate %d from %c to %c", n, source, destination); // only 1 plate left in source, place in destination (biggest plate)
    solve(helper, destination, source, n - 1); // helper -> destination via source (n - 1 plates)
}

int main() {
    int n = 3;
    solve('A', 'C', 'B', n); // source = a, helper = b, destination = c

    return 0;
}

// ---------------

// ---------------

#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int cq[MAX];
int front = -1, rear = -1;

// check if full
int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == MAX - 1))
        return 1;
    return 0; // else
}

// check if empty
int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}

// Add element

void insert(int elem)
{
    if (isFull())
    {
        printf("\n Overflow (full)");
    }
    else
    {
        if (front == -1)
            front = 0;           // change front to 0 (front++)
        rear = (rear + 1) % MAX; // make space
        cq[rear] = elem;
        printf("\n Inserted -> %d", elem);
    }
}

// Delete element
int delete()
{
    int elem;
    if (isEmpty())
    {
        printf("\n Queue is empty \n");
        return -1;
    }
    else
    {
        elem = cq[front];
        if (front == rear)
        {
            // reset
            front = -1;
            rear = -1;
        }
        // Queue has only one element, so we reset.
        else
        {
            front = (front + 1) % MAX;
        }
        printf("\n Deleted element -> %d \n", elem);
        return elem;
    }
}

// display
void display()
{
    int i;
    if (isEmpty())
    {
        printf("\n Empty Queue");
    }
    else
    {
        printf("\n Front -> %d", front);
        printf("\n Items -> ");
        for (i = front; i != rear; i = (i + 1) % MAX)
        {
            printf("%d", cq[i]);
        }
        printf("%d", cq[i]);
        printf("\n Rear -> %d", rear);
    }
}

int main()
{
    int choice;
    char elem;
    while (1)
    {
        printf("\n 1. Insertion and Overflow demo");
        printf("\n 2. Deletion and Underflow demo");
        printf("\n 3. Display");
        printf("\n 4. Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n Enter element to be inserted : ");
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
            exit(0);
        default:
            printf("\n Enter valid choice!");
        }
    }

    return 0;
}

// ---------------
// ---------------

// Linked List -> USN, Name, Branch, Sem, PhNo
// insertAtFront(), insertAtEnd(), deleteAtFront(), deleteAtEnd(), status of LL and count number of nodes in it.

#include <stdio.h>
#include <stdlib.h>

// node
struct node {
    char usn[25], name[25], branch[25];
    int sem;
    long int phone;
    struct node *nxt; // next pointer
};

typedef struct node *node; // now we just have to mention node

// initially
node head = NULL;
int count = 0;

// creating node
node create() {
    node snode; // student node
    snode = (node)malloc(sizeof(struct node));

    if (snode == NULL) {
        // empty
        printf("\n Linked list is empty");
        exit(1);
    }
    // else -> input data (usn, name, branch, sem, phone number)
    printf("\n Enter USN, Name, Branch, SEM, Phone Number of student : ");
    scanf("%s %s %s %d %ld", snode->usn, snode->name, snode->branch, &snode->sem, &snode->phone);
    snode->nxt = NULL; // nxt pointer points to null as of now (since only 1 element)
    count++; // from 0 -> 1
    return snode;
}

// insert at front
node insertAtFront() {
    node temp;
    temp = create(); // temp node created, count/size++ done
    if (head == NULL) {
        // empty
        return temp; // return head
    }
    // insert at front = move head to next (temp node created, it points to head (if it wants to be the first element))
    temp->nxt = head; // head = temp, return head
    return temp;
}

// insert at end
node insertAtEnd() {
    node curr, temp;
    temp = create(); // temp node created
    if (head == NULL) {
        // empty
        return temp; // head
    }
    // else
    curr = head; // start point
    // traverse through the linked list and go to the end 
    while (curr -> nxt != NULL) {
        curr = curr->nxt; // iterate
    }
    // reached last pointer
    curr->nxt = temp; // last element points to temp (new last element)
    return head; // return LL
}

// delete at front
// [HEAD] 10 (2k) -> 20 (3k) -> 30 (NULL) [TAIL]
// [HEAD] 20 (3k) -> 30 (NULL) [TAIl]

// shift head to head.next

node deleteAtFront() {
    node temp;
    if (head == NULL) {
        // empty
        printf("\n Linked list is empty");
        return NULL;
    }
    // if only 1 element
    if (head->nxt == NULL) {
        printf("\n Student node with usn : %s is deleted", head->usn);
        // decrement size of LL
        count--; 
        free(head);
        return NULL;
    }
    // else -> more than 1 element
    temp = head; // temp
    head = head->nxt; // main logic
    printf("\n Student node with usn : %s is deleted", temp->usn); // current
    count--;
    free(temp);
    return head; // pretty easy explaination if you think about it visually
}

// delete at end -> you go to last element and point it to null .
// if more than 1 element in linked list. (first size--)
/*
    [HEAD] 10 (2k) -> 20 (3k) -> 30 (NULL) [TAIL]
    Removing element? Make 3k = NULL, and shift TAIL to 20.
    Now address of 30 (last (3k) = removed) 
    New tail = Node having value 20.
*/

node deleteAtEnd() {
    node curr, prev;
    if (head == NULL) {
        // empty
        printf("\n Linked list is empty!");
        return NULL;
    }
    // if only 1 element
    if (head->nxt == NULL) {
        printf("\n Student node with usn : %s is deleted", head->usn);
        free(head);
        count--;
        return NULL;
    }
    // else -> more than 1 element
    prev = NULL;
    curr = head;
    // go to last element
    while (curr->nxt != NULL) {
        prev = curr; // store current value of curr in prev and go to the end
        curr = curr->nxt;
    }
    // now prev has last node value, just do prev.address = NULL to delete last node
    printf("\n Student node with usn %s is deleted", curr->usn); // last element
    free(curr);
    prev->nxt = NULL;
    count--;
    return head;
}

// display
void display() {
    node curr;
    int num = 1; // index (1. 2. 3.) -> number of entries
    if (head == NULL) {
        printf("\n Linked list is empty!");
        return;
    }
    // else -> contents
    printf("\n Contents of Linked List : ");
    curr = head;
    // traverse
    while (curr != NULL) {
        printf("\n |%d| |USN: %s| | Name:%s | | Branch:%s | | Sem:%d | | Ph:%ld |", num, curr->usn, curr->name, curr->branch, curr->sem, curr->phone);
        curr = curr->nxt; // iterate to next 
        num++;
    }
    printf("\n Number of student nodes : %d", count);
}

// stack demo (FIFO)
void stack() {
    int choice;
    while (1) {
        printf("\n 1. Push operation \n 2. Pop operation \n 3. Display \n 4. Exit");
        printf("\n Enter choice for stack demo :");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertAtFront();
                break;
            case 2:
                head = deleteAtFront();
            case 3:
                display();
                break;
            default:
            return;
        }
    }
}

int main() {
    int choice, i, n;
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
                printf("\n Enter number of students : ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++){
                    head = insertAtFront();
                }
                break;

            case 2:
                display();
                break;

            case 3:
                head = insertAtEnd();
                break;

            case 4:
                head = deleteAtEnd();
                break;

            case 5:
                stack();
                break;

            case 6:
                exit(0);

            default:
                printf("\n Enter valid choice!");
        }
    }
    return 0;
}

// ---------------

// ---------------

// Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

// Design, Develop and Implement a menu driven Program in C for the following operations on 
// Doubly Linked List (DLL) of Employee Data with the fields: 
// SSN, Name, Dept, Designation, Sal, PhNo

struct node {
    char ssn[25], name[25], dept[10], designation[25];
    int sal;
    long int phone;
    // doubly linked list has 2 pointers -> left node and right node
    struct node *left_link;
    struct node *right_link;
};
typedef struct node *node;

node head = NULL;
int count = 0;

node create() {
    node snode;
    snode = (node)malloc(sizeof(struct node));
    if (snode == NULL) {
        // empty
        printf("\n Linked list empty");
        exit(0);
    }
    // else -> input operations
    printf("\n Enter SSN, Name, Dept, Designation, Salary, Phone number of employee :");
    scanf("%s %s %s %s %d %ld", snode->ssn, snode->name, snode->dept, snode->designation, &snode->sal, &snode->phone);
    // set left and right pointers to null as of now
    snode->left_link = NULL;
    snode->right_link = NULL;
    // count increase -> new node created
    count++;
    return snode;
}

// insert at front
node insertAtFront() {
    node temp;
    temp = create(); // node created, count/size++ done
    if (head == NULL) {
        return temp; // linked list empty
    }
    // else -> right link address points to head (first), and head point to left link (vice versa)
    // easier to draw and imagine
    temp->right_link = head;
    head->left_link = temp;
    return temp;
}

// insert at end
node insertAtEnd() {
    node curr, temp;
    temp = create();
    if (head == NULL) {
        return temp;
    }
    curr = head;
    while (curr->right_link != NULL) {
        // traverse until right link points to null
        curr = curr->right_link;
    }
    // right_link is at end posn, point it to temp.
    curr->right_link = temp;
    temp->left_link = curr; // vice versa
    return head;
}

// delete at front

node deleteAtFront() {
    node temp;
    if (head == NULL) {
        printf("\n Doubly Linked List is empty");
        return NULL;
    }
    // only 1 element / employee
    if (head->right_link == NULL) {
        printf("\n The employee node with ssn %s is deleted", head->ssn); // first one
        free(head);
        count--;
        return NULL;
    }
    // else -> multiple entries (head = head.next trick) (here next = rlink)
    temp = head;  // curr node
    head = head->right_link;
    temp->right_link = NULL; // curr (old / deleted) node points to null (both left and right)
    temp->left_link = NULL;
    printf("\n Employee node with ssn %s is deleted", temp->ssn);
    free(temp);
    count--;
    return head;
}

// delete at end

node deleteAtEnd() {
    node prev, curr;
    if (head == NULL) {
        printf("\n Doubly Linked List is empty");
        return NULL;
    }
    // only 1 element / employee
    if (head->right_link == NULL) {
        printf("\n The employee node with ssn %s is deleted", head->ssn); // first one
        free(head);
        count--;
        return NULL;
    }
    // else -> multiple entries
    prev = NULL;
    curr = head;
    // traverse through LL
    while(curr->right_link != NULL) {
        prev = curr;
        curr = curr->right_link;
    }
    // prev is at last node, prev.next = NULL in this case prev.rlink = NULL
    // and curr->left_link should also be NULL
    curr->left_link = NULL;
    printf("\n Employee node with ssn %s is deleted", curr->ssn);
    free(curr);
    prev->right_link = NULL;
    count--;
    return head;
}

void display() {
    node curr;
    int num = 1; // node number (entry/index)
    curr = head;
    if (curr == NULL) {
        // empty
        printf("\n Linked List is empty!");
    }
    while (curr != NULL) {
        printf("\n | %d | SSN : %s | Name : %s | Dept : %s | | Designation : %s | | Salary : %d | | Phone Number : %ld |", num, curr->ssn, curr->name, curr->dept, curr->designation, curr->sal, curr->phone);
        curr = curr->right_link; // next
        num++; 
    }
    printf("\n Number of employee nodes : %d", count); // count
}

// deque (both front and rear entry)

void deque() {
    int choice;
    while (1) {
        printf("\n 1. Insert Front \n 2. Delete Front \n 3. Insert Rear \n 4. Delete Rear \n 5. Display Status \n 6. Exit");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                head = insertAtFront();
                break;
            case 2:
                head = deleteAtFront();
                break;
            case 3:
                head = insertAtEnd();
                break;

            case 4:
                head = deleteAtEnd();
                break;
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
    int choice, i, n;
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
                printf("\n Enter number of employees : ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++) {
                    head = insertAtEnd();
                }
                break;

            case 2:
                display();
                break;

            case 3:
                head = insertAtEnd();
                break;

            case 4:
                head = deleteAtEnd();
                break;

            case 5:
                head = insertAtFront();
                break;

            case 6:
                head = deleteAtFront();

            case 7:
                deque();
                break;

            case 8:
                exit(0);

            default:
                printf("\n Enter valid choice!");
        }
    }
}

// ---------------

// ---------------

/*
Using circular representation for a polynomial, design, develop, and execute a program 
accept two polynomials, add them, and then print the resulting polynomial.
*/

#include <stdio.h>
#include <stdlib.h>

// structure -> 2 things -> coefficient and exponent
struct node {
    int coeff, exp; 
    struct node *nxt;
};
typedef struct node *node;

// create -> takes head node, coeff, exponent
node create(node head, int coeff, int exp) {
    node temp, flag;
    // if polynomial empty, create and make the node empty.
    if (head == NULL) {
        temp = (node)malloc(sizeof(node));
        // constructors 
        temp->coeff = coeff;
        temp->exp = exp;
        temp->nxt = NULL;
        head = temp;
    }
    else {
        // else polynomial not empty, append to last node 
        temp = head;
        while (temp->nxt != NULL) {
            temp = temp->nxt; // iterate through the node
        }
        // reached last node 
        // define flag, set constructors
        flag = (node)malloc(sizeof(node));
        flag->coeff = coeff;
        flag->exp = exp;
        flag->nxt = NULL; // points to null as its the last node
        temp->nxt = flag;
    }
    return head;
}

// add two polynomials

node polynomial_add(node p1, node p2, node sum) {
    node poly1 = p1, poly2 = p2, res; // res = sum
    if (poly1 != NULL && poly2 == NULL) {
        // poly1 is answer
        sum = poly1;
        return sum;
    }
    else if (poly1 == NULL && poly2 != NULL) {
        // poly2 is answer
        sum = poly2;
        return sum;
    }
    
    // if both not null
    while (poly1 != NULL && poly2 != NULL) {
        // if sum = null, create sum node and assign res to sum
        if (sum == NULL) {
            sum = (node)malloc(sizeof(node));
            res = sum;
        }
        // else sum is already present, just create a new one and append it to res.next
        else {
            res->nxt = (node)malloc(sizeof(node));
            res = res->nxt;
        }

        // if poly1's exponent > poly2's exponent then :
            // ans = poly1, res.coeff = poly1's coeff and res.expo = poly1's exp
            // poly1 = poly1.next -> move forward and check for other terms
        if (poly1->exp > poly2->exp) {
            res->coeff = poly1->coeff;
            res->exp = poly1->exp;
            poly1 = poly1->nxt;
        }
        // else -> ans = poly2, res.coeff = poly2's coeff and res.expo = poly2's exp
            // poly2 = poly2.next -> move forward and check for other terms
        else if (poly1-> exp < poly2->exp) {
            res->coeff = poly2->coeff;
            res->exp = poly2->exp;
            poly2 = poly2->nxt;
        }
        // if both are equal
        else if (poly1->exp == poly2->exp) {
            // then add
            res->coeff = poly1->coeff + poly2->coeff;
            res->exp = poly1->exp; // pick any, doesn't matter
            // increment both
            poly1 = poly1->nxt;
            poly2 = poly2->nxt;
        }
    }

    // poly1 is not empty
    while (poly1 != NULL) {
        res->nxt = (node)malloc(sizeof(node)); // create result's next node
        res = res->nxt; // shift
        // same thing
        res->coeff = poly1->coeff;
        res->exp = poly1->exp;
        poly1 = poly1->nxt;
    }
    // poly2 is not empty
    while (poly2 != NULL) {
        res->nxt = (node)malloc(sizeof(node)); // create result's next node
        res = res->nxt; // shift
        // same thing
        res->coeff = poly2->coeff;
        res->exp = poly2->exp;
        poly2 = poly2->nxt;
    }

    // at last the end term points to null
    // return sum (ans)
    res->nxt = NULL; 
    return sum;
}

// display polynomial

void display(node head) {
    node temp = head;
    while (temp != NULL) {
        // print and then iterate
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->nxt;
        // if temp reaches end = print new line, otherwise print + to concatenate
        if (temp != NULL) {
            printf("+");
        } 
        else {
            printf("\n");
        }
    }
}

int main() {
    node p1 = NULL, p2 = NULL, sum = NULL; // initially
    int choice, coeff, exp;
    while (1) {
        printf("\n 1. Enter polynomial 1");
        printf("\n 2. Enter polynomial 2");
        printf("\n 3. Perform addition of 1 and 2: ");
        printf("\n 4. Exit");;
        printf("\n Enter choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n Enter coeff of polynomial 1 : ");
                scanf("%d", &coeff);
                printf("\n Enter exponent of polynomial 1 : ");
                scanf("%d", &exp);
                // create polynomial1
                p1 = create(p1, coeff, exp);
                break;

            case 2:
                printf("\n Enter coeff of polynomial 2 : ");
                scanf("%d", &coeff);
                printf("\n Enter exponent of polynomial 2 : ");
                scanf("%d", &exp);
                // create polynomial1
                p2 = create(p2, coeff, exp);
                break;

            case 3:
                sum = polynomial_add(p1, p2, sum);
                printf("\n Polynomial 1 : ");
                display(p1);
                printf("\n Polynomial 2 : ");
                display(p2);
                printf("\n Sum : ");
                display(sum);
                break;

            case 4:
                exit(0);

            default:
                printf("\n Enter valid choice!");
                break;
        }
    }
}

// ---------------

// ---------------

/*
11. Design, Develop and Implement a menu driven Program in C for BST
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
b. Traverse the BST in Inorder, Preorder and Post Order
c. Search the BST for a given element (KEY) and report the appropriate message
d. Exit
*/

#include <stdio.h>
#include <stdlib.h>

struct BST {
    // 3 parameters -> data, left child, right child
    int data;
    struct BST *lchild;
    struct BST *rchild;
};
typedef struct BST *node;

node create() {
    node temp;
    temp = (node)malloc(sizeof(struct BST));
    printf("\n Enter value : ");
    scanf("%d", &temp->data); // data -> value
    // initially left and right child -> null
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

// insert

// root -> root node, newnode -> new node
// if new node value < root value -> goes to left half (root->leftchild = newnode)
// if new node value > root value -> goes to right half (root->rightchild = newnode)
void insert(node root, node newnode) {
    // left part
    if (newnode->data < root->data) {
        // if empty
        if (root->lchild == NULL) {
            // insert
            root->lchild = newnode;
        }
        // if elements already there -> use recursion to insert
        insert(root->lchild, newnode);
    }

    // right part
    if (newnode->data > root->data) {
        // if empty
        if (root->rchild == NULL) {
            // insert
            root->rchild = newnode;
        }
        // else elements already there -> use recursion to insert
        insert(root->rchild, newnode);
    }
}

// searching

void search(node root) {
    int key;
    node curr;
    if (root == NULL) {
        // empty BST
        printf("\n BST is empty");
        return;
    }
    // if bst not empty
    printf("\n Enter element to be searched : ");
    scanf("%d", &key);
    curr = root; // head
    // traverse over BST
    while (curr != NULL) {
        // found
        if (curr->data == key) {
            printf("\n Key element is present in BST");
            return;
        }
        // if left half
        if (key < curr->data) {
            // check for left side
            curr = curr->lchild;
        }
        else {
            // check for right side
            curr = curr->rchild;
        }
    }
    // if none works
    printf("\n Key element is not found in BST");
}

// inorder -> Left -> Node -> Right (inorder(leftchild), root->data, inordere(rightchild))

void inorder(node root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

// preorder -> Node -> Left -> Right (root->data, preorder(lchild), preorder(rchild))

void preorder(node root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

// postorder -> Left -> Right -> Node (postorder(lchild), postorder(rchild), root-data))

void postorder(node root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}

int main() {
    int choice, key, value, i, n;
    node root = NULL, newnode; // initalise
    while (1) {
        printf("\n 1. Create BST");
        printf("\n 2. Search");
        printf("\n 3. BST traversals");
        printf("\n 4. Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("\n Enter number of elements : ");
            scanf("%d", &n);
            for (i = 1; i <= n; i++) {
                // create new node
                newnode = create();
                if (root == NULL) { // tree is empty -> push value of newnode as the root node.
                    root = newnode;
                }
                // else tree is not empty -> insert newnode in root
                insert(root, newnode);
            }
            break;

        case 2:
            search(root);
            break;

        case 3:
            if (root == NULL) {
                printf("\n Tree is not created"); // empty
            }
            else {
                printf("\n Preorder display : ");
                preorder(root);
                printf("\n Inorder display : ");
                inorder(root);
                printf("\n Postorder display : ");
                postorder(root);
            }
            break;

        case 4:
            exit(0);

        default:
            break;
        }
    }
}

// ---------------

// ---------------

// 12
/*
Following is traversal of ternary search tree
bug
cat
cats
up

Following are search results for cats, bu and cat respectively
Found
Not Found

Remember output! */

#include <stdio.h>
#include <stdlib.h>
#define MAX 50
// Construct a dictionary of key-value pairs using Tree and search for a value matching a key

struct Node
{
    char data;
    unsigned isEndOfString : 1;

    struct Node *left, *eq, *right;
};

// A utility function to create a new ternary search tree node
struct Node *newNode(char data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = NULL;
    return temp;
}

// Function to insert a new word in a Ternary Search Tree
void insert(struct Node **root, char *word)
{
    // Base Case: Tree is empty
    if (!(*root))
        *root = newNode(*word);

    // If current character of word is smaller than root's character,
    // then insert this word in left subtree of root
    if ((*word) < (*root)->data)
        insert(&((*root)->left), word);

    // If current character of word is greate than root's character,
    // then insert this word in right subtree of root
    else if ((*word) > (*root)->data)
        insert(&((*root)->right), word);

    // If current character of word is same as root's character,
    else
    {
        if (*(word + 1))
            insert(&((*root)->eq), word + 1);

        // the last character of the word
        else
            (*root)->isEndOfString = 1;
    }
}

// A recursive function to traverse Ternary Search Tree
void traverseTSTUtil(struct Node *root, char *buffer, int depth)
{
    if (root)
    {
        // First traverse the left subtree
        traverseTSTUtil(root->left, buffer, depth);

        // Store the character of this node
        buffer[depth] = root->data;
        if (root->isEndOfString)
        {
            buffer[depth + 1] = '\0';
            printf("%s\n", buffer);
        }

        // Traverse the subtree using equal pointer (middle subtree)
        traverseTSTUtil(root->eq, buffer, depth + 1);

        // Finally Traverse the right subtree
        traverseTSTUtil(root->right, buffer, depth);
    }
}

// The main function to traverse a Ternary Search Tree.
// It mainly uses traverseTSTUtil()
void traverseTST(struct Node *root)
{
    char buffer[MAX];
    traverseTSTUtil(root, buffer, 0);
}

// Function to search a given word in TST
int searchTST(struct Node *root, char *word)
{
    if (!root)
        return 0;

    if (*word < (root)->data)
        return searchTST(root->left, word);

    else if (*word > (root)->data)
        return searchTST(root->right, word);

    else
    {
        if (*(word + 1) == '\0')
            return root->isEndOfString;

        return searchTST(root->eq, word + 1);
    }
}

// Driver program to test above functions
int main()
{
    struct Node *root = NULL;

    insert(&root, "cat");
    insert(&root, "cats");
    insert(&root, "up");
    insert(&root, "bug");

    printf("Following is traversal of ternary search tree\n");
    traverseTST(root);

    printf("\nFollowing are search results for cats, bu and cat respectively\n");
    searchTST(root, "cats") ? printf("Found\n") : printf("Not Found\n");
    searchTST(root, "bu") ? printf("Found\n") : printf("Not Found\n");
    searchTST(root, "cat") ? printf("Found\n") : printf("Not Found\n");

    return 0;
}

// ---------------
