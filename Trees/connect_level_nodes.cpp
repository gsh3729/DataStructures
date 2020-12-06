#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
    Node(int val)
    {
        data = val;
        left = right = nextRight = NULL;
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

void print_connect(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    Node* nextRec=NULL;
    if (root->left)
    {
        nextRec = root->left;
    }
    else if (root->right)
    {
        nextRec = root->right;
    }
    
    while(root)
    {
        cout << root->data << " ";
        root = root->nextRight;
    }
    cout<<endl;
    return print_connect(nextRec);
}

void connect(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    Node* prev = NULL;
    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();

        if(curr)
        {
            curr->nextRight = q.front();
            prev = curr;
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        else
        {
            q.push(NULL);
            prev->nextRight = NULL; 
        }
    }
    return;
}
void connect_best(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    
    // p->nextRight = NULL;
    // int level = 0;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));
    
    while(!q.empty())
    {
        pair<Node*,int> p  = q.front();
        Node* curr = p.first;
        int level = p.second;
        
        q.pop();

        pair<Node*,int> x  = q.front();
        Node* front = x.first;
        int front_level = x.second;  
        
        if(level == front_level)
        {
            curr->nextRight = front;
        }
        else
        {
            curr->nextRight = NULL;
        }

        if(curr->left)
        {
            q.push(make_pair(curr->left, level+1));
        }
        
        if(curr->right)
        {
            q.push(make_pair(curr->right, level+1));
        }
    }
    return;
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

    connect_best(root);
    print_connect(root);
    return 0;
}
