#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char x;

    while (infix[i] != '\0') {
        if (isalnum(infix[i]))
            postfix[k++] = infix[i];

        else if (infix[i] == '(')
            push(infix[i]);

        else if (infix[i] == ')') {
            while ((x = pop()) != '(')
                postfix[k++] = x;
        }

        else {
            while (priority(stack[top]) >= priority(infix[i]))
                postfix[k++] = pop();
            push(infix[i]);
        }
        i++;
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

int main() {
    {
    char infix[MAX], postfix[MAX];
    int ch;

    while (1) {
        printf("\n=== Infix to Postfix Converter ===\n");
        printf("1. Convert\n");
        printf("2. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        if (ch == 2) exit(0);
        if (ch != 1) {
            printf("Invalid\n\n");
            continue;
        }

        printf("Enter infix expression: ");
        scanf("%s", infix);

        top = -1;
        infixToPostfix(infix, postfix);

        printf("Postfix: %s\n\n", postfix);
    }
    return 0;
}
