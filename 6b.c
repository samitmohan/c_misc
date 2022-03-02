// TOH

#include <stdio.h>

void solve(char source, char destination, char helper, int n) {
	if (n == 1) {
		printf("Moving plate 1 from %c to %c \n", source, destination);
		return;
	}
	solve(source, helper, destination, n - 1);
	printf("Moving plate %d from %c to %c \n", n, source, destination);
	solve(helper, destination, source, n - 1);
}

int main() {
	int n = 3;
	solve('A', 'B', 'C', n);

	return 0;
}
