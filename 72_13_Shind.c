#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Doubly Linked List - All Operations Menu Driven
int main() {
    int ch, val, pos;

    while (1) {
        printf("\n=== Doubly Linked List Operations ===\n");
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
        printf("11. Sum of All Data\n");
        printf("12. Print Odd-Even Positions\n");
        printf("13. Display Forward Display\n");
        printf("14. Backward Display\n");
        printf("15. Clear List\n");
        printf("16. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch(ch) {

            case 1:
                printf("Value: ");
                scanf("%d", &val);
                struct Node* new1 = (struct Node*)malloc(sizeof(struct Node));
                new1->data = val;
                new1->prev = NULL;
                new1->next = head;
                if (head != NULL) head->prev = new1;
                head = new1;
                printf("Inserted at beginning\n");
                break;

            case 2:
                printf("Value: ");
                scanf("%d", &val);
                struct Node* new2 = (struct Node*)malloc(sizeof(struct Node));
                new2->data = val;
                new2->next = NULL;
                if (head == NULL) {
                    new2->prev = NULL;
                    head = new2;
                } else {
                    struct Node* temp = head;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = new2;
                    new2->prev = temp;
                }
                printf("Inserted at end\n");
                break;

            case 3:
                printf("Position & Value: ");
                scanf("%d%d", &pos, &val);
                if (pos == 1) { /* reuse case 1 logic */ ch = 1; continue; }
                struct Node* new3 = (struct Node*)malloc(sizeof(struct Node));
                new3->data = val;
                struct Node* temp = head;
                for (int i = 1; i < pos-1 && temp != NULL; i++) temp = temp->next;
                if (temp == NULL) {
                    printf("Position invalid\n");
                    free(new3);
                } else {
                    new3->next = temp->next;
                    new3->prev = temp;
                    if (temp->next != NULL) temp->next->prev = new3;
                    temp->next = new3;
                    printf("Inserted at position %d\n", pos);
                }
                break;

            case 4:
                if (head == NULL) printf("List empty\n");
                else {
                    struct Node* del1 = head;
                    head = head->next;
                    if (head != NULL) head->prev = NULL;
                    free(del1);
                    printf("Deleted from beginning\n");
                }
                break;

            case 5:
                if (head == NULL) printf("List empty\n");
                else if (head->next == NULL) {
                    free(head);
                    head = NULL;
                    printf("Deleted last node\n");
                } else {
                    struct Node* temp = head;
                    while (temp->next != NULL) temp = temp->next;
                    temp->prev->next = NULL;
                    free(temp);
                    printf("Deleted from end\n");
                }
                break;

            case 6:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos == 1) { ch = 4; continue; }
                temp = head;
                for (int i = 1; i < pos && temp != NULL; i++) temp = temp->next;
                if (temp == NULL) printf("Position not found\n");
                else {
                    if (temp->prev != NULL) temp->prev->next = temp->next;
                    if (temp->next != NULL) temp->next->prev = temp->prev;
                    if (temp == head) head = temp->next;
                    free(temp);
                    printf("Deleted position %d\n", pos);
                }
                break;

            case 7:  // Reverse
                temp = head;
                struct Node* t = NULL;
                while (temp != NULL) {
                    t = temp->prev;
                    temp->prev = temp->next;
                    temp->next = t;
                    temp = temp->prev;
                }
                if (t != NULL) head = t->prev;
                printf("List reversed\n");
                break;

            case 8:  // Middle
                if (head == NULL) printf("List empty\n");
                else {
                    struct Node *slow = head, *fast = head;
                    while (fast != NULL && fast->next != NULL) {
                        slow = slow->next;
                        fast = fast->next->next;
                    }
                    printf("Middle element = %d\n", slow->data);
                }
                break;

            case 9:  // Sort (bubble)
                if (head == NULL) break;
                int swapped;
                struct Node* ptr;
                do {
                    swapped = 0;
                    ptr = head;
                    while (ptr->next != NULL) {
                        if (ptr->data > ptr->next->data) {
                            val = ptr->data;
                            ptr->data = ptr->next->data;
                            ptr->next->data = val;
                            swapped = 1;
                        }
                        ptr = ptr->next;
                    }
                } while (swapped);
                printf("List sorted\n");
                break;

            case 10:  // Detect Loop
                slow = head; fast = head;
                int loop = 0;
                while (fast != NULL && fast->next != NULL) {
                    slow = slow->next;
                    fast = fast->next->next;
                    if (slow == fast) { loop = 1; break; }
                }
                printf(loop ? "Loop Detected\n" : "No Loop\n");
                break;

            case 11:  // Sum
                val = 0;
                temp = head;
                while (temp != NULL) {
                    val += temp->data;
                    temp = temp->next;
                }
                printf("Sum = %d\n", val);
                break;

            case 12:  // Odd-Even positions
                printf("Odd positions: ");
                pos = 1;
                temp = head;
                while (temp != NULL) {
                    if (pos % 2 == 1) printf("%d ", temp->data);
                    temp = temp->next;
                    pos++;
                }
                printf("\nEven positions: ");
                pos = 1;
                temp = head;
                while (temp != NULL) {
                    if (pos % 2 == 0) printf("%d ", temp->data);
                    temp = temp->next;
                    pos++;
                }
                printf("\n");
                break;

            case 13:  // Forward
                if (head == NULL) printf("Empty\n");
                else {
                    temp = head;
                    printf("Forward: ");
                    while (temp != NULL) {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }
                    printf("\n");
                }
                break;

            case 14:  // Backward
                if (head == NULL) printf("Empty\n");
                else {
                    temp = head;
                    while (temp->next != NULL) temp = temp->next;
                    printf("Backward: ");
                    while (temp != NULL) {
                        printf("%d ", temp->data);
                        temp = temp->prev;
                    }
                    printf("\n");
                }
                break;

            case 15:  // Clear
                while (head != NULL) {
                    struct Node* del = head;
                    head = head->next;
                    free(del);
                }
                printf("List cleared\n");
                break;

            case 16:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
