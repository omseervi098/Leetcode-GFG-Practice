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
    int helper(TreeNode* root,int temp){
        if(root==NULL)
        {
            return 0;
        }
        if(root->left==nullptr and root->right==nullptr){
            return temp*10+root->val;
        }
        int left=helper(root->left,temp*10+root->val);
        int right=helper(root->right,temp*10+root->val);
        cout<<left<<" "<<right<<endl;
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
};