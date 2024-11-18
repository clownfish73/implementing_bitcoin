#include "coin.h"

typedef struct Node {
    int data;
    struct Node *right;
    struct Node *left;
} Node;

Node* createNode(int data)
{
    Node* newNode = 
    (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};

void insert(Node** root, int data)
{
    Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = *root;

    while (front != rear){
        temp = queue[++front];

        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        }

        else {
            queue[++rear] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        }
        
        else {
            queue[++rear] = temp->right;
        }
    }
}

void inorderTraversal(Node* root)
{
    if (root==NULL){
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);

};

int main() {
    Node* root = NULL;
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 50);
    insert(&root, 80);
    insert(&root, 70);
    insert(&root, 80);

    inorderTraversal(root);

    return 0;
}