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


vector<int> spiralorder(Node* root)
{
    stack<Node*> s1,s2;
    s1.push(root);
    vector<int> spiral;
    
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            Node* curr = s1.top();
            s1.pop();

            spiral.push_back(curr->data);
            
            if (curr->right)
            {
                s2.push(curr->right);
            }
            if (curr->left)
            {
                s2.push(curr->left);
            }
        }
        
        while (!s2.empty())
        {
            Node* curr = s2.top();
            s2.pop();

            spiral.push_back(curr->data);

            if (curr->left)
            {
                s1.push(curr->left);
            }
            if (curr->right)
            {
                s1.push(curr->right);
            }
        }
        
    }
    return spiral;
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

    vector<int> res = spiralorder(root);
    print_vector(res);
    return 0;
}
