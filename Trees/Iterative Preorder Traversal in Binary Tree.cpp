class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* x=st.top();
            st.pop();
            ans.push_back(x->val);
            if(x->right)
                st.push(x->right);
            if(x->left)
                st.push(x->left);
        }
        return ans;
    }
};
