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
typedef struct node *NODE;

// create -> takes head node, coeff, exponent
NODE create(NODE head, int coeff, int exp) {
    NODE temp, flag;
    // if polynomial empty, create and make the node empty.
    if (head == NULL) {
        temp = (NODE)malloc(sizeof(NODE));
        // constructors 
        temp->coeff = coeff;
        temp->exp = exp;
        temp->nxt = NULL;
        head = temp;
    }
    else {
        // else polynomial not empty, append to last node 
        temp = head;
        while (temp ->nxt != NULL) {
            temp = temp->nxt; // iterate through the node
        }
        // reached last node 
        // define flag, set constructors
        flag = (NODE)malloc(sizeof(NODE));
        flag->coeff = coeff;
        flag->exp = exp;
        flag->nxt = NULL; // points to null as its the last node
        temp->nxt = flag;
    }
    return head;
}

// add two polynomials

NODE polynomial_add(NODE p1, NODE p2, NODE sum) {
    NODE poly1 = p1, poly2 = p2, res; // res = sum
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
            sum = (NODE)malloc(sizeof(NODE));
            res = sum;
        }
        // else sum is already present, just create a new one and append it to res.next
        else {
            res->nxt = (NODE)malloc(sizeof(NODE));
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
        res->nxt = (NODE)malloc(sizeof(NODE)); // create result's next node
        res = res->nxt; // shift
        // same thing
        res->coeff = poly1->coeff;
        res->exp = poly1->exp;
        poly1 = poly1->nxt;
    }
    // poly2 is not empty
    while (poly2 != NULL) {
        res->nxt = (NODE)malloc(sizeof(NODE)); // create result's next node
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

void display(NODE head) {
    NODE temp = head;
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
    NODE p1 = NULL, p2 = NULL, sum = NULL; // initially
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