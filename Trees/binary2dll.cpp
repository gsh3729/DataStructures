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

Node* binary2dll(Node* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    
    Node* left_head = binary2dll(root->left);
    if(left_head)
    {
        Node* temp = left_head;
        while(temp->right!=NULL)
        {
            temp = temp->right;
        }
        root->left = temp;
        temp->right = root;
    }
    else
    {
        left_head = root;
        root->left = NULL;
    }
    
    Node* right_head = binary2dll(root->right);
    if(right_head)
    {
        root->right = right_head;
        right_head->left = root;
    }
    else
    {
        root->right = NULL;
    }
    
    return left_head;
}

void print_dll(Node* root)
{
    while (root->right)
    {
        cout << root->data << " ";
        root = root->right;
    }
    cout << root->data << endl;

    while (root->left)
    {
        cout << root->data << " ";
        root = root->left;
    }
    cout << root->data << endl;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node* res = binary2dll(root);
    print_dll(res);
    return 0;
}
