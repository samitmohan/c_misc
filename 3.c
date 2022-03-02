// str to store name, acc number, balance of customers, balance < 200; print(name of customer)
// add 100$ in balance of all customers having more than 1000$ in balance

#include <stdio.h>

struct bank_customer {
	char name[20];
	char acc_number[20];
	float balance;
} s[3];

void display(struct bank_customer s[]) {
	int i;
	for (i = 0; i < 3; i++) {
		printf("\n %s %s %f", s[i].name, s[i].acc_number, s[i].balance);
	}
}

void print_less_than_200(struct bank_customer s[]) {
	int i;
	for (i = 0; i < 3; i++) {
		if (s[i].balance < 200) {
			printf("%s", s[i].name);
		}
	}
}

void add_100(struct bank_customer s[]) {
	int i;
	for (i = 0; i < 3; i++) {
		if (s[i].balance > 1000) {
			s[i].balance += 100;
		}
	}
	display(s);
}

int main() {
	int i;
	printf("Enter name, acc number, balance : \n");
	for (i = 0; i < 3; i++) {
		scanf("%s %s %f", s[i].name, s[i].acc_number, &s[i].balance);
	}
	print_less_than_200(s);
	add_100(s);
	return 0;
}