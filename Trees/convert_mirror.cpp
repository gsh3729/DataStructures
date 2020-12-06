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

Node* mirror_tree(Node* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    
    Node* temp; 
    temp = mirror_tree(root->left);
    root->left = mirror_tree(root->right);
    root->right = temp;
    return root;
}

vector<int> inorder(Node* root)
{
    if (root == NULL)
    {
        return vector<int>();
    }

    vector<int> res;    
    if (root->left)
    {
        res = inorder(root->left);
    }

    res.push_back(root->data);
    
    vector<int> sub_res;
    if (root->right)
    {
        sub_res = inorder(root->right);
    }

    res.insert(res.end(), sub_res.begin(), sub_res.end());

    return res;
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
