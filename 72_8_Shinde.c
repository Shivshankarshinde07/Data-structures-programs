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

int isEmpty() {
    return top == -1;
}

int priority(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

void reverse(char *exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    reverse(infix);
    
    int i = 0, k = 0;
    char x;

    while (infix[i]) {
        if (isalnum(infix[i]))
            prefix[k++] = infix[i];

        else if (infix[i] == '(')
            push(infix[i]);

        else if (infix[i] == ')') {
            while ((x = pop()) != '(')
                prefix[k++] = x;
        }

        else {
            while (!isEmpty() && priority(stack[top]) > priority(infix[i]))
                prefix[k++] = pop();
            push(infix[i]);
        }
        i++;
    }

    while (!isEmpty())
        prefix[k++] = pop();

    prefix[k] = '\0';
    reverse(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];
    int ch;

    while (1) {
        printf("\n=== Infix to Prefix Converter ===\n");
        printf("1. Convert\n");
        printf("2. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        if (ch == 2) exit(0);

        printf("Enter infix expression: ");
        scanf("%s", infix);

        top = -1;
        infixToPrefix(infix, prefix);

        printf("Prefix : %s\n\n", prefix);
    }
    return 0;
}
