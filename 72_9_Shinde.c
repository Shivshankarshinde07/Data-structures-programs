#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
    printf("%d pushed to stack\n\n", x);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Empty\n\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped from stack\n\n", top->data);
    top = top->next;
    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("Stack is Empty\n\n");
        return;
    }
    printf("Top element = %d\n\n", top->data);
}

void display() {
    if (top == NULL) {
        printf("Stack is Empty\n\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack (top -> bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

// Stack using Linked List - Menu Drive
int main() {
    int choice, val;

    while (1) {
        printf("=== Stack using Linked List ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n\n");
        }
    }
    return 0;
}
