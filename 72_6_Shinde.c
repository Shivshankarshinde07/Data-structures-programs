#include <stdio.h>
#include <stdlib.h>

#define MAX 32

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

void decToBin(int n) {
    if (n == 0) {
        printf("Binary: 0\n\n");
        return;
    }
    
    int num = n < 0 ? -n : n;
    
    while (num > 0) {
        push(num % 2);
        num /= 2;
    }
    
    if (n < 0) printf("-");
    printf("Binary: ");
    while (top >= 0)
        printf("%d", pop());
    printf("\n\n");
}

int main() {
    int num, ch;
    
    while (1) {
        printf("=== Decimal to Binary Converter \n");
        printf("1. Convert\n");
        printf("2. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);
        
        if (ch == 2) exit(0);
        if (ch != 1) {
            printf("Wrong input\n\n");
            continue;
        }
        
        printf("Enter decimal number: ");
        scanf("%d", &num);
        
        top = -1;
        decToBin(num);
    }
    return 0;
}
