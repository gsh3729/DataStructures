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

int height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    
    return 1 + max(height(root->left), height(root->right));
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(1);
    root->left->left = new Node(2);
    root->right = new Node(1);
    root->right->right = new Node(2);

    int h = height(root);
    cout << "Height: " << h << endl;
    return 0;
}