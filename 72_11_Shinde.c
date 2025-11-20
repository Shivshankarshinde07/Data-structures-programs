#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int apply(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '^') return (int)pow(a, b);
    return 0;
}

int evaluatePostfix(char exp[]) {
    top = -1;
    int i = 0, num = 0;

    while (exp[i] != '\0') {
        if (exp[i] == ' ' || exp[i] == '\t') {
            i++;
            continue;
        }

        if (isdigit(exp[i])) {
            num = 0;
            while (exp[i] != '\0' && isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
            continue;
        }

        if (isOperator(exp[i])) {
            int b = pop();
            int a = pop();
            push(apply(a, b, exp[i]));
        }
        i++;
    }
    return pop();
}

int main() {
    char exp[MAX];
    int choice;

    while (1) {
        printf("\n=== Postfix Expression Evaluation ===\n");
        printf("1. Evaluate\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 2) exit(0);
        if (choice != 1) continue;

        printf("Enter postfix expression: ");
        fgets(exp, MAX, stdin);
        exp[strcspn(exp, "\n")] = 0;

        printf("Result = %d\n\n", evaluatePostfix(exp));
    }
    return 0;
}
