/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
};*/

class Solution {
public:
    bool is_leaf(Node* root)
    {
        if(!root->left && !root->right)
            return true;
        return false;
    }
    void leftnodes(Node* root, vector<int>&res)
    {
        Node *cur=root->left;
        while(cur)
        {
            if(!is_leaf(cur)) res.emplace_back(cur->data);
            if(cur->left) cur=cur->left;
            else
                cur=cur->right;
        }
        
    }
    
    void leafnodes(Node* root, vector<int> &res)
    {
        if(is_leaf(root))
        {
            res.emplace_back(root->data);
            return;
        }
        if(root->left) leafnodes(root->left, res);
        if(root->right) leafnodes(root->right, res);
    }
    
    void rightnodes(Node* root, vector<int> &res)
    {
        Node *cur=root->right;
        vector<int> temp;
        while(cur)
        {
            if(!is_leaf(cur)) temp.emplace_back(cur->data);
            if(cur->right) cur=cur->right;
            else
                cur=cur->left;
        }
        for(int i=temp.size()-1;i>=0;--i)
        {
            res.emplace_back(temp[i]);
        }
    }
    
    vector <int> printBoundary(Node *root)
    {
        vector<int> res;
        if(root==NULL)
            return res;
        if(!is_leaf(root))
            res.emplace_back(root->data);
        leftnodes(root,res);
        leafnodes(root,res);
        rightnodes(root,res);
        return res;
    }
};
