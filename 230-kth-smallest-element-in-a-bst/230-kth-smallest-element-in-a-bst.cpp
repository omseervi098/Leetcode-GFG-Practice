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
    int i=0,ans;
    void helper(TreeNode* root,int k){
        if(root==nullptr)
            return;
        helper(root->left,k);
        cout<<root->val<<" "<<i<<endl;
        i++;
        if(i==k){
            ans=root->val;
            return;
        }
        helper(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;

         helper(root,k);
        return ans;
    }
};