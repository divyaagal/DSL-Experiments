#include<iostream>
using namespace std;

struct Node {
    int data;
    Node*left;
    Node*right;
};

Node*createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root,int value) {
    if (root == NULL)
        return createNode(value);

    if(value < root->data)
       root->left = insert(root->left, value);
    else
       root->right = insert(root->right, value);
    
    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL)
       return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main() {
    Node* root = NULL;
    int values[] = {50,30,70,20,40,60,80};

    for(int i = 0; i < 7 ; i++) {
        root = insert(root,values[i]);
    }

    cout<<"Inorder Traversal:";
    inorder(root);

    cout<<"\nPreorder Traversal:";
    preorder(root);

    cout<<"\nPostorder Traversal:";
    postorder(root);

    return 0;
}