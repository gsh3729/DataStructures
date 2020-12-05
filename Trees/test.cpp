#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string data;
    Node* left;
    Node* right;
    Node(string val)
    {
        data = val;
        left = right = NULL;
    }
};

int eval_exp_tree(Node* root)
{
    cout << root->data << endl;
    return 0;
}

int main()
{
    Node *root = new Node("a");  
    // root->data = 10;
    // Node* root = new Node(10);  
    cout << root->data << endl;
    // root->left->left = newNode("5");  
    // root->left->right = newNode("-4");  
    // root->right = newNode("-");  
    // root->right->left = newNode("100");  
    // root->right->right = newNode("20");
    int res = eval_exp_tree(root);
    // cout << "Result: " <<  res << endl;  
    return 0;
}
