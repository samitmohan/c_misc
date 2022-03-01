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

