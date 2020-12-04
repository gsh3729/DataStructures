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

int stoint(string s);
int eval_exp_tree(Node* root);

int stoint(string s)
{
    int res = 0;

    if (s[0] == '-')
    {
        for (int i = 1; i < s.length(); i++)
        {
            res = res*10 + s[i] - '0';
        }
        return  res*-1;    
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            res = res*10 + s[i] - '0';
        }   
    }
    
    
    return res;
}

int eval_exp_tree(Node* root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    if (!root->left && !root->right)
    {
        return stoint(root->data);
    }
    
    int left = eval_exp_tree(root->left);
    int right = eval_exp_tree(root->right);
    
    int res=0;
    if(root->data == "+")
    {
        res = left + right;
    }
    else if(root->data == "-")
    {
        res = left - right;
    }
    else if(root->data == "*")
    {
        res = left * right;
    }
    else if(root->data == "/")
    {
        res = left / right;
    }
    
    return res;`
}
`
int main()
{
   
    Node *root = new Node("+");  
    root->left = new Node("*");  
    root->left->left = new Node("5");  
    root->left->right = new Node("-4");  
    root->right = new Node("-");  
    root->right->left = new Node("100");  
    root->right->right = new Node("20");
    int res = eval_exp_tree(root);
    cout << "Result: " <<  res << endl;  
}