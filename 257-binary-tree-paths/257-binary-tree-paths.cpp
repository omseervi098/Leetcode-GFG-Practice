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
    vector<string> v;
    public:
    void helper(TreeNode* root,string s){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr and root->right==nullptr){
            v.push_back(s+to_string(root->val));
            return;
        }
        helper(root->left,s+to_string(root->val)+"->");
        helper(root->right,s+to_string(root->val)+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root,"");
        return v;
    }
};