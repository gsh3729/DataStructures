#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    Node* left;
    Node* right;
}

vector<int> leftview(Node* root);
void print_vector(vector<int> temp);
Node* newNode(int val);

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* buildTree(string str)
{
    if(str.length()==0 || str[0] == 'N')
    {
        return NULL;
    }

    vector<string> ip;
    istringstream iss(str);
    for(string str; iss > str)
    {
        ip.push_back(str);
    }

    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i < ip.size())
    {
        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if(currVal != "N")
        {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if(i > i.size())
        {
            break;
        }
        currVal = ip[i];

        if(currVal != 'N')
        {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

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
        left.append(root->data);
        sub_result = leftview(root->left);
    }
    else if (root->right != NULL)
    {
        left.append(root->data);
        sub_result = leftview(root->right);
    }
    else if (root->left == NULL)
    {
        vector<int> result;
        result.push_back(root->data);
        return result;
    }
    
    left.insert(left.end(), sub_result.begin(), sub_result.end());
    return left;
    
}

bool BSTutil(Node* root, int mini, int maxi)
{

}

int max_node(Node* root)
{
    if (root == NULL)
    {
        return -1000;
    }
    else if (root->left == NULL and root->right == NULL)
    {
        return root->data;
    }
    
    left_max = max_node(root->left);
    right_max = max_node(root->right);
    
    return max(left_max, root->data, right_max);
}

int min_node(Node* root)
{
    if (root == NULL)
    {
        return 1000;
    }
    else if (root->left == NULL and root->right == NULL)
    {
        return root->data;
    }
    
    left_min = min_node(root->left);
    right_min = min_node(root->right);
    
    return min(left_min, root->data, right_min);
}


bool isBST(Node* root)
{
    if(isBST(root->left) and isBST(root->right))
    {
        if(max_node(root->right) < root->data and min_node(root->right) > root->data)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool isBSTutil(Node* root, int mini, int maxi)
{
    if (root == NULL)
    {
        return true;
    }

    if (node->data < min || node->data > max) 
    {
        return false;
    }

    return isBSTutil(root->left, mini, root->data-1) && isBSTutil(root->right, root->data+1, maxi);
}

bool isBST_eff(Node* root)
{
    return isBSTutil(root, INT_MIN, INT_MAX);
}

vector<int> bottomview(Node* root)
{
    if (root == NULL)
    {
        return vector<int>();
    }

    
}

void verticalutil(Node* root, int level, map<int, vector<int>> level_map)
{
    if (root == NULL)
    {
        return;
    }
    
    if (level_map.find(level) == level_map.end())
    {
        level_map.insert(pair<int, vector<int>>(0, root->data));
    }
    else
    {
        level_map[level].push_back(root->data);
        verticalutil(root->left, level-1, level_map);
        verticalutil(root->right, level+1, level_map);
    }
    return;
}

bool compare(pair<int, vector<int>>a, pair<int, vector<int>>b)
{
    return a.first > b.first;
}

vector<int> verticalorder(Node* root)
{
    int level = 0;
    map<int, vector<int>> level_map;

    verticalutil(root, level, level_map);
    
    sort(level_map.begin(), level_map.end(), compare); //is sorting req
    
    for(auto const& i: level_map)
    {
        for(auto j: i->second)
        {
            cout<<j<<" "; 
        }
        cout<<endl;
    }
}

vector<int> inorder_without_rec(Node* root)
{
    if (root == NULL)
    {
        return vector<int>();
    }
    
    stack<Node*> s;
    s.push(root);

    vector<int> inorder;
    while(!s.empty() )  //check the terminating condition curr != NULL || s.empty() == false
    {
        Node* curr = s.top();
        while (curr->left!=NULL)
        {
            curr = curr->left;
            s.push(curr->left);
        }

        inorder.push_back(curr->data);
        s.pop();
        s.push(curr->right);
    }
    return inorder;
}

vector<int> inorder_without_rec_stack(Node* root)
{
    if (root == NULL)
    {
        return vector<int>();
    }
    
    vector<int> inorder;
    while ()
    {
        
    }
    
    return inorder;
}

Node* build_tree_from_in_pre(vector<int> inorder, vector<int> preorder, int& pre_idx, int in_start, int in_end)
{
    if (in_start > in_end)
    {
        return NULL;
    }
    
    Node* root = newNode(preorder[pre_idx]);
    pre_idx++;

    if (in_start == in_end)
    {
        return root;
    }
    
    int i;
    for (i = in_start; i <= in_end; i++)  
    {  
        if (inorder[i] == root->data)
        {
            break;
        }    
    }
    
    root->left = build_tree_from_in_pre(inorder,preorder,pre_idx, in_start, i-1);
    root->right = build_tree_from_in_pre(inorder,preorder,pre_idx, i+1,in_end);

    return root;
}

vector<int> post_util(vector<int> inorder, vector<int> preorder, int in_start, int in_end)
{
    vector<int> post_order;



    return post_order;
}

vector<int> post_from_in_pre(vector<int> inorder, vector<int> preorder)
{
    Node* root = build_tree_from_in_pre(inorder, preorder, 0, inorder.size()-1);

    return post_util(inorder, preorder, 0, inorder.size() - 1);
    
}

int eval_exp_tree(Node* root)
{
    if (root == NULL)
    {
        return -2;
    }

    if (!root->left && !root->right)
    {
        return root->data;
    }
    

    left = eval_exp_tree(root->left);
    right = eval_exp_tree(root->right);
    
    int res;
    if(root->data == '+')
    {
        res = stoi(left)+stoi(right);
    }

    return res;
}

int main()
{
    string s = '1 2 3 4 5 6 7';
    Node* root = buildTree(s);
    vector<int> leftView = leftView(root);
    print_vector(leftview);   
}