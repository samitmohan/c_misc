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
                i = 0; // set i back to 0
                count = m; // count back to m
            }
        }
        else {
            ans[j] = str[count]; // increment j and count
            j++;
            count++;
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