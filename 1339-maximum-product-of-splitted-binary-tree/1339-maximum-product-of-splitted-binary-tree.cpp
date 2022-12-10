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
    long long mx=0;
    const int MOD=1e9+7;
    public:
    long long helper(TreeNode* root,long long totalsum=0){
        if(root==NULL) return 0;
        int sum=root->val+helper(root->left,totalsum)+helper(root->right,totalsum);
        mx=max(mx,sum*(totalsum-sum));
        return sum;
    }
    int maxProduct(TreeNode* root) {
        int res=0;
        long long sum=helper(root);
        helper(root,sum);
        return mx%MOD;
    }
};