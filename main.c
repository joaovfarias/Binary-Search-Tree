#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct treeNode{
    int value;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

bool findElement(treeNode *root, int value);
bool insertElement(treeNode **root, int value);
treeNode *createElement(int value);
void printInOrder(treeNode *root);
void printPostOrder(treeNode *root);
void printPreOrder(treeNode *root);

int main() {

    treeNode *myTreeRoot = NULL;

    insertElement(&myTreeRoot, 10);
    insertElement(&myTreeRoot, 7);
    insertElement(&myTreeRoot, 14);
    insertElement(&myTreeRoot, 5);
    insertElement(&myTreeRoot, 8);
    insertElement(&myTreeRoot, 12);
    insertElement(&myTreeRoot, 15);

    printf("Pre-ordem: ");
    printPreOrder(myTreeRoot);
    printf("\n");
    printf("Em ordem/Ordem central: ");
    printInOrder(myTreeRoot);
    printf("\n");
    printf("Pos-ordem: ");
    printPostOrder(myTreeRoot);
}

treeNode *createElement(int value){

    treeNode *tmp = (treeNode *) malloc(sizeof(treeNode));

    tmp->left = NULL;
    tmp->right = NULL;
    tmp->value = value;

    return tmp;
}

void printInOrder(treeNode *root){

    if (root != NULL){

        printInOrder(root->left);
        printf("%d| ", root->value);
        printInOrder(root->right);
    }
}

void printPostOrder(treeNode *root){

    if (root != NULL){

        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%d| ", root->value);
    }
}

void printPreOrder(treeNode *root){

    if (root != NULL){

        printf("%d| ", root->value);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

bool insertElement(treeNode **root, int value){

    treeNode *noobptr = *root;

    if (noobptr == NULL){
        *root = createElement(value);
        return true;
    }
    if (value == noobptr->value){
        return false;
    }
    
    if (value < noobptr->value){
        insertElement(&(noobptr->left), value);

    }
    else{
        return insertElement(&(noobptr->right), value);
    }

}

bool findElement(treeNode *root, int value){

    if (root == NULL){
        return false;
    }

    if (root->value == value){
        return true;
    }

    if (value < root->value){
        findElement(root->left, value);
    }
    else{
        findElement(root->right, value);
    }
}

