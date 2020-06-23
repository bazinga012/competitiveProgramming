#include <iostream>
using namespace std;

struct node {
    node* left;
    node* right;
    int data;
};

void Inorder(node *root) {
    if(root==NULL)return ;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

void Postorder(node *root) {
    if(root==NULL)return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}

void Preorder(node *root) {
    if(root ==NULL)return;
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}

