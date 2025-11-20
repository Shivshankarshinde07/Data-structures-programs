#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;

struct Node* createNode(int x) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct Node* insert(struct Node* node, int x) {
    if (node == NULL) return createNode(x);
    if (x < node->data)
        node->left = insert(node->left, x);
    else if (x > node->data)
        node->right = insert(node->right, x);
    return node;
}

void inorder(struct Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void preorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct Node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

void bfs() {
    if (root == NULL) {
        printf("Tree empty\n");
        return;
    }
    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    printf("BFS (Level Order): ");
    while (front < rear) {
        struct Node* curr = queue[front++];
        printf("%d ", curr->data);
        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
    printf("\n");
}

void dfs(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    dfs(node->left);
    dfs(node->right);
}

struct Node* mirror(struct Node* node) {
    if (node == NULL) return NULL;
    struct Node* temp = node->left;
    node->left = mirror(node->right);
    node->right = mirror(temp);
    return node;
}

struct Node* findNode(struct Node* node, int val) {
    if (node == NULL || node->data == val) return node;
    if (val < node->data) return findNode(node->left, val);
    return findNode(node->right, val);
}

void findParent(int val) {
    if (root == NULL || root->data == val) {
        printf("No parent (root or empty)\n");
        return;
    }
    struct Node *curr = root, *parent = NULL;
    while (curr != NULL) {
        if (curr->data == val) {
            printf("Parent of %d = %d\n", val, parent->data);
            return;
        }
        parent = curr;
        if (val < curr->data) curr = curr->left;
        else curr = curr->right;
    }
    printf("Node not found\n");
}

void findChildren(int val) {
    struct Node* node = findNode(root, val);
    if (node == NULL) printf("Node not found\n");
    else {
        printf("Children of %d: ", val);
        if (node->left) printf("%d ", node->left->data);
        if (node->right) printf("%d ", node->right->data);
        if (!node->left && !node->right) printf("None");
        printf("\n");
    }
}

void findSibling(int val) {
    if (root == NULL || root->data == val) {
        printf("No sibling (root)\n");
        return;
    }
    struct Node *curr = root, *parent = NULL;
    while (curr != NULL) {
        if (curr->data == val) {
            if (parent->left == curr && parent->right)
                printf("Sibling of %d = %d\n", val, parent->right->data);
            else if (parent->right == curr && parent->left)
                printf("Sibling of %d = %d\n", val, parent->left->data);
            else
                printf("No sibling\n");
            return;
        }
        parent = curr;
        if (val < curr->data) curr = curr->left;
        else curr = curr->right;
    }
}

void findGrandParent(int val) {
    if (root == NULL || root->data == val) {
        printf("No grandparent\n");
        return;
    }
    struct Node *curr = root, *parent = NULL, *gp = NULL;
    while (curr != NULL) {
        if (curr->data == val) {
            if (gp) printf("Grandparent of %d = %d\n", val, gp->data);
            else printf("No grandparent\n");
            return;
        }
        gp = parent;
        parent = curr;
        if (val < curr->data) curr = curr->left;
        else curr = curr->right;
    }
}

void findUncle(int val) {
    if (root == NULL || root->data == val) {
        printf("No uncle\n");
        return;
    }
    struct Node *curr = root, *parent = NULL, *gp = NULL;
    while (curr != NULL) {
        if (curr->data == val) {
            if (gp == NULL || parent == gp->left && gp->right == NULL || parent == gp->right && gp->left == NULL) {
                printf("No uncle\n");
            } else {
                if (parent == gp->left)
                    printf("Uncle of %d = %d\n", val, gp->right->data);
                else
                    printf("Uncle of %d = %d\n", val, gp->left->data);
            }
            return;
        }
        gp = parent;
        parent = curr;
        if (val < curr->data) curr = curr->left;
        else curr = curr->right;
    }
}

// BST All Operations Menu Driven
int main() {
    int ch, val;
    while (1) {
        printf("\n=== Binary Search Tree Operations ===\n");
        printf("1. Insert\n");
        printf("2. Inorder\n");
        printf("3. Preorder\n");
        printf("4. Postorder\n");
        printf("5. BFS (Level Order)\n");
        printf("6. DFS\n");
        printf("7. Mirror Tree\n");
        printf("8. Find Parent of node\n");
        printf("9. Find Children of node\n");
        printf("10. Find Sibling of node\n");
        printf("11. Find GrandParent of node\n");
        printf("12. Find Uncle of node\n");
        printf("13. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2: printf("Inorder: "); inorder(root); printf("\n"); break;
            case 3: printf("Preorder: "); preorder(root); printf("\n"); break;
            case 4: printf("Postorder: "); postorder(root); printf("\n"); break;
            case 5: bfs(); break;
            case 6: printf("DFS: "); dfs(root); printf("\n"); break;
            case 7: root = mirror(root); printf("Tree mirrored\n"); break;
            case 8: printf("Node: "); scanf("%d",&val); findParent(val); break;
            case 9: printf("Node: "); scanf("%d",&val); findChildren(val); break;
            case 10: printf("Node: "); scanf("%d",&val); findSibling(val); break;
            case 11: printf("Node: "); scanf("%d",&val); findGrandParent(val); break;
            case 12: printf("Node: "); scanf("%d",&val); findUncle(val); break;
            case 13: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
