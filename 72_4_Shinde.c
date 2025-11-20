#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int front1 = -1, rear1 = -1;
int front2 = MAX, rear2 = MAX;

void enqueue1(int x) {
    if (rear1 + 1 >= front2) {
        printf("Array Full!\n\n");
        return;
    }
    if (front1 == -1) front1 = 0;
    rear1++;
    arr[rear1] = x;
    printf("%d inserted in Queue-1\n\n", x);
}

void enqueue2(int x) {
    if (rear1 + 1 >= front2) {
        printf("Array Full!\n\n");
        return;
    }
    if (front2 == MAX) front2 = MAX-1;
    rear2--;
    arr[rear2] = x;
    printf("%d inserted in Queue-2\n\n", x);
}

void dequeue1() {
    if (front1 == -1 || front1 > rear1) {
        printf("Queue-1 Empty!\n\n");
        return;
    }
    printf("%d removed from Queue-1\n\n", arr[front1]);
    front1++;
    if (front1 > rear1) front1 = rear1 = -1;
}

void dequeue2() {
    if (front2 == MAX || rear2 >= front2) {
        printf("Queue-2 Empty!\n\n");
        return;
    }
    printf("%d removed from Queue-2\n\n", arr[front2]);
    front2++;
    if (rear2 >= front2) front2 = rear2 = MAX;
}

void displayQ1() {
    if (front1 == -1 || front1 > rear1) {
        printf("Queue-1: Empty\n\n");
        return;
    }
    printf("Queue-1: ");
    for (int i = front1; i <= rear1; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}

void displayQ2() {
    if (front2 == MAX || rear2 >= front2) {
        printf("Queue-2: Empty\n\n");
        return;
    }
    printf("Queue-2: ");
    for (int i = front2; i >= rear2; i--)
        printf("%d ", arr[i]);
    printf("\n\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("=== Two Queues in One Array ===\n");
        printf("1. Enqueue Queue-1\n");
        printf("2. Enqueue Queue-2\n");
        printf("3. Dequeue Queue-1\n");
        printf("4. Dequeue Queue-2\n");
        printf("5. Display Queue-1\n");
        printf("6. Display Queue-2\n");
        printf("7. Exit\n");
        printf("Choice: ");
        scanf("%d("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &val);
                enqueue1(val);
                break;
            case 2:
                scanf("%d", &val);
                enqueue2(val);
                break;
            case 3: dequeue1(); break;
            case 4: dequeue2(); break;
            case 5: displayQ1(); break;
            case 6: displayQ2(); break;
            case 7: exit(0);
            default: printf("Invalid\n\n");
        }
    }
    return 0;
}
