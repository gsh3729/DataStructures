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
void verticalutil(Node* root, int level, map<int, vector<int>>& level_map)
{
    if (root == NULL)
    {
        return;
    }
    
    if (level_map.find(level) == level_map.end())
    {
        vector<int> temp;
        temp.push_back(root->data);
        level_map.insert(pair<int, vector<int>>(level, temp));
    }
    else
    {
        level_map[level].push_back(root->data);
    }
    verticalutil(root->left, level-1, level_map);
    verticalutil(root->right, level+1, level_map);
    return;
}



vector<int> verticalorder(Node* root)
{
    int level = 0;
    map<int, vector<int>> level_map;

    verticalutil(root, level, level_map);
    
    vector<int> res;
    for(auto i: level_map)
    {
        vector<int> p = i.second;
        for(auto j: p)
        {
            res.push_back(j);
        }
    }
    return res;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(1);
    root->left->left = new Node(2);
    root->right = new Node(1);
    root->right->right = new Node(3);

    vector<int> res = verticalorder(root);
    print_vector(res);
    return 0;
}
