// ---------------

// Array operations -> Create, Display, Insert, Delete, Exit.

#include <stdio.h>
#include <stdlib.h>
#define MAX 5 // size of array

int arr[MAX], pos, elem;
int n = 0; // number of elements


// create array
void create() {
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