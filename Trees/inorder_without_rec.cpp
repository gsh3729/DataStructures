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

vector<int> inorder_with_stack(Node* root)
{
    if (root == NULL)
    {
        return vector<int>();
    }
    
    stack<Node*> s;
    Node* curr = root; 
    vector<int> inorder;

    while(curr || !s.empty()) //stack empty when root and its left are done
    {
        while (curr) 
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        inorder.push_back(curr->data);
        
        curr = curr->right;
    }

    return inorder;
}


int main()
{
    Node* root = new Node(10);
    root->left = new Node(1);
    root->left->left = new Node(2);
    root->right = new Node(1);
    root->right->right = new Node(2);

    vector<int> res = inorder_with_stack(root);
    print_vector(res);
    return 0;
}