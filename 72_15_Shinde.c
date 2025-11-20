#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;

struct Node* createNode(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int x) {
    if (node == NULL) return createNode(x);
    if (x < node->data)
        node->left = insert(node->left, x);
    else if (x > node->data)
        node->right = insert(node->right, x);
    return node;
}

// Main function - Print all nodes in given range [low, high]
void printInRange(struct Node* node, int low, int high) {
    if (node == NULL) return;

    // If left subtree can have nodes >= low, go left
    if (node->data > low)
        printInRange(node->left, low, high);

    // If current node lies in range, print it
    if (node->data >= low && node->data <= high)
        printf("%d ", node->data);

    // If right subtree can have nodes <= high, go right
    if (node->data < high)
        printInRange(node->right, low, high);
}

void inorder(struct Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

int main() {
    int ch, val, low, high;

    while (1) {
        printf("\n=== BST - Print Nodes in Range ===\n");
        printf("1. Insert\n");
        printf("2. Print full tree (Inorder)\n");
        printf("3. Print nodes in given range\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                printf("Full BST (Inorder): ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter lower limit: ");
                scanf("%d", &low);
                printf("Enter upper limit: ");
                scanf("%d", &high);
                printf("Nodes between %d and %d : ", low, high);
                printInRange(root, low, high);
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
