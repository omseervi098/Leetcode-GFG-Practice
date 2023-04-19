class Solution {
public:
    int helper(TreeNode* root,bool left,int d){
        if(!root) return d;
        if(left) return max(helper(root->right,false,d+1),helper(root->left,true,0));
        return max(helper(root->left,true,d+1),helper(root->right,false,0));
    }
    int longestZigZag(TreeNode* root) {
        return max(helper(root->left,true,0),helper(root->right,false,0));
    }
};