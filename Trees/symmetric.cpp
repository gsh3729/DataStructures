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

bool isMirror(Node* r1, Node* r2)
{
    if(r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if(r1==NULL || r2==NULL)
    {
        return false;
    }
    if(r1->data == r2->data)
    {
        return isMirror(r1->left, r2->right)&&isMirror(r1->right, r2->left);
    }
    else
    {
        return false;
    }
}

bool isSymmetric(struct Node* root)
{
    if(root == NULL)
    {
        return true;
    }
    
    return isMirror(root->left, root->right);
	// Code here
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(1);
    root->left->left = new Node(2);
    root->right = new Node(1);
    root->right->right = new Node(2);

    if (isSymmetric(root))
    {
        cout << "symmmetric tree" << endl;
    }
    else
    {
        cout << "not symmetric tree" << endl;
    }
    

}