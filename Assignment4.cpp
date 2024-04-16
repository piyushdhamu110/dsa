#include <iostream>
#include <queue>
#include <stack>
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

void insert_Node(int key, node *&root)
{
    node *p = new node(key);

    if (root->left == NULL)
    {
        root->left = p;
        p->left = root;
        p->right = root;
        root->lThread = false;
        return;
    }
    else
    {
        node *temp = root->left;

        while (true)
        {
            if (key < temp->data)
            {
                if (temp->lThread == true)
                {
                    p->left = temp->left;
                    temp->left = p;
                    temp->lThread = false;
                    p->right = temp;
                    return;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->rThread == true)
                {
                    p->right = temp->right;
                    temp->right = p;
                    temp->rThread = false;
                    p->left = temp;
                    return;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}

void inOrderTraversal(node *root)
{

    node *current = root->left;

    while (current != root)
    {

        while (current->lThread == false)
        {
            current = current->left;
        }

        cout << current->data << " ";

        if (current->rThread == false)
        {
            current = current->right;
        }
        else
        {

            while (current->rThread == true && current->right != root)
            {
                current = current->right;
                cout << current->data << " ";
            }
            current = current->right;
        }
    }
    cout << endl;
}

void preorderTraversal(node *root)
{
    node *current = root->left;

    while (current != root)
    {
        cout << current->data << " ";

        if (current->lThread == false)
        {
            current = current->left;
        }
        else if (current->rThread == false)
        {
            current = current->right;
        }
        else
        {
            while (current->rThread == true && current->right != root)
            {
                current = current->right;
            }
            current = current->right;
        }
    }
    cout << endl;
}

void insertIntoBST(node *&root, int key)
{
    node *nw = new node(key);

    if (root == NULL)
    {
        root = nw;
        return;
    }
    node *temp = root;
    while (true)
    {
        if (temp->data > key)
        {
            if (temp->left == NULL)
            {
                temp->left = nw;
                return;
            }
            else
                temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = nw;
                return;
            }
            else
                temp = temp->right;
        }
    }
}

void bstInorder(node *&root, queue<node *> &q) 
{
    if (root == NULL)
        return;

    bstInorder(root->left, q); 
    q.push(root);            
    bstInorder(root->right, q); 
}

void convertToThreadedBST(node *dummy)
{
    stack<node *> s;
    node *current = dummy->left;
    node *prev = dummy;

    // Perform inorder traversal to establish thread connections
    while (current || !s.empty())
    {
        while (current)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        // Update thread pointers
        if (prev->rThread)
        {
            prev->right = current;
            prev->rThread = false;
        }
        if (current->left == nullptr)
        {
            current->left = prev;
            current->lThread = false;
        }

        prev = current;
        current = current->right;
    }

    // Set thread flags for the first and last nodes
    node *first = dummy->left;
    while (first->left)
        first = first->left;
    first->lThread = true;

    node *last = dummy->left;
    while (last->right)
        last = last->right;
    last->rThread = true;
}

int main()
{
    node *dummy = new node(999);

    insert_Node(45, dummy);
    insert_Node(32, dummy);
    insert_Node(7, dummy);
    insert_Node(98, dummy);
    insert_Node(62, dummy);

    cout << "Inorder: ";
    inOrderTraversal(dummy);

    cout << "Preorder: ";
    preorderTraversal(dummy);

    node *bst = NULL;
    insertIntoBST(bst, 6);
    insertIntoBST(bst, 3);
    insertIntoBST(bst, 8);
    insertIntoBST(bst, 1);
    insertIntoBST(bst, 5);
    insertIntoBST(bst, 7);
    insertIntoBST(bst, 11);
    insertIntoBST(bst, 9);
    insertIntoBST(bst, 13);

    queue<node *> q;
    q.push(NULL);
    bstInorder(bst, q); 
    q.push(NULL);

    // while(!q.empty())
    // {
    //     cout << q.front()->data << " ";
    //     q.pop();
    // }
}
