#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = NULL;
    
    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("%d inserted into queue\n\n", x);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is Empty!\n\n");
        return;
    }
    struct Node* temp = front;
    printf("%d removed from queue\n\n", front->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void peek() {
    if (front == NULL) {
        printf("Queue is Empty!\n\n");
        return;
    }
    printf("Front element = %d\n\n", front->data);
}

void display() {
    if (front == NULL) {
        printf("Queue is Empty!\n\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue (front -> rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

// Queue using Linked List - Menu Driven Program
int main() {
    int choice, val;

    while (1) {
        printf("=== Queue using Linked List ===\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
                break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n\n");
        }
    }
    return 0;
}
