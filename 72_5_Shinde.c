
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top >= MAX-1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return '#';                
    return stack[top--];
}

char peek() {
    if (top == -1) return '#';
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int isMatchingPair(char a, char b) {
    if (a == '(' && b == ')') return 1;
    if (a == '{' && b == '}') return 1;
    if (a == '[' && b == ']') return 1;
    return 0;
}

int areParenthesesBalanced(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[')
            push(ch);

        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty()) 
                return 0;                     

            char open = pop();
            if (!isMatchingPair(open, ch))
                return 0;                       
        }
    }
    return isEmpty();                      
}

int main() {
    char expr[MAX];
    int choice;

    while (1) {
        printf("\n=== Parentheses Matching using Stack ===\n");
        printf("1. Check Expression\n");
        printf("2. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 2) {
            printf("Bye!\n");
            exit(0);
        }
        if (choice != 1) {
            printf("Invalid choice\n");
            continue;
        }

        printf("Enter expression: ");
        scanf("%s", expr);

        top = -1;                   

        if (areParenthesesBalanced(expr))
            printf("Balanced ✓\n");
        else
            printf("Not Balanced ✗\n");
    }
    return 0;
}
