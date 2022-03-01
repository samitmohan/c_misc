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
            front = 0;           // change front to 0
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