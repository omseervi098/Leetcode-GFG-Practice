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
     void helper(TreeNode* root,vector<int> v,int targetSum,vector<vector<int>>&cpy){
         if(root==NULL)
             return ;
          if(root->left==NULL and root->right==NULL and root->val==targetSum)
         {
             v.push_back(root->val);
             cpy.push_back(v);
             return;
         }
         v.push_back(root->val);
         helper(root->left,v,targetSum-root->val,cpy);
         helper(root->right,v,targetSum-root->val,cpy);
        
     }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        vector<vector<int>>cpy;
         helper(root,v,targetSum,cpy);
        return cpy;
    }
};