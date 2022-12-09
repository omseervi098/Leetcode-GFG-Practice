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
    int ans=0;
    void helper(TreeNode* root,int mn,int mx){
        if(root==NULL) return;
        mn=min(mn,root->val);
        mx=max(mx,root->val);
        ans=max(ans,mx-mn);
        helper(root->left,mn,mx);
        helper(root->right,mn,mx);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        helper(root,INT_MAX,INT_MIN);
        return ans;
    }
};