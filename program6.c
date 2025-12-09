#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Check if queue is full
int isFull() {
    return (front == (rear + 1) % SIZE);
}

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Enqueue operation
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is FULL!\n");
        return;
    }

    if (front == -1)  // first element
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = value;

    printf("%d enqueued\n", value);
}

// Dequeue operation
int dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return -1;
    }

    int value = queue[front];

    if (front == rear) {
        // Queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    return value;
}

// Display queue
void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Queue: ");

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);  // queue becomes full

    display();

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    display();

    enqueue(60);
    enqueue(70);  // wrap-around happens here

    display();

    return 0;
}
