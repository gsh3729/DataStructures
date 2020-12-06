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


void bottomutil(Node* root, int height, int level, map<int, pair<int, int>>& level_map)
{
    if (root==NULL)
    {
        return;
    }
    
    if (level_map.find(level) == level_map.end())
    {
        level_map[level] = make_pair(root->data, height);
    }
    else
    {
        pair<int, int> p = level_map[level];
        if (p.second <= height)
        {
            level_map[level].first = root->data;
            level_map[level].second = height;
        }
    }
    
    bottomutil(root->left, height+1, level-1, level_map); //try post order 
    bottomutil(root->right, height+1, level+1, level_map);
    
    return;
}


bool compare(pair<int, vector<int>>a, pair<int, vector<int>>b)
{
    return a.first > b.first;
}

vector<int> bottomview(Node* root)
{
    int level=0, height=0;
    map<int, pair<int, int>> level_map;
    bottomutil(root, height, level, level_map);
    
    sort(level_map.begin(), level_map.end(), compare);
    
    for (auto i: level_map)
    {
        cout << "Level: " << i.first << "\t Value: " << i.second.first << endl;
    }
    vector<int> bview;
    
    map<int, pair<int, int>>::iterator it;
    for ( it = level_map.begin(); it != level_map.end(); it++ )
    {
        bview.push_back(it->second.first);   
    }
    
    return bview;
}

vector <int> bottomview_q(Node *root)
{
    
    if (root == NULL) 
    {
        return vector<int>(); 
    }

    int hd = 0; 
    vector<int> bview;
    map<int, int> m; 
    queue<pair<Node *, int>> q; 

    q.push(make_pair(root, hd)); 
    while (!q.empty()) 
    { 
        pair<Node*, int> p = q.front();
        Node *temp = p.first; 
        hd = p.second;
        q.pop();  
  
        m[hd] = temp->data; 
        if (temp->left != NULL) 
        { 
            q.push(make_pair(temp->left, hd-1)); 
        } 
        if (temp->right != NULL) 
        { 
            q.push(make_pair(temp->right, hd+1)); 
        } 
    } 
  
    for (auto i = m.begin(); i != m.end(); ++i) 
    {
        bview.push_back(i->second);  
    }
    return bview;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(1);
    root->left->left = new Node(2);
    root->right = new Node(1);
    root->right->right = new Node(2);

    vector<int> res = bottomview(root);
    print_vector(res);
    return 0;
}
