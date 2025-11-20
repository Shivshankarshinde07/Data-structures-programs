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

// Minimum element in BST (leftmost node)
int findMin() {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return -1;
    }
    struct Node* curr = root;
    while (curr->left != NULL)
        curr = curr->left;
    return curr->data;
}

// Maximum element in BST (rightmost node)
int findMax() {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return -1;
    }
    struct Node* curr = root;
    while ( қал->right != NULL)
        curr = curr->right;
    return curr->data;
}

void inorder(struct Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

int main() {
    int ch, val;

    while (1) {
        printf("\n=== BST - Find Min & Max Element ===\n");
        printf("1. Insert\n");
        printf("2. Find Minimum Element\n");
        printf("3. Find Maximum Element\n");
        printf("4. Display Tree (Inorder)\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                val = findMin();
                if (val != -1)
                    printf("Minimum element = %d\n", val);
                break;

            case 3:
                val = findMax();
                if (val != -1)
                    printf("Maximum element = %d\n", val);
                break;

            case 4:
                printf("BST (Inorder): ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
