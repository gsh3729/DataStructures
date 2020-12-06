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

void print_vector(vector<int> temp)
{
    for(int x : temp)
    {
        cout << x << " ";
    }
    cout << endl;
    return;
}

bool is_bstutil(Node* root, int mini, int maxi)
{
    if (root == NULL)
    {
        return true;
    }
    
    if (root->data < mini || root->data > maxi )
    {
        return false;
    }

    return is_bstutil(root->left, mini, root->data-1) && is_bstutil(root->right, root->data+1, maxi);
    
}
bool is_bst(Node* root)
{
    return is_bstutil(root, INT_MIN, INT_MAX);
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(1);
    root->left->left = new Node(2);
    root->right = new Node(1);
    root->right->right = new Node(3);

    vector<int> res = inorder(root);
    print_vector(res);
    root = mirror_tree(root);
    res = inorder(root);
    print_vector(res);
    return 0;
}
