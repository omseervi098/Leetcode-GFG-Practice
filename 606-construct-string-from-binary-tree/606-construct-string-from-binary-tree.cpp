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
    string helper(TreeNode* root){
        if(root==NULL){
            return "()";
        }
        string val=to_string(root->val);
        string left=helper(root->left);
        string right=helper(root->right);
        if(right=="()" and left=="()")
        {
            left="";
            right="";
        }
        else if(right=="()")
            right="";
        return '('+val+left+right+')';
    }
    string tree2str(TreeNode* root) {
        
       string s=helper(root);
        return s.substr(1,s.size()-2);
    }
};