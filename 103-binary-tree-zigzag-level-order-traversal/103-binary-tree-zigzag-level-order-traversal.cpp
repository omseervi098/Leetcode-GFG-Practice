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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        bool right=true;
        while(!q.empty())
        {
            TreeNode* x=q.front();
            q.pop();
            if(x==NULL)
            {
                if(!right)
                    reverse(v.begin(),v.end());
                if(q.empty()){
                    ans.push_back(v);
                    break;
                }
                q.push(NULL);
                right=!right;
                ans.push_back(v);
                v.erase(v.begin(),v.end());
                continue; 
            }
            v.push_back(x->val);
            if(x->left)
                q.push(x->left);
            if(x->right)
                q.push(x->right);
            
        }
        return ans;
    }
};