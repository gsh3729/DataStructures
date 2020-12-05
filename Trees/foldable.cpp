#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool foldableutil(Node* left, Node* right)
{
    if(left == NULL && right == NULL)
    {
        return true;
    }
    else if (left == NULL || right == NULL)
    {
        return false;
    }
    
    return foldableutil(left->right, right->left) && foldableutil(left->left, right->right);
}


bool foldable(Node* root)
{
    if (root == NULL)
    {
        return true;
    }

    return foldableutil(root->left, root->right);
    
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(7);
    root->left->right = new Node(9);
    root->right = new Node(15);
    root->right->left = new Node(11);

    bool res = foldable(root);
    if(res)
    {
        cout << "foldable tree" << endl;
    }
    else
    {
        cout << "not foldable" << endl;
    }
}