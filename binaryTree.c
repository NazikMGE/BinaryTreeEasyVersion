#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

struct Node {
    char item;
    struct Node *left, *right;
};

struct Node *createNewNode(char k) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->item = k;
    node->right = node->left = NULL;
    return node;
}

void printResult(struct Node *node) {
    if (node == NULL) {
        return;
    }
    printResult(node->left);
    printResult(node->right);
    printf("%c", node->item);
}

void print2DUtil(struct Node *root, int space) {
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->left, space); 
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%c\n", root->item);
    print2DUtil(root->right, space); 
}

void printTree(struct Node *root) {
    print2DUtil(root, 0);
}

int main() {
    struct Node *root = createNewNode('*');
    root->left = createNewNode('+');
    root->right = createNewNode('+');

    root->left->left = createNewNode('a');
    root->left->right = createNewNode('b');

    root->right->left = createNewNode('c');
    root->right->right = createNewNode('d');

    printf("Our binary tree\n");
    printTree(root);
    printf("\n");
    printf("Result: ");
    printResult(root);
    
    return 0;
}