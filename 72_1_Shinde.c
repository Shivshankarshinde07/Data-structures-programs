// Stack Implementation using Array 

#include <stdio.h>
#include <stdlib.h>

#define MAX 100                

int stack[MAX];
int top = -1;                 

// Function to push (add) element into stack
void push() {
    if (top >= MAX-1) {
        printf("Stack Overflow! Cannot push more elements.\n\n");
        return;
    }
    
    int value;
    printf("Enter the value to push: ");
    scanf("%d", &value);
    
    top++;
    stack[top] = value;
    printf("%d pushed successfully into stack!\n\n", value);
}

// Function to pop (remove) element from stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n\n");
        return;
    }
    
    printf("%d popped from stack.\n\n", stack[top]);
    top--;
}

// Function to see the top element without removing it
void peek() {
    if (top == -1) {
        printf("Stack is empty! Nothing to show.\n\n");
        return;
    }
    
    printf("Top element is: %d\n\n", stack[top]);
}

// Function to display all elements in stack
void display() {
    if (top == -1) {
        printf("Stack is empty!\n\n");
        return;
    }
    
    printf("Stack elements (top to bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
        if (i == top) 
            printf(" <-- top");
        printf("\n");
    }
    printf("\n");
}

// Main menu
int main() {
    int choice;
    
    printf("\n=== Stack Operations using Array ===\n");
    
    while (1) {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (See Top)\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Thank you! Bye bye :)\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }
    
    return 0;
}
