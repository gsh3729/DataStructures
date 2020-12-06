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

int lca_bst(Node* root, int n1, int n2)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    
    if (root->data > n1 && root->data > n2)
    {
        return lca_bst(root->left, n1, n2);
    }

    if (root->data < n1 && root->data < n2)
    {
        return lca_bst(root->right, n1, n2);
    }

    if (root->data < n1 && root->data > n2)
    {
        return root->data;
    }
    
}


int main()
{
    Node* root = new Node(10);
    root->left = new Node(1);
    root->left->left = new Node(2);
    root->right = new Node(1);
    root->right->right = new Node(3);

    int res = lca_bst(root, 2, 1);
    print_vector(res);
    return 0;
}
