// polynomial, accept two polynomials and add then and print resulting polynomials.

#include <stdio.h>
#include <stdlib.h>

struct node {
	int coeff, exp;
	struct node *nxt;
};
typedef struct node *node;

node create(node head, int coeff, int exp) {
	node temp, flag;
	if (head == NULL) {
		temp = (node)malloc(sizeof(node));
		temp->coeff = coeff;
		temp->exp = exp;
		temp->nxt = NULL;
		head = temp;
	}
	else {
		temp = head;
		while (temp->nxt != NULL) { // iterating and appending
			temp = temp->nxt;
		}
		// last element (temp should point to flag)
		flag = (node)malloc(sizeof(node));
		flag->coeff = coeff;
		flag->exp = exp;
		flag->nxt = NULL;
		temp->nxt = flag;
	}

	return head;
}

node poly_add(node p1, node p2, node sum) {
	node poly1 = p1, poly2 = p2, res;
	if (poly1 != NULL && poly2 == NULL) {
		sum = poly1;
		return sum;
	}
	else if (poly2 != NULL && poly1 == NULL) {
		sum = poly2;
		return sum;
	}

	while (poly1 != NULL && poly2 != NULL) {
		if (sum == NULL) {
			sum = (node)malloc(sizeof(node));
			res = sum;
		}
		else {
			res->nxt = (node)malloc(sizeof(node));
			res = res->nxt;
		}

		if (poly1->exp > poly2->exp) {
			res->coeff = poly1->coeff;
			res->exp = poly1->exp;
			poly1 = poly1->nxt;
		}
		else if (poly2->exp > poly1->exp) {
			res->coeff = poly2->coeff;
			res->exp = poly2->exp;
			poly2 = poly2->nxt;
		}
		else if (poly1->exp == poly2->exp) {
			res->coeff = poly1->coeff + poly2->coeff;
			res->exp = poly1->exp; // pick any, doesn't matter
			poly1 = poly1->nxt;
			poly2 = poly2->nxt;
		}
	}

	while (poly1 != NULL) {
		res->nxt = (node)malloc(sizeof(node));
		res = res->nxt;
		res->coeff = poly1->coeff;
		res->exp = poly1->exp;
		poly1 = poly1->nxt;
	}
	while (poly2 != NULL) {
		res->nxt = (node)malloc(sizeof(node));
		res = res->nxt;
		res->coeff = poly2->coeff;
		res->exp = poly2->exp;
		poly2 = poly2->nxt;
	}

	res->nxt = NULL;
	return sum;
}
 
void display(node head) {
	node temp = head;
	while (temp != NULL) {
		printf("%dx^%d\n", temp->coeff, temp->exp);
		temp = temp->nxt;

		if (temp != NULL) {
			printf("+");
		} else {
			printf("\n");
		}
	}
}

int main() {
	node p1 = NULL, p2 = NULL, sum = NULL;
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
        		printf("Enter coeff of polynomial 1 : \n");
        		scanf("%d", &coeff);
        		printf("Enter exponent of polynomial 1 : \n");
        		scanf("%d", &exp);
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
            	sum = poly_add(p1, p2, sum);
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
	return 0;
}






















