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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int, multiset<int>> > adj;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int x=p.second.first;
            int y=p.second.second;
            int v= p.first->val;
            adj[x][y].insert(v);
            if(p.first->left)
            {
                q.push({p.first->left,{x-1,y+1} });
            }
            if(p.first->right)
            {
                q.push({p.first->right,{x+1,y+1} });
            }
        }
        vector<vector<int>> ans;
       for(auto it:adj)
       {
           vector<int> cur;
           for(auto t: it.second)
           {
               cur.insert(cur.end(), t.second.begin(), t.second.end());
           }
           ans.emplace_back(cur);
       }
        return ans;
    }
};
