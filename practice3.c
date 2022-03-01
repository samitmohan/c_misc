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
