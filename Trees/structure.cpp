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

bool isstructure(Node* left, Node* right)
{
    if(left == NULL && right == NULL)
    {
        return true;
    }
    else if (left == NULL || right == NULL)
    {
        return false;
    }
    
    return isstructure(left->right, right->right) && isstructure(left->left, right->left);
}



int main()
{
    Node* root = new Node(10);
    root->left = new Node(7);
    root->left->right = new Node(9);
    root->right = new Node(15);
    root->right->right = new Node(11);

    bool res = isstructure(root->left, root->right);
    if(res)
    {
        cout << "structured tree" << endl;
    }
    else
    {
        cout << "not structured" << endl;
    }
}