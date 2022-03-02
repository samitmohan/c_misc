// Read main string, pattern string, replace string, find and replace all occurences of pat in str with rep if pat exists

#include <stdio.h>

char str[50], pat[50], rep[50], ans[50];
int count = 0, m = 0, i = 0, j = 0, k, flag = 0;


void string_match() {
	while(str[count] != '\0') {
		if (str[m] == pat[i]) {
			i++;
			m++;

			if (pat[i] == '\0') {
				flag = 1; // ans
				for (k = 0; rep[k] != '\0'; k++, j++) {
					ans[j] = rep[k];
				}
				i = 0;
				count = m;
			}
		}
		else {
			ans[j] = str[count];
			j++;
			count++;
			m = count;
			i = 0;
		}
	}
	ans[j] = '\0';
}

int main() {
	printf("Enter main string : \n");
	gets(str);
	printf("Enter pattern string : \n");
	gets(pat);
	printf("Enter replacement string : \n");
	gets(rep);

	string_match();
	if (flag == 1) {
		printf("Resultant string : %s", ans);
	}
	else {
		printf("Resultant string is not found: \n");
	}

	return 0;
}
