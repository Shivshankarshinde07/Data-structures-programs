#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(struct TrieNode* root, char* key) {
    struct TrieNode* curr = root;
    int len = strlen(key);
    
    for (int i = 0; i < len; i++) {
        char ch = tolower(key[i]);
        int index = ch - 'a';
        
        if (index < 0 || index >= ALPHABET_SIZE) continue;  // skip non-alphabet
        
        if (curr->children[index] == NULL)
            curr->children[index] = createNode();
            
        curr = curr->children[index];
    }
    curr->isEndOfWord = 1;
    printf("'%s' inserted successfully\n\n", key);
}

int search(struct TrieNode* root, char* key) {
    struct TrieNode* curr = root;
    int len = strlen(key);
    
    for (int i = 0; i < len; i++) {
        char ch = tolower(key[i]);
        int index = ch - 'a';
        
        if (index < 0 || index >= ALPHABET_SIZE || curr->children[index] == NULL)
            return 0;
            
        curr = curr->children[index];
    }
    return curr->isEndOfWord;
}

void deleteTrie(struct TrieNode* root) {
    if (root == NULL) return;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        deleteTrie(root->children[i]);
    free(root);
}

int main() {
    struct TrieNode* root = createNode();
    char word[50];
    int choice;

    while (1) {
        printf("=== Trie Implementation (Dictionary) ===\n");
        printf("1. Insert word\n");
        printf("2. Search word\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 3) {
            deleteTrie(root);
            printf("Bye bhai! Full marks pakke :)\n");
            break;
        }

        if (choice == 1) {
            printf("Enter word to insert: ");
            fgets(word, 50, stdin);
            word[strcspn(word, "\n")] = 0;
            insert(root, word);
        }
        else if (choice == 2) {
            printf("Enter word to search: ");
            fgets(word, 50, stdin);
            word[strcspn(word, "\n")] = 0;
            
            if (search(root, word))
                printf("'%s' FOUND in Trie ✓\n\n", word);
            else
                printf("'%s' NOT FOUND ✗\n\n", word);
        }
        else {
            printf("Invalid choice\n\n");
        }
    }
    return 0;
}
