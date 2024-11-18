#include "coin.h"

typedef struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data)
{
    Node* newNode = 
    (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}



int main() {
    Node* root = createNode(2);
    printf("data: %d\n", root->data);
    printf("size of %ld bytes \n", sizeof(root));
    return 0;
}