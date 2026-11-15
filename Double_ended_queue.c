/* Program to perform :
   1. Front insertion
   2. Rear insertion
   3. Front deletion
   4. Rear deletion
on a double-ended queue.
*/
#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

// Check whether deque is full
int isFull() {
    return (front == 0 && rear == MAX - 1)
           || (front == rear + 1);
}

// Check whether deque is empty
int isEmpty() {
    return front == -1;
}

// A. Front insertion
void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full!\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    deque[front] = value;
    printf("%d inserted at front.\n", value);
}

// B. Rear insertion
void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full!\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
    printf("%d inserted at rear.\n", value);
}

// C. Front deletion
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }

    printf("%d deleted from front.\n",
           deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// D. Rear deletion
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }

    printf("%d deleted from rear.\n",
           deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

// Display deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    int i = front;

    printf("Deque elements: ");

    while (1) {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);

    display();

    deleteFront();
    deleteRear();

    display();

    return 0;
}
