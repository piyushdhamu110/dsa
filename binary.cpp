#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();

    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
};

void preorder(Node *temp)
{
    if (temp == NULL)
        return;

    cout << temp->data << ' ';
    preorder(temp->left);
    preorder(temp->right);
}
void inorder(Node *temp)
{
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}
void postorder(Node *temp)
{
    if (temp == NULL)
        return;

    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << ' ';
}

int main()
{
    Node *root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);

    cout << "PreOrder: ";
    preorder(root);
    cout << "\nInOrder: ";
    inorder(root);
    cout << "\nPostOrder: ";
    postorder(root);
}

