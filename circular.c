//Implementation of a circular queue using C
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Insert an element
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full!\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = value;

    printf("%d inserted\n", value);
}

// Remove an element
void dequeue() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display queue elements
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();
    enqueue(50);

    display();

    return 0;
}
