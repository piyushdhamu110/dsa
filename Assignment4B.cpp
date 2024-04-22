#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    bool lThread, rThread;

    node()
    {
        left = right = nullptr;
        lThread = rThread = true;
    }
    node(int val)
    {
        data = val;
        left = right = nullptr;
        lThread = rThread = true;
    }
};

void insertIntoBST(node *&root, int key)
{
    node *newNode = new node(key);

    if (root == NULL)
    {
        root = newNode;
        return;
    }

    node *temp = root;

    while (true)
    {
        if (temp->data > key)
        {
            if (temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            else
                temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            else
                temp = temp->right;
        }
    }
}

void InorderSucc(node *root, vector<node> &v)
{
    if (root == NULL)
    {
        return;
    }

    InorderSucc(root->left, v);
    v.push_back(*root);
    InorderSucc(root->right, v);
}

void printInorder(node *&root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    cout << root->left << " ";
    cout << root->right << " ";
    cout << root->lThread << " ";
    cout << root->rThread << " ";
    cout << endl;
    printInorder(root->right);
}

void BSTIntoTBT(node *root, vector<node> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i != 0 && v[i].left == nullptr)
        {
            v[i].left = &v[i - 1];
        }
        else
        {
            v[i].lThread = false;
        }

        if (i != v.size() - 1 && v[i].right == nullptr)
        {
            v[i].right = &v[i + 1];
        }
        else
        {
            v[i].rThread = false;
        }

        // cout << v[i].data << " ";
        // cout << v[i].left << " ";
        // cout << v[i].right << " ";
        // cout << v[i].lThread << " ";
        // cout << v[i].rThread << " ";
        // cout << endl;
    }
}

void inOrderTraversal(node *root)
{

    // node *current = root;
    // while (current != root)
    // {

    //     while (current->lThread == false)
    //     {
    //         current = current->left;
    //     }

    //     // cout << current->data << " ";
    //     cout << "First: " << current->data << endl;

    //     if (current->rThread == false)
    //     {
    //         current = current->right;
    //     }
    //     else
    //     {

    //         while (current->rThread == true && current->right != root)
    //         {
    //             current = current->right;
    //             // cout << current->data << " ";
    //             cout << "Second: " << current->data << endl;
    //         }
    //         current = current->right;
    //     }
    // }
    // cout << endl;
    node *current = root;
    cout << current->data << endl;
    while (current!=NULL)
    {
        while (current->lThread==true)
        {
            cout << "kshdfkjhd\n";
            current = current->left;
            cout << "middle: "<<current->data << endl;
        }
        // cout << current->data << " ";
        cout << "First: " << current->data << endl;

        if(current->rThread==false)
        {
            current = current->right;
        }
        else{
            while (current->rThread==true)
            {
                current = current->right;
                // cout << current->data << " ";
                cout << "Second: " << current->data << endl;
            }
            current = current->right;
        }
        
    }
    
}

int main()
{

    node *bst = nullptr;
    insertIntoBST(bst, 6);
    insertIntoBST(bst, 3);
    insertIntoBST(bst, 8);
    insertIntoBST(bst, 1);
    insertIntoBST(bst, 5);
    insertIntoBST(bst, 7);
    insertIntoBST(bst, 11);
    insertIntoBST(bst, 9);
    insertIntoBST(bst, 13);

    vector<node> v;

    InorderSucc(bst, v);

    int n = v.size();
   
    BSTIntoTBT(bst, v);

    v[0].left = NULL;
    v[0].lThread = true;

    v[n - 1].right = NULL;
    v[n - 1].rThread = true;

    // for (int i = 0; i < v.size(); i++)
    // {

    //     cout << v[i].data << " ";
    //     cout << v[i].left << " ";
    //     cout << v[i].right<< " ";
    //     cout << v[i].lThread << " ";
    //     cout << v[i].rThread << " ";
    //     cout << endl;
    // }
   
    // inOrderTraversal(bst);
    printInorder(bst);

    return 0;
}
