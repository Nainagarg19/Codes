/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int check(TreeNode*root, int &maxi)
    {
        if(root==NULL)
            return 0;
        int lh=check(root->left,maxi);
        int rh=check(root->right,maxi);
        
        maxi=max(maxi, rh+lh);
        
        return 1+max(rh,lh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        int p=check(root,dia );
        return dia;
    }
};
