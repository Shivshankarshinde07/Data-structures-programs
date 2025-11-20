// Two Stacks in One Array 

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int top1 = -1;        
int top2 = MAX;         

// Push in Stack 1
void push1(int x) {
    if (top1 < top2 - 1) {
        arr[++top1] = x;
        printf("%d pushed to Stack-1\n\n", x);
    } else {
        printf("Stack Overflow! No space left\n\n");
    }
}

// Push in Stack 2
void push2(int x) {
    if (top1 < top2 - 1) {
        arr[--top2] = x;
        printf("%d pushed to Stack-2\n\n", x);
    } else {
        printf("Stack Overflow! No space left\n\n");
    }
}

// Pop from Stack 1
void pop1() {
    if (top1 >= 0) {
        printf("%d popped from Stack-1\n\n", arr[top1--]);
    } else {
        printf("Stack-1 is Empty!\n\n");
    }
}

// Pop from Stack 2
void pop2() {
    if (top2 < MAX) {
        printf("%d popped from Stack-2\n\n", arr[top2++]);
    } else {
        printf("Stack-2 is Empty!\n\n");
    }
}

// Display both stacks
void display() {
    printf("Stack-1 (bottom to top): ");
    for (int i = 0; i <= top1; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Stack-2 (bottom to top): ");
    for (int i = MAX-1; i >= top2; i--)
        printf("%d ", arr[i]);
    printf("\n\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("=== Two Stacks in One Array ===\n");
        printf("1. Push Stack-1\n");
        printf("2. Push Stack-2\n");
        printf("3. Pop Stack-1\n");
        printf("4. Pop Stack-2\n");
        printf("5. Display Both Stacks\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value for Stack-1: ");
                scanf("%d", &val);
                push1(val);
                break;
            case 2:
                printf("Enter value for Stack-2: ");
                scanf("%d", &val);
                push2(val);
                break;
            case 3: pop1(); break;
            case 4: pop2(); break;
            case 5: display(); break;
            case 6:
                printf("Bye bhai! Full marks pakke 😎\n");
                exit(0);
            default:
                printf("Galat choice daala bhai!\n\n");
        }
    }
    return 0;
}
