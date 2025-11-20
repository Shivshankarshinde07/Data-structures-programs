#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create() {
    struct Node* temp = head;
    head = NULL;
    while (temp != NULL) {
        struct Node* del = temp;
        temp = temp->next;
        free(del);
    }
    printf("List cleared, now create new list\n");
}

void insertBeg(int x) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = head;
    head = newnode;
}

void insertEnd(int x) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newnode;
}

void insertPos(int pos, int x) {
    if (pos == 1) {
        insertBeg(x);
        return;
    }
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    struct Node* temp = head;
    for (int i = 1; i < pos-1 && temp != NULL; i++) temp = temp->next, i++);
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteBeg() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deletePos(int pos) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    if (pos == 1) {
        deleteBeg();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos-1 && temp != NULL; i++) temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        printf("Position not found\n");
        return;
    }
    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

void reverse() {
    struct Node *prev = NULL, *curr = head, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

struct Node* merge(struct Node* h1, struct Node* h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;
    if (h1->data <= h2->data) {
        h1->next = merge(h1->next, h2);
        return h1;
    } else {
        h2->next = merge(h1, h2->next);
        return h2;
    }
}

void findMiddle() {
    struct Node *slow = head, *fast = head;
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element = %d\n", slow->data);
}

void sort() {
    if (head == NULL || head->next == NULL) return;
    struct Node *i, *j;
    int temp;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int detectLoop() {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

void sum() {
    int s = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        s += temp->data;
        temp = temp->next;
    }
    printf("Sum of all data = %d\n", s);
}

void printOddEven() {
    struct Node* temp = head;
    printf("Odd positions : ");
    int pos = 1;
    while (temp != NULL) {
        if (pos % 2 == 1) printf("%d ", temp->data);
        temp = temp->next;
        pos++;
    }
    printf("\nEven positions: ");
    temp = head;
    pos = 1;
    while (temp != NULL) {
        if (pos % 2 == 0) printf("%d ", temp->data);
        temp = temp->next;
        pos++;
    }
    printf("\n");
}

void display() {
    if (head == NULL) {
        printf("List is Empty\n\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

// Singly Linked List - All Operations Menu Driven
int main() {
    int ch, val, pos;
    while (1) {
        printf("\n=== Singly Linked List Operations ===\n");
        printf("1.  Insert Beginning\n");
        printf("2.  Insert End\n");
        printf("3.  Insert at Position\n");
        printf("4.  Delete Beginning\n");
        printf("5.  Delete End\n");
        printf("6.  Delete at Position\n");
        printf("7.  Reverse List\n");
        printf("8.  Find Middle\n");
        printf("9.  Sort List\n");
        printf("10. Detect Loop\n");
        printf("11. Sum of Data\n");
        printf("12. Print Odd-Even Positions\n");
        printf("13. Display List\n");
        printf("14. Clear & Create New\n");
        printf("15. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: printf("Value: "); scanf("%d",&val); insertBeg(val); break;
            case 2: printf("Value: "); scanf("%d",&val); insertEnd(val); break;
            case 3: printf("Pos & Val: "); scanf("%d%d",&pos,&val); insertPos(pos,val); break;
            case 4: deleteBeg(); break;
            case 5: deleteEnd(); break;
            case 6: printf("Pos: "); scanf("%d",&pos); deletePos(pos); break;
            case 7: reverse(); printf("List Reversed\n"); break;
            case 8: findMiddle(); break;
            case 9: sort(); printf("List Sorted\n"); break;
            case 10: printf(detectLoop() ? "Loop Found\n" : "No Loop\n"); break;
            case 11: sum(); break;
            case 12: printOddEven(); break;
            case 13: display(); break;
            case 14: create(); break;
            case 15: exit(0);
            default: printf("Wrong choice\n");
        }
    }
    return 0;
}
