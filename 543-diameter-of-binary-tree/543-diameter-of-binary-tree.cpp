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
    pair<int,int> helper(TreeNode* root){
        
        if(root==NULL)
            return {0,0};
        pair<int,int> ans;
        pair<int,int> op2=helper(root->left);
        pair<int,int> op3=helper(root->right);
        ans.first=1+max(op2.first,op3.first);
        ans.second=max(op2.second,max(op3.second,(op2.first+op3.first)));
        return ans;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        return helper(root).second;
    }
};