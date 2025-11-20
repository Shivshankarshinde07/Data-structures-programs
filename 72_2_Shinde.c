// Queue Implementation using Array

#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int q[SIZE];
int front = -1;
int rear = -1;

// Insert element
void enqueue() {
    if (rear == SIZE-1) {
        printf("Queue is Full!\n\n");
        return;
    }
    
    int x;
    printf("Enter value to insert: ");
    scanf("%d", &x);
    
    if (front == -1) front = 0;    // first element
    rear++;
    q[rear] = x;
    printf("%d inserted into queue\n\n", x);
}

// Delete element
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n\n");
        return;
    }
    
    printf("%d deleted from queue\n\n", q[front]);
    front++;
    
    if (front > rear)              // queue became empty
        front = rear = -1;
}

// See front element
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n\n");
        return;
    }
    printf("Front element = %d\n\n", q[front]);
}

// Display whole queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n\n");
        return;
    }
    
    printf("Queue (front -> rear): ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("=== Queue Menu ===\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: 
                printf("Bye bye!\n");
                exit(0);
            default:
                printf("Invalid choice, try again\n\n");
        }
    }
    return 0;
}
