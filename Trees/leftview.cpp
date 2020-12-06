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

vector<int> leftview(Node* root)
{
    if (root == NULL)
    {
        return vector<int>();
    }
    

    vector<int> left;
    vector<int> sub_result;
    if (root->left != NULL)
    {
        left.push_back(root->data);
        sub_result = leftview(root->left);
    }
    else if (root->right != NULL)
    {
        left.push_back(root->data);
        sub_result = leftview(root->right);
    }
    else if (root->left == NULL && root->right == NULL)
    {
        sub_result.push_back(root->data);
        return sub_result;
    }
    
    left.insert(left.end(), sub_result.begin(), sub_result.end());

    return left;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(1);
    root->left->left = new Node(2);
    root->right = new Node(1);
    root->right->right = new Node(2);

    vector<int> res = leftview(root);
    print_vector(res);
    return 0;
}
