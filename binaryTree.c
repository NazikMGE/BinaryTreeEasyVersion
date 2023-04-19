#include <stdbool.h> // включення бібліотеки для підтримки типу даних bool (true, false)
#include <stdio.h> // включення бібліотеки стандартного вводу-виводу для функцій, які працюють з введенням/виведенням, таких як printf, scanf
#include <stdlib.h> // включення бібліотеки для роботи з пам'яттю (malloc, free) та загальними функціями
#define COUNT 10 // дефініція константи COUNT для кількості пробілів при відображенні дерева

// структура вузла дерева
struct Node {
    char item; // елемент вузла (символьне значення)
    struct Node *left, *right; // вказівники на лівий та правий підвузли
};

// функція для створення нового вузла дерева
struct Node *createNewNode(char k) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node)); // виділення пам'яті для нового вузла
    node->item = k; // присвоєння значення елементу
    node->right = node->left = NULL; // ініціалізація вказівників на підвузли як NULL
    return node; // повернення створеного вузла
}

// рекурсивна функція для відображення результату
void printResult(struct Node *node) {
    if (node == NULL) {
        return;
    }

    printResult(node->left); // перехід до лівого піддерева

    printResult(node->right); // перехід до правого піддерева

    printf("%c", node->item); // друк поточного елемента
}

// допоміжна рекурсивна функція для візуалізації дерева
void print2DUtil(struct Node *root, int space) {
    if (root == NULL)
        return;
    space += COUNT; // збільшення відступу
    print2DUtil(root->left, space); // перехід до лівого піддерева
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" "); // друк пробілів для відступу
    printf("%c\n", root->item); // друк поточного елемента
    print2DUtil(root->right, space); // перехід до правого піддерева
}

// функція для виводу дерева
void printTree(struct Node *root) {
    print2DUtil(root, 0);// функція для виводу дерева
}

int main() {
    struct Node *root = createNewNode('*'); // створення кореневого вузла
    root->left = createNewNode('+'); // створення лівого вузла
    root->right = createNewNode('+'); // створення правого вузла
    root->left->left = createNewNode('a'); // створення вузла лівого лівого піддерева
    root->left->right = createNewNode('b'); // створення вузла лівого правого піддерева
    root->right->left = createNewNode('c'); // створення вузла правого лівого піддерева
    root->right->right = createNewNode('d'); // створення вузла правого правого піддерева

    printf("Our binary tree\n"); // вивід повідомлення про бінарне дерево
    printTree(root); // відображення структури бінарного дерева
    printf("\n");
    printf("Result: "); // вивід результату
    printResult(root); // відображення результату обходу дерева

    return 0; // повернення значення 0, що означає успішне завершення програми
}
