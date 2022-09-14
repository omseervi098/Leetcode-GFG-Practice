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
    unordered_map<int,int> m;
public:
    int helper(TreeNode* root){
        if(root==NULL)
            return 0;
        
        if(root->left==NULL and root->right==NULL){
            m[root->val]+=1;
            int cnt=0;
            for(int i=1;i<=9;i++){
                // if(cnt>1) return 0;
                if(m[i]&1){
                    cnt++;
                }
            }
            m[root->val]-=1;
            if(cnt<=1) return 1;
            return 0;
        }
        m[root->val]+=1;
        int ans= helper(root->left)+helper(root->right);
        m[root->val]-=1;
        return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return helper(root);
    }
};